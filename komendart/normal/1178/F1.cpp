#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

const int mod = 998244353;
const int maxn = 505;

int n;
int c[maxn];
int dp[maxn][maxn];

void calc_dp(int left, int right) {
    int mid = min_element(c + left, c + right) - c;
    int L = 0;
    for (int i = left; i <= mid; ++i) {
        L += dp[left][i] * dp[i][mid];
        if (!(i & 3)) L %= mod;
    }
    int R = 0;
    for (int i = mid; i < right; ++i) {
        R += dp[mid + 1][i + 1] * dp[i + 1][right];
        if (!(i & 3)) R %= mod;
    }
    //cerr << L << ' ' << R << endl;
    dp[left][right] = L % mod * R % mod;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i <= n; ++i) {
        dp[i][i] = 1;
    }
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;
            calc_dp(l, r);
        }
    }
    
    cout << dp[0][n] << '\n';
}