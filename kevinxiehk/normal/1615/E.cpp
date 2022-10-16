#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
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
vector<int> idk;
int dfs(int now, int fa) {
    vector<int> aa;
    for(auto x: conn[now]) if(x != fa) aa.pb(dfs(x, now));
    sort(aa.begin(), aa.end());
    if(aa.empty()) return 1;
    for(int i = 0; i < aa.size() - 1; i++) idk.pb(aa[i]);
    return aa[aa.size() - 1] + 1;
}
void solve(int TC) {
    int n, k;
    cin >> n >> k;
    int t, tt;
    for(int i = 1; i < n; i++) {
        cin >> t >> tt;
        conn[t].pb(tt);
        conn[tt].pb(t);
    }
    idk.pb(dfs(1, 1));
    sort(idk.begin(), idk.end());
    // for(auto x: idk) cerr << x << ' '; cerr << '\n';
    int aaa = idk.size();
    if(k >= idk.size()) {
        k = min(k, max((int)idk.size(), n / 2));
        int ans = k * (n - k);
        int b = 0, r = idk.size();
        for(auto x: idk) {
            b += x;
            r--;
            ans = max(ans, (n - r - b) * (r - b));
        }
        cout << ans << '\n';
        return;
    }
    int bcnt = 0;
    for(int i = 0; i < idk.size() - k; i++) {
        bcnt += idk[i];
    }
    int ans = LLONG_MAX;
    for(int i = 0; i <= bcnt; i++) ans = min(ans, (n - k - i) * (k - i));
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}