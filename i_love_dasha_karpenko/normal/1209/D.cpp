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

vector<ll> A[DIM];
pp S[DIM];
ll vis[DIM],took[DIM],cnt[DIM];
void dfs(ll pos){
    while(!A[pos].empty()){
        ll b = A[pos].back();
        A[pos].pop_back();
        if (took[b]==1)continue;
        if (vis[S[b].fi]+vis[S[b].sc]!=2)took[b] = 1;
        else continue;
        vis[S[b].fi] = vis[S[b].sc] = 1;
        ll val = S[b].fi+S[b].sc-pos;
        dfs(val);
    }
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    set<pp> Se;
    forn(i,k){
        ll x,y;
        cin>>x>>y;
        if (x>y)swap(x,y);
        Se.insert({x,y});
    }
    ll p = 0;
    for(pp to:Se){
        p++;
        S[p] = to;
        cnt[to.fi]++;
        cnt[to.sc]++;
    }
    forn(i,p){
        pp to = S[i];
        if (cnt[to.fi]==1){
            took[i] = 1;
            continue;
        }
        if (cnt[to.sc]==1){
            took[i] = 1;
            continue;
        }
        A[to.fi].pb(i);
        A[to.sc].pb(i);
    }
    forn(i,n){

        dfs(i);
    }
    ll res = 0;
    forn(i,k)res+=took[i]^1;
    cout<<res<<endl;
    return 0;
}