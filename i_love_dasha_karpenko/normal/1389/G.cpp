#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 3E5+7;
const ll MOD = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
stack<ll> S;
ll col[DIM],tin[DIM],tmin[DIM],timer = 0,ptr = 0,c[DIM],C[DIM],spec[DIM],O[DIM],ww[DIM];
vector<pair<pp,ll> > edges;
vector<pp> g[DIM],G[DIM];
ll n,m,k;
void cond(ll v,ll par){
    S.push(v);
    tin[v] = tmin[v] = ++timer;
    for(pp to:g[v]){
        if (to.fi==par)continue;
        if(tin[to.fi]!=0){
            tmin[v] = min(tin[to.fi],tmin[v]);
        }
        else{
            cond(to.fi,v);
            tmin[v] = min(tmin[v],tmin[to.fi]);
            if (tmin[to.fi]>tin[v]){
                ++ptr;
                while(1){
                    ll t = S.top();
                    col[t] = ptr;
                    C[ptr]+=c[t];
                    O[ptr]+= spec[t];
                    S.pop();
                    if (t==to.fi)break;
                }
            }
        }
    }
}
ll ocnt[DIM],dp[DIM];
void dfs(ll v,ll par){
    ocnt[v] = O[v];
    dp[v] = C[v];
    for(pp to:G[v]){
        if (to.fi==par)continue;
        dfs(to.fi,v);
        ocnt[v]+=ocnt[to.fi];
        if (ocnt[to.fi]==0 || ocnt[to.fi]==k)dp[v]+=dp[to.fi];
        else dp[v]+=max(0ll,dp[to.fi]-to.sc);

    }


}
ll ans[DIM];
void solve(ll v,ll par){

    ocnt[v] = O[v];
    dp[v] = C[v];

    for(pp to:G[v]){
        ocnt[v]+=ocnt[to.fi];
        if (ocnt[to.fi]==0 || ocnt[to.fi]==k)dp[v]+=dp[to.fi];
        else dp[v]+=max(0ll,dp[to.fi]-to.sc);

    }

    ans[v] = dp[v];
    for(pp to:G[v]){
        if (to.fi==par)continue;
        ll val;
        if (ocnt[to.fi]==0 || ocnt[to.fi]==k)val = dp[to.fi];
        else val = max(0ll,dp[to.fi]-to.sc);
        dp[v]-=val;
        ll mcnt = ocnt[to.fi];
        ocnt[v]-=mcnt;
        solve(to.fi,v);
        dp[v]+=val;
        ocnt[v]+=mcnt;
    }

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m>>k;
    forn(i,k){
        ll x;
        cin>>x;
        spec[x] = 1;
    }
    forn(i,n){
        cin>>c[i];
    }
    forn(i,m){
        cin>>ww[i];
    }
    forn(i,m){
        ll u,v;
        cin>>u>>v;
        edges.pb({{u,v},ww[i]});
        g[v].pb({u,ww[i]});
        g[u].pb({v,ww[i]});
    }
    cond(1,1);
    ++ptr;
    while(!S.empty()){
        col[S.top()] = ptr;
        O[ptr]+=spec[S.top()];
        C[ptr]+=c[S.top()];
        S.pop();
    }
    for(pair<pp,ll> to:edges){
        if (col[to.fi.fi]!=col[to.fi.sc]){
            G[col[to.fi.fi]].pb({col[to.fi.sc],to.sc});
            G[col[to.fi.sc]].pb({col[to.fi.fi],to.sc});
        }
    }
    dfs(1,1);
    solve(1,1);
    forn(i,n){
        cout<<ans[col[i]]<<' ';
    }
    cout<<endl;
    return 0;
}