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
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll MOD = 1e9+7;
const ll INF = 1E5;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

vector<ll> G[DIM];
ll A[DIM];
ll P[DIM];
ll vis[DIM];
ll ptr = 0;
vector<vector<ll> > V;
void dfs(ll v){
    vis[v] = 1;
    for(ll to:G[v]){

        P[to]++;
        if (vis[to]==0)
        dfs(to);
    }

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    forn(i,n){
        cin>>A[i];
    }
    forn(i,n){
        ll x;
        cin>>x;
        if (x==-1 && x!=i)continue;
        G[i].pb(x);
    }
    forn(i,n){
        if(vis[i]==0){

            dfs(i);
        }
    }
    deque<ll> V;
    forn(i,n){
        if (P[i]==0)V.pb(i);
    }
    ll res = 0;
    vector<ll> ans;
    vector<ll> rr;
    memset(vis,0,sizeof(vis));
    while(!V.empty()){
        ll t = V.front();
        V.pop_front();
        res+=A[t];

        if (!G[t].empty() ){
            if (A[t]>0){
                A[G[t][0]]+=A[t];
                ans.pb(t);
            }
            else rr.pb(t);
            P[G[t][0]]--;
            if (vis[G[t][0]]==0 && P[G[t][0]]==0){
                V.pb(G[t][0]);
                vis[G[t][0]] = 1;
            }
        }
        else ans.pb(t);
    }
    cout<<res<<endl;
    for(ll to:ans)cout<<to<<' ';
    reverse(rr.begin(),rr.end());
    for(ll to:rr)cout<<to<<' ';
    cout<<endl;

    return 0;
}