#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
vector<int> conn[200005];
pair<int, pair<int, int>> di[200005];
int mod = 1e9 + 7;
void solve(int TC) {
    int n, m;
    int s, t;
    cin >> n >> m >> s >> t;
    for(int i = 0; i <= n; i++) {
        conn[i].clear();
        di[i] = mp(-1, mp(0, 0));
    }
    di[s] = mp(0, mp(1, 0));
    queue<pair<int, int>> bfs;
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        conn[u].pb(v);
        conn[v].pb(u);
    }
    bfs.push(mp(0, s));
    while(!bfs.empty()) {
        auto now = bfs.front();
        bfs.pop();
        int add;
        if(now.fi == di[now.se].fi) {
            add = di[now.se].se.fi;
        }
        else {
            add = di[now.se].se.se;
        }
        int nd = now.fi + 1;
        for(auto x: conn[now.se]) {
            if(di[x].fi == -1) {
                di[x].fi = nd;
                bfs.push(mp(nd, x));
            }
            if(di[x].fi == nd) di[x].se.fi += add;
            else if(di[x].fi + 1 == nd) {
                if(di[x].se.se == 0) bfs.push(mp(nd, x));
                di[x].se.se += add;
            }
            di[x].se.fi %= mod;
            di[x].se.se %= mod;
        }
    }
    cout << (di[t].se.fi + di[t].se.se) % mod << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}