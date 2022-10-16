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
int dp[105][10005];
void solve(int TC) {
    int n;
    cin >> n;
    pair<int, int> arr[n + 5];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi;
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].se;
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n * 100; j++) dp[i][j] = inf;
    }
    dp[1][arr[1].fi] = dp[1][arr[1].se] = 0;
    int tc = arr[1].fi + arr[1].se;
    int tcc = arr[1].fi * arr[1].fi + arr[1].se * arr[1].se;
    int ans = inf;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= n * 100; j++) {
            dp[i][j + arr[i].fi] = min(dp[i][j + arr[i].fi], dp[i - 1][j] + arr[i].fi * j + arr[i].se * (tc - j));
            dp[i][j + arr[i].se] = min(dp[i][j + arr[i].se], dp[i - 1][j] + arr[i].se * j + arr[i].fi * (tc - j));
        }
        tc += arr[i].fi + arr[i].se;
        tcc += arr[i].fi * arr[i].fi + arr[i].se * arr[i].se;
    }
    for(int i = 0; i <= n * 100; i++) ans = min(ans, dp[n][i]);
    cout << tcc * (n - 1) + ans * 2 << '\n';
    return;
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