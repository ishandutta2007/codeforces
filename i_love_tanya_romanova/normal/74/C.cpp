#include <iostream>
#include <math.h>
#include <vector> 
#include <string> 
#include <stdio.h>
#include <algorithm>
#define M_PI 3.14159265358979323846
using namespace std;
long n,m;
int main()
{
//  freopen("input.txt","r",stdin);
 // freopen("output.txt","w",stdout);
cin>>n>>m;
--n;--m;
while (n&&m)n>m?n%=m:m%=n;
cout<<n+m+1<<endl;
cin.get();cin.get();cin.get();
return 0;}