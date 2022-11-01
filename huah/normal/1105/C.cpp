#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int n,l,r;
ll dp[200005][3];
int main()
{
    scanf("%d%d%d",&n,&l,&r);
    int z=r/3-(l-1)/3,o,t,oo,tt;
    o=(l-1)/3;
    if((l-1)%3==1||(l-1)%3==2) o++;
    t=(l-1)/3;
    if((l-1)%3==2) t++;
    oo=r/3;
    if(r%3==1||r%3==2) oo++;
    tt=r/3;
    if(r%3==2) tt++;
    o=oo-o;
    t=tt-t;
    dp[1][0]=z;
    dp[1][1]=o;
    dp[1][2]=t;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][0]*z+dp[i-1][1]*t+dp[i-1][2]*o)%mod;
        dp[i][1]=(dp[i-1][0]*o+dp[i-1][1]*z+dp[i-1][2]*t)%mod;
        dp[i][2]=(dp[i-1][0]*t+dp[i-1][1]*o+dp[i-1][2]*z)%mod;
    }
    printf("%lld\n",dp[n][0]);
}