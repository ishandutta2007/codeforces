#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int MOD = 1E9 + 7;
int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = LL(ans) * a % MOD;
        a = LL(a) * a % MOD;
        b >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> p(n);
    for (auto &i : p) {
        i.resize(n);
        for (int &j : i) {
            cin >> j;
            j = LL(j) * power(100, MOD - 2) % MOD;
        }
    }
    vector<vector<int>> id(n + 1);
    vector<vector<int>> subsets(n + 1);
    for (int sz = 0; sz <= n; ++sz) {
        id[sz].resize(1 << n);
        for (int s = 0; s < (1 << n); ++s)
            if (__builtin_popcount(s) == sz) {
                id[sz][s] = subsets[sz].size();
                subsets[sz].push_back(s);
            }
    }
    vector<map<LL, int>> families(n + 1);
    families[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < (1 << n); ++s) {
            int pr = 1;
            for (int j = 0; j < n; ++j)
                if (s >> j & 1)
                    pr = LL(pr) * p[i - 1][j] % MOD;
                else
                    pr = LL(pr) * (1 + MOD - p[i - 1][j]) % MOD;
            for (auto [f, _p] : families[i - 1]) {
                LL mask = 0;
                for (int t : subsets[i])
                    for (int j = 0; j < n; ++j)
                        if ((t >> j & 1) && (s >> j & 1) && (f >> id[i - 1][t ^ 1 << j] & 1)) {
                            mask |= 1LL << id[i][t];
                            break;
                        }
                families[i][mask] = (families[i][mask] + LL(_p) * pr) % MOD;
            }
        }
    }
    cout << families[n][1] << "\n";
    return 0;
}