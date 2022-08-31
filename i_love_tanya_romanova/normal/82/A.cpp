#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#define M_PI        3.14159265358979323846
using namespace std;
long long n,q,s;
long long ar[10000];
int main(){   
    ar[1]=1;
    ar[2]=1;
    ar[3]=1;
    ar[4]=1;
    ar[5]=1;
    s=0;
   q=0;
   cin>>n;
   while (s<n){q++;if (q==6)q=1;s+=ar[q];ar[q]*=2;}
   
   n=q;
       if (n==1)cout<<"Sheldon"<<endl;
     if (n==2)cout<<"Leonard"<<endl;
     if (n==3)cout<<"Penny"<<endl;
     if (n==4)cout<<"Rajesh"<<endl;
     if (n==5)cout<<"Howard"<<endl;
cin.get();cin.get();
return 0;}