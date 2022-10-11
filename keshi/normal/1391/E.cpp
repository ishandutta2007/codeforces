//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, m, d[maxn], par[maxn];
bool vis[maxn];
vector<ll> vec[maxn], g[maxn];
vector<pll> ans;

void dfs(ll v){
    vis[v] = 1;
    vec[d[v]].pb(v);
    for(ll u : g[v]){
        if(!vis[u]){
            d[u] = d[v] + 1;
            par[u] = v;
            dfs(u);
        }
    }
    return;
}

int main(){
    fast_io;

    cin >> t;

    while(t--){
        for(ll i = 0; i <= n; i++){
            vis[i] = 0;
            g[i].clear();
            vec[i].clear();
        }
        cin >> n >> m;
        for(ll i = 0; i < m; i++){
            ll v, u;
            cin >> v >> u;
            g[v].pb(u);
            g[u].pb(v);
        }
        dfs(1);
        if(vec[(n - 1) / 2].empty()){
            cout << "PAIRING\n";
            ans.clear();
            for(ll i = 0; i < n; i++){
                for(ll j = 0; j + 1 < (ll)vec[i].size(); j += 2){
                    ans.pb(Mp(vec[i][j], vec[i][j + 1]));
                }
            }
            cout << ans.size() << '\n';
            for(pll i : ans){
                cout << i.F << " " << i.S << '\n';
            }
        }
        else{
            ll v = vec[(n - 1) / 2][0];
            cout << "PATH\n";
            cout << (n + 1) / 2 << '\n';
            while(v){
                cout << v << " ";
                v = par[v];
            }
            cout << '\n';
        }
    }
    

    return 0;
}