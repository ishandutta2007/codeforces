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
//#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E3+7;
const ll INF = 2E15;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

vector<ll> G[DIM],D[DIM];

pp ask(vector<ll> &V){
    cout<<"? "<<V.size()<<' ';
    for(ll to:V)cout<<to<<' ';
    cout<<endl;
    pp ret;
    cin>>ret.fi>>ret.sc;
    if (ret.fi==-1)ret.fi/=0;
    return ret;
}
ll depth[DIM],mx;
void dfs(ll v,ll par){
    D[depth[v]].pb(v);
    mx = max(mx,depth[v]);
    for(ll to:G[v]){
        if (to==par)continue;
        depth[to] = depth[v]+1;
        dfs(to,v);
    }
}
void dfs1(ll v,ll par){
    for(ll to:G[v]){
        if (to==par)continue;
        depth[to] = depth[v]+1;
        dfs1(to,v);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        mx = 0;
        forn(i,n-1){
            ll u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        vector<ll> V;
        forn(i,n)V.pb(i);
        pp xx = ask(V);
        ll val = xx.sc;
        ll dir = xx.fi;
        depth[dir] = 0;
        dfs(dir,dir);
        ll l = val/2-1,r = min(val,mx);

        ll last = dir;
        while(l!=r){
            ll tm = (l+r+1)/2;
            pp x = ask(D[tm]);
            if (x.sc==xx.sc){
                l = tm;
                last = x.fi;
            }
            else r = tm-1;
        }

        ll a = last;
        depth[a] = 0;
        dfs1(a,a);
        V.clear();
        forn(i,n){
            if (depth[i]==xx.sc)V.pb(i);
        }
        xx = ask(V);
        cout<<"! "<<a<<' '<<xx.fi<<endl;
        for(ll i = 0;i<=n;++i){
            D[i].clear();
            G[i].clear();
            depth[i] = 0;
        }
        string s;
        cin>>s;
        if (s=="Incorrect")n/=0;

    }

    return 0;
}
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,