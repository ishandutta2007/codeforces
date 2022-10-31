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
const ll DIM = 10E4+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll CP[DIM],sz[DIM],ts,level[DIM];
vector<ll> G[DIM];
ll calcsize(ll v,ll par){
    sz[v] = 1;
    for(ll to:G[v]){
        if (CP[to]!=0 || to==par)continue;
        calcsize(to,v);
        sz[v]+=sz[to];
    }
    return sz[v];
}
ll findcent(ll v,ll par){
    for(ll to:G[v]){
        if (to==par || CP[to]!=0)continue;
        if (sz[to]*2>ts){
            return findcent(to,v);
        }
    }
    return v;
}
void decompose(ll v,ll par,ll lev){
    ts = calcsize(v,v);
    ll cent = findcent(v,v);
    CP[cent] = par;
    level[cent] = lev;
    for(ll to:G[cent]){
        if (CP[to]==0)decompose(to,cent,lev+1);
    }
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    decompose(1,1,0);
    forn(i,n)cout<<char('A'+level[i])<<' ';
    cout<<endl;
    return 0;
}
// a[i]-b[i]>b[j]-a[j]