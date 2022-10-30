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
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;

const ll MOD = 1e9+7;

const ll INF = 1E16+7;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
vector<pp> G[DIM];
ll W[DIM],cst[DIM],cnt[DIM],sz[DIM];
void dfs(ll v,ll par){

    for(pp to:G[v]){
        if (to.fi==par)continue;
        dfs(to.fi,v);
        cnt[to.sc] = sz[to.fi];
        sz[v]+=sz[to.fi];
    }
    if (G[v].size()==1 && v!=1)sz[v] = 1;
}
const ll LOG = 21;
ll dp[DIM*LOG];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,sum;
        cin>>n>>sum;
        forn(i,n-1){
            ll u,v,w,cost;
            cin>>u>>v>>w>>cost;
            G[u].pb({v,i});
            G[v].pb({u,i});
            cst[i] = cost;
            W[i] = w;
        }
        dfs(1,1);
        priority_queue<pp> Q[3];
        ll su = 0;
        forn(i,n-1){
            Q[cst[i]].push({(W[i]-W[i]/2)*cnt[i],i});
            su+=W[i]*cnt[i];
        }
        ll ptr = 0;
        ll res = INF;
        if (su<=sum)res = 0;
        while(!Q[1].empty()){
            pp a = Q[1].top();
            Q[1].pop();
            ll dif = (W[a.sc]-W[a.sc]/2)*cnt[a.sc];
            ++ptr;
            dp[ptr] = dp[ptr-1]+dif;
            if (su-dp[ptr]<=sum)res = min(res,ptr);
            W[a.sc]/=2;
            if (W[a.sc]==0)continue;
            Q[1].push({(W[a.sc]-W[a.sc]/2)*cnt[a.sc],a.sc});
        }

        ll cost = 0;

        while(!Q[2].empty()){
            pp a = Q[2].top();
            Q[2].pop();
            ll dif = (W[a.sc]-W[a.sc]/2)*cnt[a.sc];
            su-=dif;
            ll need = su-sum;
            cost+=2;
            if (dp[ptr]>=need){
                ll pos = lower_bound(dp,dp+1+ptr,need)-dp;
                res = min(res,pos+cost);
            }
            W[a.sc]/=2;
            if (W[a.sc]==0)continue;
            Q[2].push({(W[a.sc]-W[a.sc]/2)*cnt[a.sc],a.sc});
        }

        cout<<res<<endl;
        forn(i,n){
            G[i].clear();
            cst[i] = cnt[i] = sz[i] = W[i] = 0;

        }
    }

    return 0;
}