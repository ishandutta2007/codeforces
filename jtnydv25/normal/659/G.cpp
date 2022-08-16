#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

void gett()
{
    cerr<< (clock())/(double)cps<<endl;
}

ll powr(ll a, ll b, ll mod)
{
    ll x = 1%mod;
    a %= mod;
    while(b)
    {
        if(b&1)
            x = (x*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return x;
}
ll inv(ll a, ll mod)
{
    return powr(a,mod-2,mod);
}

const int maxn = 1e6+10;
const ll mod = 1e9+7;

int dp[maxn],H[maxn],l[maxn],r[maxn],m[maxn];
const ll inf = 1e9+7;
int main()
{
    memset(dp,0,sizeof dp);
    int n;
    sd(n);
    rep(i,1,n+1)
    sd(H[i]);
    H[0] = H[n+1] = inf;
    rep(i,1,n+1)
    {
        l[i] = min(H[i],H[i-1]);
        r[i] = min(H[i],H[i+1]);
        m[i] = min(l[i],r[i]);
    }
    ll sm = H[1]-1;
    dp[1] = H[1]-1;
    rep(i,2,n+1)
    {
        dp[i] = (H[i] - 1 + (l[i]-1)*1ll*(l[i]-1))%mod;
        if(l[i-1] >= 2)
            dp[i] += (((((dp[i-1] - H[i-1] + 1)*1ll*(m[i-1]-1))%mod * inv(l[i-1]-1,mod))%mod)*1ll*(l[i]-1))%mod;
        dp[i]%=mod;
        sm = (sm+dp[i])%mod;
    }
    if(sm<0)
        sm+=mod;
    cout<<sm;

}