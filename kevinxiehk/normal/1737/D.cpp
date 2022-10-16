#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
void solve(int TC) {
    int n, m;
    cin >> n >> m;
    int d1[n + 5], dn[n + 5];
    vector<int> dd1[n + 5], ddn[n + 5];
    for(int i = 0; i <= n; i++) d1[i] = dn[i] = inf;
    d1[1] = 0; dn[n] = 0;
    vector<int> conn[n + 5];
    vector<pair<pair<int, int>, int>> edges;
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        conn[a].pb(b);
        conn[b].pb(a);
        edges.pb(mp(mp(a, b), c));
    }
    queue<pair<int, vector<int>>> bfs;
    vector<int> aaa;
    bfs.push(mp(1, aaa));
    while(!bfs.empty()) {
        int k = bfs.front().fi;
        vector<int> aa = bfs.front().se;
        aa.pb(k);
        bfs.pop();
        for(auto x: conn[k]) {
            if(d1[x] > d1[k] + 1) {
                d1[x] = d1[k] + 1;
                dd1[x] = aa;
                bfs.push(mp(x, aa));
            }
        }
    }
    vector<int> bbb;
    bfs.push(mp(n, bbb));
    while(!bfs.empty()) {
        int k = bfs.front().fi;
        vector<int> aa = bfs.front().se;
        aa.pb(k);
        bfs.pop();
        for(auto x: conn[k]) {
            if(dn[x] > dn[k] + 1) {
                dn[x] = dn[k] + 1;
                ddn[x] = aa;
                bfs.push(mp(x, aa));
            }
        }
    }
    for(int i = 0; i <= n; i++) {
        reverse(dd1[i].begin(), dd1[i].end());
        reverse(ddn[i].begin(), ddn[i].end());
    }
    int ans = inf;
    int mmi[n + 5][n + 5];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int cn = 0, mi = inf;
            for(auto xx: dd1[i]) {
                cn++;
                mi = min(mi, cn + d1[xx] + 1 + dn[xx]);
            }
            cn = 0;
            for(auto xx: ddn[i]) {
                cn++;
                mi = min(mi, cn + dn[xx] + 1 + d1[xx]);
            }
            cn = 0;
            for(auto xx: dd1[j]) {
                cn++;
                mi = min(mi, cn + d1[xx] + 1 + dn[xx]);
            }
            cn = 0;
            for(auto xx: ddn[j]) {
                cn++;
                mi = min(mi, cn + dn[xx] + 1 + d1[xx]);
            }
            mmi[i][j] = mi;
        }
    }
    for(auto x: edges) {
        ans = min(ans, x.se * (1 + min(d1[x.fi.fi] + dn[x.fi.se], dn[x.fi.fi] + d1[x.fi.se])));
        
        ans = min(ans, (mmi[x.fi.fi][x.fi.se] + 1) * x.se);
    }
    cout << ans << '\n';
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