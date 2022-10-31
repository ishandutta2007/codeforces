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
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 5*10E4+7;
const ll INF = 10E16;

ll n;
pp ans[DIM];
vector<ll> G[DIM];
ll dfs(ll v,ll par,ll l,ll give)
{
    ll r = give+G[v].size()+1;
    ans[v] ={l,r};
    r--;
    give = r;
    for(ll to:G[v]){
        if (to==par)continue;
        give=max(dfs(to,v,r,give),give);
        r--;
    }
    return give;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n-1){
        ll x,y; cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1,-1,1,1);
    forn(i,n)cout<<ans[i].fi<<' '<<ans[i].sc<<endl;
    return 0;
}

// 1 2 3
//