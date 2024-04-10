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
const ll DIM = 5E5+7;
const ll INF = 1E16;

vector<ll> G[DIM];
pp A[DIM];
ll pos[DIM];
char vis[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    forn(i,m){
        ll u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    forn(i,n){
        cin>>A[i].fi;
        A[i].sc = i;
    }
    sort(A+1,A+1+n);
    vector<ll> ans;
    forn(i,n){
        pos[A[i].sc] = i;
    }
    forn(i,n){
        vector<ll> V = {0};
        for(ll to:G[A[i].sc]){
            if (vis[to]!=0)
                V.pb(A[pos[to]].fi);
        }
        sort(V.begin(),V.end());
        ll ptr = 0;
        for(ll to:V)if (to==ptr)ptr++;
        if (A[i].fi!=ptr){
            cout<<"-1\n";
            return 0;
        }
        ans.pb(A[i].sc);
        vis[A[i].sc] = 1;
    }
    for(ll to:ans)cout<<to<<' ';
    cout<<endl;
    return 0;
}