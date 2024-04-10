#include <math.h>
#include <string>
#include <iostream>
#include<algorithm>
//#include <stdio.h>
//#include <fstream>
#define M_PI		3.14159265358979323846
using namespace std;
double a,b;
long tests;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>tests;cout.precision(10);
for (;tests;--tests)
{cin>>a>>b;if (a==0&&b==0)a=1;
if (b==0&&a!=0)a=1;else 
if (a==0&&b!=0)a=0.5;else  
if (a!=0&&b!=0){
b*=4;if (a<=b)a=(b+a/2)/b/2;
else a=(a-b)/a+(b+b/2)*b/a/2/b;}
cout<<fixed<<a<<endl;}

cin.get();cin.get();
return 0;}