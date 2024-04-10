#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5e5+10;
const int inf=0x3f3f3f3f;
const ll mod=998244353;
ll po(ll a,ll b=mod-2){
	ll ans=1;
	for(a%=mod;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
	return ans;
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
    ll n,m,l,r;
    cin>>n>>m>>l>>r;
    ll e=(r/2)-((l-1)/2),o=(r-l+1)-e;
    ll p1=po(o+e,n*m),pn1=po(-o+e,n*m);
    ll ans;
    if((n&1)&&(m&1))ans=po(e+o,n*m);
    else ans=(p1+pn1)*(mod+1)/2;
    ans%=mod;
    printf("%lld\n",ans);
}