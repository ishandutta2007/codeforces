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
const ll DIM = 2E5+7;
const ll INF = 1E16;
const ll LOG = 22;
ll A[DIM],B[DIM],C[DIM];
vector<ll> G[DIM];
void dfs(ll v,ll par,ll cost){
    cost = min(A[v],cost);
    A[v] = cost;
    for(ll to:G[v]){
        if (to!=par){
            dfs(to,v,cost);

        }
    }
}
ll res =0;
ll calc(ll v,ll par){
    ll bal = 0;
    if (B[v]!=C[v]){
        if (B[v]==1)bal++;
        else bal--;
    }
    for(ll to:G[v]){
        if (to==par)continue;
        ll nbal = calc(to,v);
        if (nbal*bal<0){
            res+=(abs(bal)+abs(nbal)-abs(bal+nbal))*A[v];
            bal+=nbal;
        }
        else bal+=nbal;
    }
    return bal;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n){
        cin>>A[i]>>B[i]>>C[i];
    }

    forn(i,n-1){
        ll u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,1,A[1]);

    ll x = calc(1,1);
    if (x!=0){
        cout<<"-1\n";
        return 0;
    }
    cout<<res<<endl;

    return 0;
}