#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long ll;

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
const ll MOD = 1e9+123;

const ll INF = 1E17;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
const ll cnum = 9;
vector<pp> G[DIM];
set<pp> C[DIM];
ll vis[cnum+1][cnum+1][cnum+1][cnum+1];
ll st[cnum+1];
ll n,m,k;
ll rec(ll pos){
    if (pos==k+1)
        return 1;

    ll r = 0;
    for(ll i = 1;i<=pos;++i){
        ll flag = 0;
        st[pos] = i;
        for(ll j = 1;j<=pos;++j){
            if (vis[pos][i][j][st[j]]){
                flag = 1;
                break;
            }
        }
        if (flag==0)r+=rec(pos+1);
    }
    st[pos] = 0;
    return r;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m>>k;
    forn(i,m){
        ll u,v,w;
        cin>>u>>v>>w;
        G[u].pb({w,v});
    }
    forn(i,n){
        sort(G[i].begin(),G[i].end());
        for(ll j = 0;j<G[i].size();++j){
            pp to1 = {G[i].size(),j+1};
            for(pp to:C[G[i][j].sc]){
                vis[to.fi][to.sc][to1.fi][to1.sc] = 1;
                vis[to1.fi][to1.sc][to.fi][to.sc] = 1;
            }
            C[G[i][j].sc].insert({G[i].size(),j+1});
        }
    }


    cout<<rec(1)<<endl;
    return 0;
}