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

const ll INF = 1E13;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll vis[DIM];
pp dp[DIM];
vector<pp> G[DIM];
ll imp = 0;
ld cof;
ll cnd = 0;
ld val[DIM];
queue<ll> Q;
vector<ll> V;
void dfs(ll v){
    vis[v] = 1;
    Q.push(v);
    V.pb(dp[v].fi*dp[v].sc*(-1));
    for(pp to:G[v]){
        if (vis[to.fi]==0){
            dp[to.fi] = {-dp[v].fi,to.sc-dp[v].sc};
            dfs(to.fi);
        }
        pp must = {-dp[v].fi,to.sc-dp[v].sc};
        pp dif = {dp[to.fi].fi-must.fi,must.sc-dp[to.fi].sc};

        if (dif.fi==0 && dif.sc!=0){
            imp = 1;
            continue;
        }
        if (dif.fi!=0){
            cof = ld(dif.sc)/dif.fi;
            cnd = 1;
        }
    }
}
ld solve(ll v){
    Q.push(v);
    vis[v] = 1;
    ld sum = abs(val[v]);
    for(pp to:G[v]){
        if (vis[to.fi]==0){
            val[to.fi] = to.sc-val[v];

            sum+=solve(to.fi);
        }
        if (val[to.fi]!=to.sc-val[v]){
            imp = 1;
        }
    }
    return sum;
}
void cl(ll ind = 0){
    while(!Q.empty()){
        vis[Q.front()] = ind;
        Q.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    forn(i,m){
        ll u,v,c;
        cin>>u>>v>>c;
        G[u].pb({v,c});
        G[v].pb({u,c});
    }

    forn(i,n){
        V.clear();
        if (vis[i]==1)continue;
        dp[i] = {1,0};
        cof = 0;
        cnd = 0;
        dfs(i);
        cl(0);

        if (imp){
            cout<<"NO\n";
            return 0;
        }
        if (cnd){
            val[i] = cof;
            solve(i);
            cl(1);
            continue;
        }
        ll sum = 0;
        ll cnt = V.size();
        for(ll to:V)sum+=to;
        sort(V.begin(),V.end());
        pp res = {sum-V[0]*cnt,V[0]};
        V.pb(INF);
        for(ll i = 0;i<V.size()-1;++i){
            ll to = V[i];
            sum-=to*2;
            --cnt;
            ll xnum = (V.size()-1-cnt)-cnt;
            ll l = to,r = V[i+1];
            res = min(res,{sum+xnum*l,l});
            res = min(res,{sum+xnum*r,r});
        }
        val[i] = res.sc;
        solve(i);
        cl(1);
    }
    if (imp){
        return cout<<"NO\n",0;
    }
    cout<<"YES\n";
    forn(i,n)cout<<fixed<<setprecision(10)<<val[i]<<' ';
    return 0;
}