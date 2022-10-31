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
//#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1000+7;
const ll INF = 10E16;
const ll MM = 2007;
ll A[DIM],cnt[MM];
vector<ll> V,G[DIM];
ll ask(ll x,ll y){
    cout<<"? "<<x<<' '<<y<<endl;
    cin>>x;
    if (x==-1)x/=0;
    return x;
}
void dfs(ll v,ll par){
    vector<ll> vv;
    for(ll to:G[v]){
        if (to!=par)vv.pb(to);
    }
    G[v] = vv;
    if (G[v].size()==1){
        V.pb(v);
        dfs(G[v][0],v);
        return;
    }
    if (G[v].size()==0){
        V.pb(v);
        return;
    }
    ll i = 1;

    for(;i<G[v].size();i+=2){
        ll g = ask(G[v][i],G[v][i-1]);
        if (g!=v){
            V.clear();
            dfs(g,v);
            return;
        }
    }
    i--;
    V.pb(v);
    if (i!=G[v].size())dfs(G[v][i],v);

}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    ll n;
    cin>>n;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    ll st = -1;
    forn(i,n-1){
        if (G[i].size()==1){
            st = i;
            break;
        }
    }
    dfs(st,st);
    ll cur = V[0];
    for(ll i = 1;i+1<V.size();i++){
        ll g = ask(cur,V[i+1]);
        cur = g;
        i++;
    }
    if(V.size()%2==0)
    cur = ask(cur,V.back());
    cout<<"! "<<cur<<endl;
    return 0;
}