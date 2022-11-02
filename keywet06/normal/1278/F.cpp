#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = 1LL * ans * a % P;
        a = 1LL * a * a % P;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> f(k + 1);
    for (int i = 0; i <= k; ++i) {
        f[i].resize(i + 1);
        f[i][i] = i == 0 ? 1LL : 1LL * f[i - 1][i - 1] * (n - i + 1) % P;
        for (int j = 1; j < i; ++j) {
            f[i][j] =
                (1LL * f[i - 1][j] * j + 1LL * f[i - 1][j - 1] * (n - j + 1)) %
                P;
        }
    }
    int inv = power(m, P - 2);
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = (ans + 1LL * f[k][i] * power(inv, i)) % P;
    }
    cout << ans << "\n";
    return 0;
}