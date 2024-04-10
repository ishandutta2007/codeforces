#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 1e8;

vector<ll> G[DIM];
ll P[DIM],timer= 0,tin[DIM],tout[DIM];
void dfs(ll v,ll par){
    P[v] = par;
    tin[v] = ++timer;
    for(ll to:G[v]){
        if (to!=par)dfs(to,v);
    }
    tout[v] = timer;
}
bool mc(ll a,ll b){
    return tin[a]<tin[b];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m;
    cin>>n>>m;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1,1);
    while(m--){
        vector<ll> V;
        ll s;
        cin>>s;
        forn(i,s){
            ll x;
            cin>>x;
            V.pb(P[x]);
        }
        sort(V.begin(),V.end(),mc);
        ll last = 1;
        ll flag= 0;
        for(ll to:V){
            if (tin[last]<=tin[to] && tout[to]<=tout[last]){
                last = to;
            }
            else{
                flag = 1;
                break;
            }
        }
        if (flag==1)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}