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
    int n;
    cin >> n;
    int cn = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cn += abs(t) % 2;
    }
    int dp[105][105][2]; // tot, odd, alice
    dp[0][0][1] = 0;
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k < 2; k++) {
                if(i % 2 != n % 2) {
                    if(j != i) dp[i][j][k] = dp[i - 1][j][k];
                    else dp[i][j][k] = 1;
                    if(j > 0) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k]);
                }
                else {
                    if(j != i) dp[i][j][k] = dp[i - 1][j][k];
                    else dp[i][j][k] = 0;
                    if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k ^ 1]);
                }
            }
        }
    }
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= i; j++) {
    //         cout << dp[i][j][0] << dp[i][j][1] << ' ';
    //     }
    //     cout << '\n';
    // }
    if(dp[n][cn][0] == 1) cout << "Alice\n";
    else cout << "Bob\n";
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