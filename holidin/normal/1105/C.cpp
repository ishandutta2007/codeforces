#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 2;
const int mod = 1e9 + 7;

long long dp[N][3], m[3];

int f(int x, int ost) {
    if (ost == 0)
        return x / 3;
    else {
        if (x % 3 >= ost)
            return x / 3 + 1;
        else
            return x / 3;
    }
}

int main() {
    int i, j, k, n, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> l >> r;
    for (i = 0; i < 3; ++i)
        m[i] = f(r, i) - f(l - 1, i);
    dp[0][0] = 1;
    for (i = 0; i < n; ++i)
    for (j = 0; j < 3; ++j)
    for (l = 0; l < 3; ++l)
        dp[i + 1][(j + l) % 3] = (dp[i + 1][(j + l) % 3] + dp[i][j] * m[l]) % mod;
    cout << dp[n][0];
}