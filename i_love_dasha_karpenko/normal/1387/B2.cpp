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
//#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;
const ll MOD = 1e9+7;
const ll INF = 1E5;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll sz[DIM],dp[DIM];
vector<ll> G[DIM];
ll A[DIM],n;
void calc(ll v,ll par){
    sz[v] = 1;
    dp[v] = 0;
    for(ll to:G[v]){
        if (to==par)continue;
        calc(to,v);
        sz[v]+=sz[to];
        dp[v]+=dp[to]+min(n-sz[to],sz[to])*2;
    }

}
ll en = 0,r = 0;
void dfs(ll v,ll par,ll psz,ll pdp){

    if (dp[v]+min(psz,n-psz)*2+pdp>r){
        r = dp[v]+min(psz,n-psz)*2+pdp;
        en = v;
    }
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v,sz[v]+psz-sz[to],dp[v]+min(psz,n-psz)*2+pdp-min(sz[to],n-sz[to])*2-dp[to]);
    }
}
vector<ll> V[DIM];
bool mc(ll a,ll b){
    return sz[a]<sz[b];
}
ll solve(ll v,ll par){
    ll big = 0;
    ll del = 0;
    for(ll to:G[v]){
        if (to==par)continue;
        if (sz[to]>sz[big])big = to;
        del+=solve(to,v);
    }
    sort(G[v].begin(),G[v].end(),mc);


    ll go = min(sz[v],n-sz[v]);
    del+=go;
    ll stay = sz[v]-del;
    if (stay/2+stay%2>V[big].size()){
        ll beg = 0;
        V[v].pb(v);
        for(ll to:G[v]){
            if (to==par)continue;

            if (to!=big){
                for(ll tt:V[to])V[v].pb(tt);

            }
        }
        beg = V[v].size()-1;
        while(!V[big].empty()){
            swap(A[V[big].back()],A[V[v][beg]]);
            --beg;
            V[big].pop_back();
            --stay;
        }
        for(ll i = 0;i<stay;++i){
            if (beg>=0)
            swap(A[V[v].back()],A[V[v][beg]]);
            V[v].pop_back();
            --beg;
        }
    }
    else{

        swap(V[big],V[v]);
        if (stay>1){
            stay-=2;
            swap(A[v],A[V[v].back()]);
            V[v].pop_back();
        }
        else if (stay==1){
            --stay;
            swap(A[v],A[V[v].back()]);

        }
        else V[v].pb(v);
        for(ll to:G[v]){
            if (to==par)continue;
            if (to==big)continue;
            for(ll tt:V[to]){

                if (stay>1){
                    swap(A[tt],A[V[v].back()]);
                    V[v].pop_back();
                    stay-=2;
                }
                else if (stay==1){
                    swap(A[tt],A[V[v].back()]);
                    V[v].pop_back();
                    V[v].pb(tt);
                    --stay;
                }
                else{
                    V[v].pb(tt);
                }
            }
        }
    }

    return sz[v]-go;

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;forn(i,n)A[i] = i;
    forn(i,n-1){
        ll u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    calc(1,0);
    dfs(1,0,0,0);
    calc(en,0);
    solve(en,0);
    cout<<dp[en]<<endl;
    forn(i,n)cout<<A[i]<<' ';
    cout<<endl;
    return 0;
}