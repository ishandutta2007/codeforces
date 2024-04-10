#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=2e5+10;
ll mod=1e9+7;
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll fact[mn];
ll ch(ll a,ll b){
    return fact[a]*po(fact[b]*fact[a-b]%mod)%mod;
}
int main(){
    int n,m,g;
    scanf("%d%d%d",&n,&m,&g);
    fact[0]=1;
    for(int i=1;i<mn;i++)fact[i]=fact[i-1]*i%mod;
    ll ans=0;
    if(m==0){
        ans=(n&1);
    }
    else if(m==1){
        for(int i=0;i<n;i+=2)ans++;
        ans+=(n&1);
    }
    else{
        for(int i=0;i<=n;i+=2)ans+=ch(n-i+m-1,m-1),ans%=mod;
    }
    if(g==1)ans=(ch(n+m,n)-ans)%mod;
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}