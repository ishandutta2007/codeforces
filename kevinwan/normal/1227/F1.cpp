#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
const ll mod=998244353;
ll dp[mn][2];
ll num[mn];
int a[mn];
ll fact[mn];
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll ch(ll a,ll b){
    return fact[a]*po(fact[b]*fact[a-b]%mod)%mod;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int m=0;
    for(int i=0;i<n-1;i++)m+=(a[i]!=a[i+1]);
    m+=(a[0]!=a[n-1]);
    ll ans=0;
    fact[0]=1;
    for(int i=1;i<=m;i++)fact[i]=fact[i-1]*i%mod;
    for(int i=0;i<m;i++){
        if((m-i)&1)ans+=po(2,m-i-1)*ch(m,i)%mod*po(k-2,i);
        else ans+=(po(2,m-i-1)-ch(m-i,(m-i)/2)*po(2))%mod*fact[m]%mod*po(fact[i]*fact[m-i]%mod)%mod*po(k-2,i);
        ans%=mod;
    }
    ans=ans*po(k,n-m)%mod;
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}