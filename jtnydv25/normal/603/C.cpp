#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

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
vi X,Y;
int grundy(int n, int k)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(k==1 && n== 3)
        return 1;
    if(n==2 && k == 0)
        return 2;
    if(n==2 && k == 1)
        return 0;
    if(n == 4 && k == 1)
        return 2;
    if(n%2==1)
    {
        return 0;
    }
    if(k == 0)
    {
        return grundy(n-1,k)+1;
    }
    int x = grundy(n/2,k),y = grundy(n-1,k);
    if(x == 0)
        return 1;
    if(x > 1)
        return 1;
    return 2;
}

int main()
{
    int n,k;

    sd(n);sd(k);
    k%=2;
    int x;
    int xr = 0;
    rep(i,0,n)
    {
        sd(x);
        xr^=grundy(x,k);
    }
    if(xr)
        cout<<"Kevin";
    else
        cout<<"Nicky";
}