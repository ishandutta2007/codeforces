#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;
const ll INF = 1E19;
const ll MAXN = 50;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll dist[DIM],mx,vis[DIM];
vector<ll> G[DIM];
void dfs(ll v,ll par){
    for(ll to:G[v]){
        if (to==par)continue;
        dist[to] = dist[v]+1;
        mx = max(mx,dist[to]);
        dfs(to,v);
    }
}
ll flag = 0;
 ll n,a,b,da,db;
void clearall(){
    forn(i,n){
        G[i].clear();
        vis[i] = dist[i] = 0;
    }
    flag = 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){


        cin>>n>>a>>b>>da>>db;
        forn(i,n-1){
            ll u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        if (da*2>=db){
            cout<<"Alice\n";
            clearall();
            continue;
        }
        mx = 0;
        dfs(1,1);
        ll v = 0;
        forn(i,n){
            if (dist[i]>=dist[v])v = i;

        }
        forn(i,n)dist[i] = 0;
        dfs(v,v);
        forn(i,n){
            mx = max(mx,dist[i]);
        }
        if (mx<=da*2){
            cout<<"Alice\n";
            clearall();
            continue;
        }

        forn(i,n)dist[i] = 0;
        dfs(a,a);
        if (dist[b]<=da){
            cout<<"Alice\n";
        }
        else cout<<"Bob\n";
        clearall();
    }


    return 0;
}