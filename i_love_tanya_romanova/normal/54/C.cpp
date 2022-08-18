#include <math.h>
#include <iostream>
#include <algorithm>
#define M_PI        3.14159265358979323846
using namespace std;
long long n,i,a[10000],b[10000],base[100],s,j,ts;
double p[2000],pq,pp[1200][1200],ans;
int main()
{//freopen("C:/input.txt","r",stdin);freopen("C:/output.txt","w",stdout);
cin>>n;
for (i=1;i<=n;i++)cin>>a[i]>>b[i];
cin>>pq;pq=pq*0.01;
base[1]=1;
for (i=2;i<=19;i++)base[i]=base[i-1]*10;
//cout<<base[19]<<endl;
for (i=1;i<=n;i++)
{s=b[i]-a[i]+1;ts=0;
    for(j=1;j<=19;j++)
    {if (a[i]>=base[j]&&b[i]<base[j]*2)ts+=s;
     if (a[i]>=base[j]&&a[i]<base[j]*2&&b[i]>=base[j]*2)ts+=base[j]*2-a[i];
     if (a[i]<base[j]&&b[i]>=base[j]&&b[i]<base[j]*2)ts+=b[i]-base[j]+1;
     if (a[i]<base[j]&&b[i]>=base[j]*2)ts+=base[j];
    }
p[i]=double(ts)/s;//cout<<ts<<endl;
    }
pp[0][0]=1000000000;
for (i=0;i<=n;i++)for (j=0;j<=i;j++)
{pp[i+1][j]+=pp[i][j]*(1.0-p[i+1]);
pp[i+1][j+1]+=pp[i][j]*p[i+1];}

for (i=0;i<=n;i++)
if (double(i)/n>pq-0.00000000001)ans+=pp[n][i];
cout.precision(13);
ans/=1000000000;
cout<<fixed<<ans<<endl;
//for (i=1;i<=n;i++)cout<<p[i]<<endl;
  cin.get();cin.get();cin.get();
return 0;}