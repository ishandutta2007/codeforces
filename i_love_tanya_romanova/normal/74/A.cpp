#include <iostream>
#include <math.h>
#include <vector> 
#include <string> 
#include <stdio.h>
#include <algorithm>
#define M_PI 3.14159265358979323846
using namespace std;
long n;
long i,j,answ,ans,mins[10000],a[10000],b[10000],c[10000],d[10000],e[10000],plas[100000];
string st[10000];
int main()
{
//  freopen("input.txt","r",stdin);
 // freopen("output.txt","w",stdout);
cin>>n;ans=-1000000;
for (i=1;i<=n;i++){cin>>st[i]>>plas[i]>>mins[i]>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];}
for (i=1;i<=n;i++){plas[i]*=100;mins[i]*=-50;}
for (i=1;i<=n;i++){if (plas[i]+mins[i]+a[i]+b[i]+c[i]+d[i]+e[i]>ans)
{ans=(plas[i]+mins[i]+a[i]+b[i]+c[i]+d[i]+e[i]);answ=i;};}
cout<<st[answ]<<endl;
//for (i=1;i<=n;i++)cout<<plas[i]+mins[i]+a[i]+b[i]+c[i]+d[i]+e[i]<<endl;
cin.get();cin.get();cin.get();
return 0;}