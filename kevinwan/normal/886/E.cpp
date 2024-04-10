#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll fact[mn],dp[mn],s[mn];
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll ch(ll a,ll b){
    if(b<0||a-b<0)return 0;
    return fact[a]*po(fact[b]*fact[a-b]%mod)%mod;
} 
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,k;
    cin>>n>>k;
    fact[0]=1;
    for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;
    for(int i=0;i<=k;i++)dp[i]=fact[n-1],s[i]=dp[i]+(i?s[i-1]:0),s[i]%=mod;
    for(int i=k+1;i<n;i++){
        dp[i]=(s[i-1]-s[i-k-1])*po(i)%mod;
        s[i]=(s[i-1]+dp[i])%mod;
    }
    for(int i=0;i<=n;i++)cerr<<dp[i]<<' ';
    ll ans=fact[n];
    for(int i=0;i<n;i++){
        ans-=dp[i];
        ans%=mod;
    }
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}