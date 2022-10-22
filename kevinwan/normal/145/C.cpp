#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e9+7;
bool gud(ll x){
    while(x){
        if(x%10!=4&&x%10!=7)return 0;
        x/=10;
    }
    return 1;
}
ll cur=1e9+1;
bool g[mn];
map<ll,ll>m;
ll num[mn];
ll dp[mn];
ll fact[mn],ifact[mn];
ll inv(ll x){
    ll ans=1;
    for(ll b=mod-2;b;b>>=1,x=x*x%mod)if(b&1)ans=ans*x%mod;
    return ans;
}
ll ch(ll a,ll b){
    if(b>a||b<0)return 0;
    return fact[a]*ifact[b]%mod*ifact[a-b]%mod;
}
int main(){
    int n,k,x,i,j;
    scanf("%d%d",&n,&k);
    fact[0]=ifact[0]=1;
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(gud(x))m[x]++;
        else m[cur++]++;
        fact[i]=fact[i-1]*i%mod;
        ifact[i]=inv(fact[i]);
    }
    for(auto p:m){
        num[p.second]++;
    }
    dp[0]=1;
    for(i=2;i<=n;i++){
        while(num[i]--){
            for(j=n;j>=0;j--){
                if(j)dp[j]=(dp[j]+dp[j-1]*i)%mod;
            }
        }
    }
    ll ans=0;
    for(i=0;i<=k;i++){
        ans+=dp[i]*ch(num[1],k-i);
        ans%=mod;
    }
    printf("%lld",ans);
}