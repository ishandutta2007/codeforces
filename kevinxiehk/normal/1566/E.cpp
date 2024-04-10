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
vector<int> conn[200005];
int ans = 0;
int dfs(int now, int pa) {
    int cnt = 0;;
    for(auto x: conn[now]) {
        if(x != pa) {
            cnt += dfs(x, now);
        }
    }
    if(cnt == 0) ans++;
    else ans--;
    //cout << now << ' ' << cnt << '\n';
    if(cnt == 0) return 1;
    return 0;
}
void solve(int TC) {
    int n;
    ans = 0;
    cin >> n;
    int u, v;
    for(int i = 0; i <= n; i++) conn[i].clear();
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        conn[u].pb(v);
        conn[v].pb(u);
    }
    int k = dfs(1, -1);
    if(k == 0) {
        ans ++;
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