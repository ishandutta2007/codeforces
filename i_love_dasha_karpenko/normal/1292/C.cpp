#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
const ll DIM = 3*1000+7;
const ll INF = 10E17;
ll D[DIM][DIM];
pp sub_size[DIM][DIM];
pp P[DIM][DIM];
vector<ll> G[DIM];

ll dp(ll a,ll b,ll p1,ll p2){
    if (D[b][a]!=-1){D[a][b] = D[b][a];sub_size[a][b] = {sub_size[b][a].sc,sub_size[b][a].fi};}
    if (D[a][b]!=-1 )return D[a][b];
    D[a][b] = 0;
    sub_size[a][b] = {1,1};
    for(ll to:G[a]){
        if (to==p1)continue;
        ll r = dp(to,b,a,p2);
        D[a][b] =max(D[a][b],r);
        sub_size[a][b].fi+=sub_size[to][b].fi;
    }
    for(ll to:G[b]){
        if (to==p2)continue;
        ll r = dp(a,to,p1,b);

        D[a][b] = max(D[a][b],r);
        sub_size[a][b].sc+=sub_size[a][to].sc;
    }
    D[a][b]+=sub_size[a][b].fi*sub_size[a][b].sc;
    return D[a][b];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    vector<pp> edges;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
        edges.pb({x,y});
    }
    ll res = 0;
    memset(D,-1,sizeof(D));
    for(pp to:edges){
        res = max(res,dp(to.fi,to.sc,to.sc,to.fi));
    }
    cout<<res<<endl;
    return 0;
}
// 9 7+2