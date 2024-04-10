#include <iostream>
#include <math.h>
#define For(i,i0,i1) for(int i=i0;i<i1;i++)

using namespace std;

int main()
{
    int n,x[10],y[10],j,k,i;
    string a;
    cin>>n;
    cin>>a;
    For(i,0,10){
        x[i]=0;
    }
    For(i,0,n){
        if(a[i]=='2') x[2]++;
        if(a[i]=='3') x[3]++;
        if(a[i]=='4') x[4]++;
        if(a[i]=='5') x[5]++;
        if(a[i]=='6') x[6]++;
        if(a[i]=='7') x[7]++;
        if(a[i]=='8') x[8]++;
        if(a[i]=='9') x[9]++;
    }
    y[0]=0;
    y[1]=0;
    y[2]=x[2]+x[3]+3*(x[4]+x[5])+4*(x[6]+x[7])+7*(x[8]+x[9]);
    y[3]=x[3]+x[4]+x[5]+2*(x[6]+x[7]+x[8])+4*x[9];
    y[4]=0;
    y[5]=x[5]+x[6]+x[7]+x[8]+x[9];
    y[6]=0;
    y[7]=x[7]+x[8]+x[9];
    y[8]=0;
    y[9]=0;
    while(y[7]>0){
        y[7]-=1;
        y[5]-=1;
        y[3]-=2;
        y[2]-=4;
        cout<<7;
    }
    while(y[5]>0){
        y[5]-=1;
        y[3]-=1;
        y[2]-=3;
        cout<<5;
    }
    while(y[3]>0){
        y[3]-=1;
        y[2]-=1;
        cout<<3;
    }
    while(y[2]>0){
        y[2]-=1;
        cout<<2;
    }
    /*
    x[0]=0;
    x[1]=0;
    x[2]+=2*x[4]+3*x[8]+x[9];
    x[3]+=x[4]+x[6]+2*x[9];
    x[5]+=x[6];
    x[7]+=x[8]+x[9];
    x[4]=0;
    x[6]=0;
    x[8]=0;
    x[9]=0;*//*
    for(int i=9;i>=2;i--){
        For(j,0,x[i]){
            cout<<i;
        }
    }*/
    return 0;
}