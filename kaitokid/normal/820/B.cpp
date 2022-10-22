#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
int n,a;
cin>>n>>a;
//cout<<"1 2 ";
double b = 180*(n-2)/(n+0.0);
double y =b/(n-2);
double v= a/y;
int v1=floor(v);
int v2= ceil (v);
if(v2==0){v2++;}

if(abs(a-(y*v1))<abs(a-(y*v2))&&v1>0){cout<<min(v1+2,n)<<" 1 2";}
else{cout<<min(v2+2,n)<<" 1 2";}
    return 0;
}