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
const ll INF = 10E17;
const ll LOG = 21;
ll tin[DIM],tout[DIM],P[DIM][LOG],timer = 0,dist[DIM];
vector<ll> G[DIM];
void dfs(ll v,ll par){
    dist[v] = dist[par]+1;
    tin[v] = ++timer;
    P[v][0] = par;
    for(ll i = 1;i<LOG;i++){
        P[v][i] = P[P[v][i-1]][i-1];
    }
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
    }
    tout[v] = ++timer;
}
ll par(ll x,ll y){
    if (tin[x]<=tin[y] && tout[y]<=tout[x])return 1;
    return 0;
}
ll lca(ll x,ll y){
    if (par(x,y))return x;
    if (par(y,x))return y;
    for(ll i = LOG-1;i>=0;--i){
        if (!par(P[x][i],y))x = P[x][i];
    }
    return P[x][0];
}
ll fd(ll x,ll y){
    ll lc = lca(x,y);
    return dist[x]+dist[y]-2*dist[lc];
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    tin[0] = -INF;
    tout[0] = INF;
    dist[0] = -1;
    dfs(1,0);
    ll q;
    cin>>q;
    while(q--){
        ll x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        ll d1 = fd(a,b);
        ll d2 = fd(a,x)+fd(y,b)+1;
        ll d3 = fd(a,y)+fd(b,x)+1;
        ll cd = fd(x,y)+1;
        ll d22 = d2+cd;
        ll d33 = d3+cd;
        ll d4 = d1;
        ll d5 = d2;
        ll lc1 = lca(a,b);
        ll lc2 = lca(x,y);
        if (par(lc1,lc2) && (par(lc2,a) || par(lc2,b))){
            d4+=cd;
            d5+=cd;
        }
        else if (par(lc2,lc1) && (par(lc1,x) || par(lc1,y))){
            d4+=cd;
            d5+=cd;
        }

        //cout<<cd<<endl;
        if (d1<=k && (k-d1)%2==0){
            cout<<"YES\n";
        }
        else if (d2<=k && (k-d2)%2==0){
            cout<<"YES\n";
        }
        else if (d3<=k && (k-d3)%2==0){
            cout<<"YES\n";
        }
        else if (d22<=k && (k-d22)%2==0){
            cout<<"YES\n";
        }
        else if (d33<=k && (k-d33)%2==0){
            cout<<"YES\n";
        }
        else if (d4<=k && (k-d4)%2==0){
            cout<<"YES\n";
        }
        else if (d5<=k && (k-d5)%2==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}