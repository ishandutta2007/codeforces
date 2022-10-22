#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e6+10;
const ll mod=998244353;
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
    ll n;
    scanf("%lld",&n);
    ll ans=0;
    fact[0]=1;
    for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;
    for(int i=1;i<=n;i++){
        ans+=2*ch(n,i)%mod*po(-3,i)%mod*po(3,(n-i)*n%(mod-1))%mod,ans%=mod;
    }
    for(int i=1;i<=n;i++){
        ll a=po(3,n-i);
        ans+=3*po(-1,i)*ch(n,i)%mod*(po(a-1,n)-po(a,n))%mod,ans%=mod;
    }
    ans*=-1;
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}