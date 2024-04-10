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
vector<int> conn[100005];
int ans[100005];
int dfs(int now, int f, int d) {
    int aim;
    if(d % 2 == 0) aim = 1;
    else aim = -1;
    if(d == 0) aim = 0;
    int cn = 0;
    for(auto x: conn[now]) {
        if(x != f) {
            cn += dfs(x, now, d + 1);
        }
    }
    ans[now] = aim - cn;
    return aim;
}
void solve(int TC) {
    int n, t, tt;
    cin >> n;
    for(int i = 0; i <= n; i++) conn[i].clear();
    for(int i = 1; i < n; i++) {
        cin >> t >> tt;
        conn[t].pb(tt);
        conn[tt].pb(t);
    }
    dfs(1, 1, 0);
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
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