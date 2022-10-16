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
int dsu[200005];
int dsu2[200005];
int f(int x) {
    if(dsu[x] == x) return x;
    return dsu[x] = f(dsu[x]);
}
int f2(int x) {
    if(dsu2[x] == x) return x;
    return dsu2[x] = f2(dsu2[x]);
}
void solve(int TC) {
    int n, m;
    cin >> n >> m;
    // for(int i = 0; i <= n; i++) dsu[i] = i;
    // for(int i = 0; i <= n; i++) dsu2[i] = i;
    int a, b;
    string ans = "";
    for(int i = 0; i < m; i++) ans += '0';
    bool done = false;
    srand(time(NULL));
    vector<int> tt;
    vector<pair<int, int>> ed;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        ed.pb(mp(a, b));
        tt.pb(i);
    }
    while(!done) {
        random_shuffle(tt.begin(), tt.end());
        int le = m;
        for(int i = 0; i <= n; i++) dsu[i] = i;
        for(int i = 0; i <= n; i++) dsu2[i] = i;
        for(auto x: tt) {
            // cerr << x << ' ' << ed[x].fi << ' ' << ed[x].se << '\n';
            if(f(ed[x].fi) == f(ed[x].se)) {
                // cerr << x << '\n';
                ans[x] = '1';
                if(f2(ed[x].fi) == f2(ed[x].se)) break;
                dsu2[f2(ed[x].fi)] = f2(ed[x].se);
            }
            else {
                ans[x] = '0';
                dsu[f(ed[x].fi)] = f(ed[x].se);
            }
            le--;
        }
        // cerr << le << '\n';
        if(le == 0) done = true;
    }
    // for(int _ = 0; _ < m; _++) {
    //     cin >> a >> b;
    //     if(f(a) == f(b)) {
    //         ans += "1";
    //     }
    //     else {
    //         ans += "0";
    //         dsu[f(a)] = f(b);
    //     }
    // }
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