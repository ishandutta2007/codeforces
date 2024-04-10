#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2*10E4+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll n,A[DIM],mi[DIM],mx[DIM],ans[DIM];
vector<ll> G[DIM];
void dfs(ll v,ll par){

    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
        mx[v] = max(mx[v],mx[v]+mx[to]);
        mi[v] = min(mi[v],mi[v]+mi[to]);
    }
    mx[v]+=A[v];
    mi[v]+=A[v];
}
void solve(ll v,ll par){
    if (v==6){
        ll r;
        r = 0;
    }
    ll a1 = 0,a2 = 0;
    for(ll to:G[v]){
        a1 = min(a1,a1+mi[to]);
        a2 = max(a2,a2+mx[to]);
    }
    a1+=A[v];
    a2+=A[v];
    ll omx = mx[v],omi = mi[v];
    mx[v] = a2;
    mi[v] = a1;
    ll res = -INF;
    res = max(res,a1);
    res = max(res,a2);
    ans[v] = res;
    for(ll to:G[v]){
        if (to==par)continue;
        if (mi[to]<0)mi[v]-=mi[to];
        if (mx[to]>0)mx[v]-=mx[to];
        solve(to,v);
        mx[v] = max(mx[v],mx[v]+mx[to]);
        mi[v] = min(mi[v],mi[v]+mi[to]);
    }
    mx[v] = omx;
    mi[v] = omi;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n){
        cin>>A[i];
        if (A[i]==0)A[i] = -1;
    }
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1,1);
    solve(1,1);
    forn(i,n)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}
// a[i]-b[i]>b[j]-a[j]