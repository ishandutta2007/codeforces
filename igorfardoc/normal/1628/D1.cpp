#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1000000007;

int bin_pow(int a, int b) {
    if(b == 0) return 1;
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) {
        res = ((ll)res * a) % mod;
    }
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vvi dp(n + 1, vi(m + 1, 0));
        int other = obr(2);
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(j > i) continue;
                if(i == j) {
                    dp[i][j] = (dp[i - 1][j - 1] + k) % mod;
                    continue;
                }
                if(j == 0) {
                    dp[i][j] = dp[i - 1][j];
                    continue; 
                }
                dp[i][j] = (ll)(dp[i - 1][j - 1] + dp[i - 1][j]) % mod * other % mod;
            }
        }
        cout << dp[n][m] << '\n';
    }
}