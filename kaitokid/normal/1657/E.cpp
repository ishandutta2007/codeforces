#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll n,k;
ll dp[255][255];
ll pw[266][277],c[259][259];
ll go(ll x,ll u)
{
    if(x==k+1 && u==n)return 1;
    if(x==k+1)return 0;
    if(dp[x][u]!=-1)return dp[x][u];
    ll ans=go(x+1,u);
    ll r=1;
    for(int i=1;i+u<=n;i++)
    {
        r*=pw[k-x+1][u+i-1];
        r%=mod;
        ll q=go(x+1,i+u)*r;

       q%=mod;
        q*=c[n-u][i];
        q%=mod;
       ans+=q;
       ans%=mod;
    }
    return dp[x][u]=ans;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   for(int i=1;i<=255;i++)
   {
       pw[i][0]=1;
       for(int j=1;j<=255;j++)pw[i][j]=(pw[i][j-1]*i)%mod;
   }
 c[1][0]=c[1][1]=1;
 for(int i=2;i<=255;i++)
 {
     c[i][0]=1;
     for(int j=1;j<=255;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
 }
 cin>>n>>k;
n--;
 memset(dp,-1,sizeof dp);
 cout<<go(1,0);

}