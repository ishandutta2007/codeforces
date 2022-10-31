#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 2*10E4 +7;
const ll INF = 10E17+7;
ll vis[DIM],pref[DIM],comps;
pp A[DIM];
vector<ll> G[DIM];
void dfs(ll v){
    vis[v] = comps;
    for(ll to:G[v]){
        if (vis[to]==0)dfs(to);
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m; cin>>n>>m;
    forn(i,m){
        ll x,y; cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    //forn(i,n)P[i] = i;
    comps = 0;

   // forn(i,n)if(G[i].size()==0)cnt++;

    for(ll i = 1;i<=n;i++){
        pref[i] = pref[i-1];
        if (vis[i]==0){
            comps++;
            dfs(i);
            A[comps].fi = i;
            A[comps].sc = i;
            pref[i]++;
        }
        else{
            A[vis[i]].sc = i;
        }
    }
    sort(A+1,A+1+comps);
    ll ans = 0;
    for(ll i = 2;i<=comps;i++){
        if (A[i].fi<=A[i-1].sc){ans++;A[i].sc = max(A[i].sc,A[i-1].sc);}
    }
    cout<<ans<<endl;
    return 0;
}

// 1 2 3
//