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

const ll DIM = 5E5+7;
const ll MOD = 1e9+7;

const ll INF = 1E8;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll depth[DIM],P[DIM];
vector<ll> G[DIM],D[DIM];

ll n,m;
void dfs(ll v){
    D[depth[v]].pb(v);

    for(ll to:G[v]){
        if (!depth[to]) {
            P[to] = v;
            depth[to] = depth[v]+1;
            dfs(to);
        }
    }


}
void clearall(){
    forn(i,n){
        G[i].clear();
        D[i].clear();
        depth[i] = P[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        clearall();
        cin>>n>>m;
        forn(i,m){
            ll u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        depth[1] = 1;
        dfs(1);
        ll v = 0;
        forn(i,n){
            if (depth[i]>(n/2+n%2))v = i;
        }
        if (v!=0){
            cout<<"PATH\n";
            cout<<depth[v]<<endl;
            while(1){
                cout<<v<<' ';
                if (P[v]==0)break;
                v = P[v];
            }
            cout<<endl;
            continue;
        }
        vector<pp> ans;
        forn(i,n){
            while(!D[i].empty()){
                ll a =D[i].back();
                D[i].pop_back();
                if (D[i].empty())break;
                ll b = D[i].back();
                D[i].pop_back();
                ans.pb({a,b});
            }
        }
        cout<<"PAIRING\n";
        cout<<ans.size()<<endl;
        for(pp to:ans)cout<<to.fi<<' '<<to.sc<<endl;
    }

    return 0;
}