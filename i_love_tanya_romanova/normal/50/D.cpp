#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
#define M_PI        3.14159265358979323846
#define M_E       2.7182818284590452353602874713527
using namespace std;
long i,n,k,eps,e;double x[10000],t,q,m,y[10000],l,r,s,ch[10000],d[10000],ch1[10000];
int main(){
//freopen("length.in","r",stdin);freopen("length.out","w",stdout);
cin>>n>>k>>eps;cin>>x[0]>>y[0];
for (i=1;i<=n;i++){cin>>x[i]>>y[i];}
for (i=1;i<=n;i++){d[i]=(x[i]-x[0])*(x[i]-x[0]);
d[i]+=(y[i]-y[0])*(y[i]-y[0]);}
l=0.0000001;r=5000;
while (r-l>0.000000001)
{for (i=1;i<=n;i++)ch[i]=0;
ch[0]=1;
m=l+r;m/=2;
for (i=1;i<=n;i++)if (d[i]<=m*m)
{for (e=n;e>=1;e--)ch[e]=ch[e-1];ch[0]=0;}
else
{t=1-(d[i]/m/m);
q=pow(M_E,t);ch1[0]=ch[0]*(1-q);
for (e=1;e<=n;e++){ch1[e]=ch[e-1]*q+ch[e]*(1-q);}
for (e=0;e<=n;e++)ch[e]=ch1[e];
}
s=0;
for (e=k;e<=n;e++)s+=ch[e];
if (s>1-eps/1000.0)r=m; else l=m;//cout<<s<<" "<<m<<endl;
}cout.precision(10);cout<<fixed<<l<<endl;
cin.get();cin.get();cin.get();
return 0;}