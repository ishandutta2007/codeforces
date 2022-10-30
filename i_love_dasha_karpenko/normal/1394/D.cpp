#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll MOD = 1e9+7;

const ll INF = 1E19;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll n,t[DIM],h[DIM],indeg[DIM],outdeg[DIM],dw[DIM],up[DIM],vis[DIM];
vector<ll> G[DIM];
void dfs(ll v,ll par){
    vis[v] = 1;
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
    }
    vector<pp> V;
    for(ll to:G[v]){
        if (to==par)continue;
        V.pb({dw[to]-up[to],to});
    }
    sort(V.begin(),V.end());
    vector<ll> pref,suf;
    pref.pb(0);
    for(pp to:V){
        pref.pb(pref.back()+up[to.sc]);
    }
    suf.pb(0);
    for(ll i =ll( V.size())-1;i>=0;--i){
        pp to = V[i];
        suf.pb(suf.back()+dw[to.sc]);
    }
    suf.pb(suf.back());
    reverse(suf.begin(),suf.end());
    ll ff = 0;
    if (v!=par)ff = 1;
    for(ll i = 0;i<=V.size();++i){
        ll r = pref[i]+suf[i+1];
        ll in = indeg[v]+i;
        ll ou = outdeg[v]+ll(V.size()-i);
        dw[v] = max(dw[v],r+min(in+ff,ou)*t[v]);
        up[v] = max(up[v],r+min(in,ou+ff)*t[v]);

    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n){
        cin>>t[i];
    }
    forn(i,n){
        cin>>h[i];
    }
    ll res = 0;
    forn(i,n-1){
        ll u,v;
        cin>>u>>v;
        res+=t[u]+t[v];
        if (h[u]!=h[v]){
            if (h[u]>h[v])swap(u,v);
            outdeg[u]++;
            indeg[v]++;
        }
        else{
            G[u].pb(v);
            G[v].pb(u);
        }
    }
    forn(i,n){
        if (vis[i])continue;
        dfs(i,i);
        res-=dw[i];
    }
    cout<<res<<endl;

    return 0;
}