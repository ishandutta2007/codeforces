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
int s[200005];
pair<int, int> dfs(int now, int k) {
    int cc = conn[now].size();
    if(cc == 0) {
        return mp(s[now] * k, s[now]);
    }
    int each = k / cc;
    int lef = k % cc;
    vector<int> ext;
    int ans = s[now] * k;
    for(auto x: conn[now]) {
        auto tt = dfs(x, each);
        ans += tt.fi;
        ext.pb(tt.se);
    }
    sort(ext.begin(), ext.end());
    reverse(ext.begin(), ext.end());
    // cout << now << ' ' << ans << '\n';
    for(int i = 0; i < lef; i++) ans += ext[i];
    return mp(ans, ext[lef] + s[now]);
}
void solve(int TC) {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i <= n; i++) conn[i].clear();
    int t;
    for(int i = 2; i <= n; i++) {
        cin >> t;
        conn[t].pb(i);
    }
    for(int i = 1; i <= n; i++) cin >> s[i];
    cout << dfs(1, k).fi << '\n';
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