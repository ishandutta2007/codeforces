#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 2e3 + 1;

int a[N][N];
int m[2][N], n;
bool use[N];
long long dp[N][N], t[N];

int f(int i) {
    return i & (-i);
}

void fenw(int s, int i, int j) {
    while (i <= n) {
        m[s][i] += j;
        i += f(i);
    }
}

int fw(int s, int i) {
    if (i == 0)
        return 0;
    else
        return m[s][i] + fw(s, i - f(i));
}

int sum(int s, int l, int r) {
    return fw(s, r) - fw(s, l - 1);
}

int main() {
    int i, j, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
        cin >> a[i][j];
    dp[0][0] = 1;
    for (i = 1; i <= n; ++i)
    for (j = 0; j <= n; ++j) {
        if (j == 0)
            dp[i][j] += (dp[i - 1][j] * i) % mod;
        if (j >= 1)
            dp[i][j] += (dp[i - 1][j - 1] * (i - j)) % mod;
        if (j >= 2)
            dp[i][j] += (dp[i - 1][j - 2] * (j - 1)) % mod;
        dp[i][j] %= mod;
    }
    t[0] = 1;
    for (i = 1; i <= n; ++i)
        t[i] = (t[i - 1] * dp[n][n]) % mod;
    long long ans = 0;
    for (i = 1; i <= n; ++i) {
        int p = n;
        for (j = 1; j <= n; ++j)
            fenw(0, j, 1);
        if (i == 1)
            p = 0;
        else {
            for (j = 1; j <= n; ++j) {
                fenw(1, j, 1);
                use[j] = false;
            }
        }
        for (j = 1; j <= n; ++j) {
            long long x0 = fw(0, a[i][j] - 1), x1 = fw(1, a[i][j] - 1), md1 = 0, md2 = 0, md3 = 0;
            if (i > 1 && !use[a[i - 1][j]] && a[i - 1][j] < a[i][j])
                ++md1;
            if (i > 1 && !use[a[i - 1][j]])
                ++md2;
            if (x1 > 0)
                ans = (ans + t[n - i] * ((x1 - md1) * dp[n - j][fw(1, n) - 1 - md2] % mod)) % mod;
            ans = (ans + t[n - i] * (((x0 - x1) * dp[n - j][fw(1, n) - md2]) % mod)) % mod;
            fenw(0, a[i][j], -1);
            use[a[i][j]] = true;
            if (sum(1, a[i][j], a[i][j]) == 1)
                fenw(1, a[i][j], -1);
            if (i > 1 && !use[a[i - 1][j]])
                fenw(1, a[i - 1][j], -1);
        }
    }
    cout << ans;
}