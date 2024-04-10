#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;

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

const ll DIM = 500000 +7;

const ll MOD = 1e9+7;

const ll INF = 1E9+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
vector<pp> G[DIM];
ll dp[DIM][2];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    forn(i,m){
        ll u,v,c;
        cin>>u>>v>>c;
        G[v].pb({u,c});
    }
    forn(i,n)dp[i][0] = dp[i][1] = INF;
    priority_queue<pp,vector<pp>,greater<pp> > Q;
    Q.push({0,n});
    forn(i,n-1)Q.push({INF,i});
    dp[n][0] = dp[n][1] = 0;

    while(!Q.empty()){
        ll t = Q.top().sc;
        if (max(dp[t][0],dp[t][1] )>=INF){
            break;
        }
        Q.pop();
        for(pp to:G[t]){
            if (dp[to.fi][to.sc]>max(dp[t][0],dp[t][1])+1){
                ll ol = dp[to.fi][to.sc];
                dp[to.fi][to.sc] = max(dp[t][0],dp[t][1])+1;
                if (ol>dp[to.fi][to.sc^1])
                Q.push({min(dp[to.fi][to.sc^1],dp[to.fi][to.sc]),to.fi});
            }
        }
    }
    if (max(dp[1][0],dp[1][1])==INF)cout<<-1<<endl;
    else cout<<max(dp[1][0],dp[1][1])<<endl;
    forn(i,n){
        if (dp[i][0]>dp[i][1])cout<<0;
        else cout<<1;
    }
    return 0;

}