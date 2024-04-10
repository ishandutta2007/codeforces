#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,pair<ll,ll> > pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 5E5+140;
const ll INF = 1E16;
const ll masksz = po(22);

pair<ll,ll> A[DIM];
vector<pp> G[masksz];
vector<ll> ans;
ll vis[DIM],a[DIM*2];
void dfs(ll v,pair<ll,ll> par){
    while(!G[v].empty()){
        pp b = G[v].back();

        G[v].pop_back();
        if (vis[(b.sc.fi+1)/2]==1)continue;
        vis[(b.sc.fi+1)/2]=1;
        dfs(b.fi,b.sc);
    }
    if (par==pair<ll,ll>{0,0})return;
    ans.pb(par.sc);
    ans.pb(par.fi);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    vector<ll> demo;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
        a[i*2-1] = A[i].fi;
        a[i*2] = A[i].sc;

        demo.pb(i*2-1);
        demo.pb(i*2);
    }
    ll res = 0;
    ll mult = 2;
    forn(xx,20){
        forn(i,n){
            G[A[i].fi%mult].pb({A[i].sc%mult,{i*2-1,i*2}});
            G[A[i].sc%mult].pb({A[i].fi%mult,{i*2,i*2-1}});
        }

        dfs(A[1].fi%mult,{0,0});

        if (ans.size()==n*2 && a[ans[0]]%mult==a[ans.back()]%mult){
            res = xx;
            demo = ans;
            ans.clear();
            for(ll i = 0;i<mult;++i)G[i].clear();
            forn(i,n)vis[i] = 0;
        }
        else break;
        mult*=2;
    }
    //if (res==0)n/=0;
    cout<<res<<endl;
    for(ll to:demo)cout<<to<<' ';
    cout<<endl;
    return 0;
}