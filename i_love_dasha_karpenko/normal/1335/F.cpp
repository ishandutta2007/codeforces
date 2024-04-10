#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
typedef int  ll;
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
const ll DIM = 1E5+7;
const ll INF = 1e18;
 
 
vector<vector<char> > A;
vector<vector<pp> > dp;
vector<vector<ll> > vis;
ll cur = 0;
pp last = {0,0};
vector<ll> sz;
void dfs(ll x,ll y){
    vis[x][y] = 1;
    ll nx = x,ny = y;
    if (A[x][y]=='U')nx--;
    if (A[x][y]=='R')ny++;
    if (A[x][y]=='D')nx++;
    if (A[x][y]=='L')ny--;
    if (vis[nx][ny]==1){
        dp[x][y].fi = 0;
        dp[x][y].sc = ++cur;
        vis[x][y] = 2;
        sz.pb(1);
        last = {nx,ny};
        return ;
    }
    if (vis[nx][ny]==0)
    dfs(nx,ny);
    dp[x][y].fi = dp[nx][ny].fi+1;
    dp[x][y].sc = dp[nx][ny].sc;
    vis[x][y] = 2;
    if (last!=pp{0,0})sz[dp[x][y].sc]++;
    if (last==pp{x,y})last = {0,0};
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        sz.pb(0);
        vector<pp> bl;
        ll n,m;
        cin>>n>>m;
        A.resize(n+7);
        dp.resize(n+7);
        vis.resize(n+7);
        forn(i,n){
            A[i].resize(m+7);
            dp[i].resize(m+7);
            vis[i].resize(m+7);
        }
        forn(i,n){
            forn(j,m){
                char ch;
                cin>>ch;
                if (ch=='0')bl.pb({i,j});
            }
        }
        forn(i,n){
            forn(j,m){
                cin>>A[i][j];
                dp[i][j] = {-1,-1};
                vis[i][j] = 0;
            }
        }
        forn(i,n){
            forn(j,m){
                if (dp[i][j]==pp{-1,-1})dfs(i,j);
            }
        }
        vector<set<ll> > cyc;
        cyc.resize(cur+1);
        ll res = 0;
        for(pp to:bl){
            ll num = dp[to.fi][to.sc].sc;
            ll pos = dp[to.fi][to.sc].fi%sz[num];
            if (cyc[num].count(pos)==0){
                res++;
                cyc[num].insert(pos);
            }
        }
        ll res1 = res;
        forn(i,n){
            forn(j,m){
                //cout<<dp[i][j].fi<<' '<<dp[i][j].sc<<endl;
                pp to = {i,j};
                ll num = dp[to.fi][to.sc].sc;
                ll pos = dp[to.fi][to.sc].fi%sz[num];
                if (cyc[num].count(pos)==0){
                    res++;
                    cyc[num].insert(pos);
                }
            }
        }
        cout<<res<<' '<<res1<<endl;
        A.clear();
        dp.clear();
        sz.clear();
        vis.clear();
        cyc.clear();
        cur = 0;
        last = {0,0};
    }
    return 0;
}