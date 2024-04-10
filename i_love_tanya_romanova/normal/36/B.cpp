#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
long a,n,i,j;char ar[1000][1000]; long t,fl,p,l,e,x,y,b;

int main(){
freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
  cin>>a>>n;
  for (i=0;i<a;i++)
  {for (j=0;j<a;j++){
  cin>>ar[i][j];     
       ;};}
l=a;for (i=1;i<n;i++)l*=a;
for (i=0;i<l;i++)
{for (j=0;j<l;j++)
{fl=0;
t=1;for (e=1;e<=n;e++){t*=a;}
for (;t>1;t/=a)
{x=i;y=j;
p=t/a;
x=i%t;y%=t;
x/=p;y/=p;
if (ar[x][y]=='*')fl++;
}
if (fl==0){cout<<".";} else {cout<<"*";}
;}cout<<endl;}
return 0;}