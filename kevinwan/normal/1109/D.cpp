#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=1e6+10;
const ll mod=1e9+7;
ll fact[mn];
ll po(ll a,ll b=mod-2){
    if(b<0)b+=mod-1;
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll ch(ll n,ll k){
    if(k<0||k>n)return 0;
    return fact[n]*po(fact[k]*fact[n-k]%mod)%mod;
}
int main(){
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    fact[0]=1;
    for(int i=1;i<mn;i++)fact[i]=fact[i-1]*i%mod;
    ll ans=0;
    for(int i=1;i<=n-1;i++){
        ll num=ch(m-1,i-1);
        num*=ch(n-2,i-1)*fact[i-1]%mod,num%=mod;
        num*=po(m,n-i-1),num%=mod;
        num*=(i+1)*po(n,n-1-i-1)%mod,num%=mod;
        ans+=num,ans%=mod;
    }
    printf("%lld",ans);
}