#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
const ll mod=998244353;
inline ll inv(ll x){
    ll ans=1;
    for(ll i=mod-2;i;i>>=1,x=x*x%mod)if(i&1)ans=ans*x%mod;
    return ans;
}
int lik[mn];
ll w[mn];
ll dp[3001][3001],ep[3001][3001],a,b;
ll in[6001];
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",lik+i);
    for(i=0;i<n;i++){
        scanf("%lld",w+i);
        if(lik[i])a+=w[i];
        else b+=w[i];
    }
    dp[0][0]=ep[0][0]=1;
    for(i=0;i<=6000;i++)in[i]=inv((a+b+i-3000)%mod);
    for(int s=0;s<m;s++){
        for(j=0;j<=s;j++){
            i=s-j;
            dp[i][j]%=mod;
            dp[i+1][j]+=dp[i][j]*((a+i+1)*in[3000+i-j]%mod)%mod;
            dp[i][j+1]+=dp[i][j]*((b-j)*in[3000+i-j]%mod)%mod;
            ep[i][j]%=mod;
            ep[i+1][j]+=ep[i][j]*((a+i)*in[3000+i-j]%mod)%mod;
            ep[i][j+1]+=ep[i][j]*((b-j-1)*in[3000+i-j]%mod)%mod;
        }
    }
    ll ans=0,bns=0;
    for(i=0;i<=m;i++)ans+=dp[i][m-i],ans%=mod,bns+=ep[i][m-i],bns%=mod;
    for(i=0;i<n;i++){
        if(lik[i])printf("%lld\n",ans*w[i]%mod);
        else printf("%lld\n",bns*w[i]%mod);
    }
}