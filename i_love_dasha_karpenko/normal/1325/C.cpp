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
ll ans[DIM];
vector<pp> G[DIM];
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    vector<pp> edges;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb({y,i});
        G[y].pb({x,i});
        edges.pb({x,y});
    }
    vector<ll> lev;
    forn(i,n){
        if (G[i].size()==1)lev.pb(i);
    }
    ll cnt = 0;
    memset(ans,-1,sizeof(ans));
    for(ll to:lev){
        if (ans[G[to][0].sc]==-1){
            ans[G[to][0].sc] = cnt;
            cnt++;
        }
    }
    for(ll i = 0;i<n-1;i++){
        if (ans[i+1]!=-1)cout<<ans[i+1]<<endl;
        else cout<<cnt++<<endl;
    }
    return 0;
}
// a[i]-b[i]>b[j]-a[j]