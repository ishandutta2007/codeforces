#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int x,n,k,xx,yy;
int main(){
cin>>n>>k;
yy=1;

x = n/3 + 1;
if (k >= x) xx = n - x - ( k - x ); else 
xx = k*2;
if (k == 0 || n == k) yy = 0; 
cout<<yy<<" "<<xx;
return 0;
}