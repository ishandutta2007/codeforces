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
vector<int> conn[200005];
int fa[25][200005];
int dep[200005];
void dfs(int a, int f) {
    fa[0][a] = f;
    for(auto x: conn[a]) {
        if(x != f) {
            dep[x] = dep[a] + 1;
            dfs(x, a);
        }
    }
}
bool cmp(int a, int b) {
    return dep[a] > dep[b];
}
int lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = 20; i >= 0; i--) {
        if(dep[a] - (1 << i) >= dep[b]) a = fa[i][a];
    }
    if(a == b) return a;
    for(int i = 20; i >= 0; i--) {
        if(fa[i][a] != fa[i][b]) {
            a = fa[i][a];
            b = fa[i][b];
        }
    }
    return fa[0][a];
}
void solve(int TC) {
    int n;
    cin >> n;
    int t, tt;
    for(int i = 1; i < n; i++) {
        cin >> t >> tt;
        conn[t].pb(tt);
        conn[tt].pb(t);
    }
    dfs(1, 1);
    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= n; j++) {
            fa[i][j] = fa[i - 1][fa[i - 1][j]];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        bool can = true;
        int k;
        cin >> k;
        int t;
        vector<int> tt;
        for(int i = 1; i <= k; i++) {
            cin >> t;
            tt.pb(t);
        }
        sort(tt.begin(), tt.end(), cmp);
        bool fd = false;
        int aa = tt[0], bb, cc, dd = 0;
        for(int i = 1; i < k; i++) {
            // cout << aa << ' ' << fd << ' ';
            // if(fd) cout << bb << ' ' << cc << ' ' << dd << '\n';
            // else cout << '\n';
            if(lca(aa, tt[i]) != tt[i] || dep[tt[i]] < dd) {
                if(!fd) {
                    fd = true;
                    bb = tt[i];
                    cc = lca(aa, tt[i]);
                    dd = dep[cc];
                }
                else if (lca(bb, tt[i]) != tt[i] || dep[cc] > dep[tt[i]]){
                    can = false;
                }
            } 
            // else if(lca(aa, tt[i]) == tt[i]) can = false;
        }
        if(can) cout << "YES\n";
        else cout << "NO\n";
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}