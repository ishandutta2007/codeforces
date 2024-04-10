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

int dp[101][3];
bool A[4][2];
int a[101];
int main()
{
    A[0][0] = A[0][1] = 0;
    A[1][0] = 0,A[1][1] = 1;
    A[2][0] = 1,A[2][1] = 0;
    A[3][0] = 1,A[3][1] = 1;
    const int inf = 1e9;
    for(int i = 0;i<101;i++)
        dp[i][0] = dp[i][1] = dp[i][2] = inf;
    int n;
    sd(n);
    rep(i,0,n)
    sd(a[i]);
    dp[0][0] = 1;
    if(A[a[0]][0])
        dp[0][1] = 0;
    else
        dp[0][1] = 1;
    if(A[a[0]][1])
        dp[0][2] = 0;
    else
        dp[0][2] = 1;
    for(int i = 1;i<n;i++)
    {
        dp[i][0] = 1 + min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
        if(A[a[i]][0])
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
        else
            dp[i][1] = inf;
        if(A[a[i]][1])
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
        else
            dp[i][2] = inf;
    }
    cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
}