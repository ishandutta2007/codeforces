#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=3e5+10;
const ll mod=998244353;

ll a[mn],fact[mn];
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n*2;i++)cin>>a[i];
    ll ans=0;
    fact[0]=1;
    for(int i=1;i<mn;i++)fact[i]=fact[i-1]*i%mod;
    sort(a,a+2*n);
    for(int i=0;i<n;i++)ans-=a[i],ans+=a[i+n],ans%=mod;
    printf("%lld\n",ans*fact[2*n]%mod*po(fact[n]*fact[n]%mod)%mod);
}
/*
Always remember to add the \n at the end
Don't get stuck on a problem

*/