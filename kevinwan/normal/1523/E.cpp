#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=1e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;

ll fact[mn],ifact[mn];

ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}

ll ch(ll a,ll b){
    if(b<0||b>a)return 0;
    return fact[a]*ifact[b]%mod*ifact[a-b]%mod;
}

ll dp[mn];
void solve(){
    ll n,k;
    cin>>n>>k;
    dp[0]=1;
    for(int i=1;i<=n;i++)dp[i]=ch(n-(k-1)*(i-1),i)*po(ch(n,i))%mod;//,cerr<<dp[i]<<endl;
    ll ans=0;
    for(int i=1;i<n;i++)ans+=(dp[i]-dp[i+1])*(i+1)%mod,ans%=mod;
    if(ans<0)ans+=mod;
    printf("%lld\n",ans);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    fact[0]=ifact[0]=1;
    for(int i=1;i<mn;i++)fact[i]=fact[i-1]*i%mod,ifact[i]=po(fact[i]);
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}