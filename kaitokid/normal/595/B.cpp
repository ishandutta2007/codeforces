#include <bits/stdc++.h>
using namespace std ;
long long  a[100006];
long long res[100007];
long long  ans=1;
long long p(int a,int b)
{int g=1;
for(int i=0;i<b;i++){g*=a;}
return g;
}
int main ()
{long long n,x,k;
cin>>n>>k;
long long u= p(10,k);
for (int i=0;i<n/k;i++)
{ cin>>a[i];

res[i] =(u-1)/a[i]+1;
}
for (int i=0;i<n/k;i++)
{cin>>x;
if (x==0){res[i]--;res[i]-=(u/10-1)/a[i];}else
{res[i]-=((x+1)*(u/10)-1)/a[i]-(x*(u/10)-1)/a[i];}
ans=(ans*res[i])%1000000007;}
cout<<ans;
//for(int i=0;i<n/k;i++)cout<<" "<<res[i];
return 0;
}