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

const int maxn = 2005;
ll x[maxn],y[maxn];
#define plll pair<pair<ll,ll> ,ll>
bool cmp(const plll& a,const plll& b)
{
    return a.S < b.S;
}
vector<plll > pts;
int p,q,r,s;
ll sqdist(ll a, ll b, ll c, ll d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}
ll mindist(int ind, int n)
{
    ll _dist = 0;
    for(int i = ind;i<n;i++)
    {
        _dist = max(_dist,sqdist(r,s,pts[i].F.F,pts[i].F.S));
    }
    return _dist;
}
int main()
{
    int n;
    cin>>n;
    cin>>p>>q>>r>>s;
    for(int i = 0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        pts.eb(mp(mp(x[i],y[i]),sqdist(x[i],y[i],p,q)));
    }
    sort(pts.begin(),pts.end(),cmp);
    ll mn = 1e18;
    ll r1 = 0;
    for(int i = 0;i<=n;i++)
    {
        mn = min(mn,r1+mindist(i,n));
        r1 = pts[i].S;
    }
    cout<<mn;
}