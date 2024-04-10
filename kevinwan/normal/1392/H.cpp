//#pragma comment(linker, "/STACK:2000000000")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1<<20;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    ll h=0;
    for(int i=1;i<=n;i++)h+=po(i),h%=mod;
    h*=m,h%=mod;
    h++;
    //cout<<h*6%mod<<endl<<n*po(m+1)%mod+1<<endl;
    printf("%lld",h*(n*po(m+1)%mod+1)%mod);
}