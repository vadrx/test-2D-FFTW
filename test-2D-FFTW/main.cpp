//
//  main.cpp
//  test-2D-FFTW
//
//  Created by Anton Volkov on 05/04/2018.
//  Copyright © 2018 Anton Volkov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fftw3.h>
#include "HighResTimer.hpp"

HighResTimer timer("Tick counter");

int main() {
    
//     Indices
    int i = 0,j = 0;
    
//     Signal 1D signal array and FFT 1D output array
    fftw_complex *Array1DIn;
    fftw_complex *Array1DOut;
    
//     Number of sampling points
    int sizex = 100;
    int sizey = 200;
    
//     Total size of FFT
    int N = sizex*sizey;
    
//     Cumulative time
//    double hx = 0;
//    double hy = 0;
    
//     Signal frequency
//    double frequency_signalx = 10;
//    double frequency_signaly = 20;
    
//     Sampling frequency
//    double frequency_samplingx = sizex*frequency_signalx;
//    double frequency_samplingy = sizey*frequency_signaly;
    
//     Step = T_sampling
//    double stepx = 1.0/frequency_samplingx;
//    double stepy = 1.0/frequency_samplingy;
    
//     File for saving outputs
//    FILE *FFT_2D;
    
//     FFTW plan signal
    fftw_plan fft_signal;
    
//     Allocation of Arrays
    Array1DIn = (fftw_complex*) fftw_malloc(N*sizeof(fftw_complex));
    Array1DOut = (fftw_complex*) fftw_malloc(N*sizeof(fftw_complex));
    
//     Initialization of 2D (real + imaginary) ArrayInput
//        FFT_2D = fopen("FFT_2D_Input.dat","w");
//        for(j=0; j<sizey; j++)
//        {
//            for(i=0; i<sizex; i++)
//            {
//                Array1DIn[j*sizex+i][0] =  cos(2*M_PI*frequency_signalx*hx)*cos(2*M_PI*frequency_signaly*hy);
//                Array1DIn[j*sizex+i][1] = 0.0f;
//                fprintf(FFT_2D,"%f %f %e\n", i/(frequency_signalx*sizex), j/(frequency_signaly*sizey),
//                        Array1DIn[j*sizex+i][0]);
//                hx = hx + stepx;
//            }
//            hx = 0.0f;
//            hy = hy + stepy;
//        }
//        fclose(FFT_2D);
    
    for (i = 0; i < 2000 ; i++) {
        for (j = 0; j < 2000; j++)
        {
            Array1DIn[i][j] = 5.5f;
        }
    }
    
    
//     FFTW plan Forward 2D
    fft_signal = fftw_plan_dft_2d(sizey, sizex, Array1DIn, Array1DOut, FFTW_FORWARD, FFTW_ESTIMATE);
    
//     Perform Forward FFT
    timer.start();
    
    fftw_execute(fft_signal);
    
    printf("FFT passed!\n");
    timer.stop();
    
    printf("FFTW time:\n");
    timer.printMilliseconds();
    timer.reset();
    
////    Save Output Array
//    FFT_2D = fopen("FFT_2D_Forward.dat","w");
//    for(j=0; j<sizey; j++){
//        for(i=0; i<sizex; i++){
//            fprintf(FFT_2D,"%f %f %e\n", i*frequency_samplingx/sizex,
//                    j*frequency_samplingy/sizey,
//                    Array1DOut[j*sizex+i][0]);
//
//        }
//    }
////    Destroy plan signal
//    fftw_destroy_plan(fft_signal);
    
//    Normalization
    for(j=0; j<sizey; j++){
        for(i=0; i<sizex; i++){
            Array1DIn[j*sizex+i][0] = Array1DIn[j*sizex+i][0]/(sizex*sizey);
        }
    }
    
////    Save Output Array
//    FFT_2D = fopen("FFT_2D_Backward.dat","w");
//    for(j=0; j<sizey; j++) {
//        for(i=0; i<sizex; i++) {
//            fprintf(FFT_2D,"%f %f %e\n", i/(sizex*frequency_signalx),
//                    j/(sizey*frequency_signaly),
//                    Array1DIn[j*sizex+i][0]);
//        }
//    }
//    fclose(FFT_2D);
    
    return 0;
}

