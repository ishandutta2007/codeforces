#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>      
#include <string>
using namespace std;
long long  n,m,a[10],s;

int main(){
cin>>n;
for (int i=0; i<n; i++)
{
cin>>m;
a[m]++;
}
s+=a[4];
a[4]=0;

s+=a[3];
a[1]-=a[3];

s+=a[2]/2; 
if (a[2]%2==1) {a[2]=1;s+=1; a[1]-=2;}

if (a[1]>0) {s+=a[1]/4; a[1]=a[1]%4;}
if (a[1]>0) {s+=1; }
cout<<s;





return 0;
}