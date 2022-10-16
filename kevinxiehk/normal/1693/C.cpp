#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"

#define pbds                                               \
    tree<pair<int, int>, null_type, less<pair<int, int>>, \
         rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
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
int in[200005];
int aa = 0;
bool vi[200005];
int ans[200005];
set<int> good[200005];
pbds huh[200005];
void solve(int TC) {
    int n, m;
    cin >> n >> m;
    int t, tt;
    for(int i = 0; i <= n; i++) {
        conn[i].clear();
        in[i] = 0;
        vi[i] = false;
        ans[i] = inf;
    }
    for(int i = 0; i < m; i++) {
        cin >> t >> tt;
        // pc[mp(tt, t)]++;
        conn[tt].pb(t);
        in[t]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;
    dij.push(mp(0, n));
    ans[n] = 0;
    while(!dij.empty()) {
        pair<int, int> now = dij.top();
        // cerr << "a " << now.fi << ' ' << now.se << '\n';
        dij.pop();
        if(vi[now.se]) continue;
        vi[now.se] = true;
        for(auto x: conn[now.se]) {
            huh[x].insert(mp(now.fi * 2, aa++));
            int di = in[x] + now.fi - huh[x].order_of_key(mp(now.fi * 2 + 1, 0)) + 1;
            if(di < ans[x]) {
                ans[x] = di;
                dij.push(mp(di, x));
            }
        }
    }
    cout << ans[1] << '\n';
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