#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 998244353;

main() {
    int n, m;
    cin >> n >> m;
    int ans = 1;
    int cur = 1;
    int sum = 0;
    vector<int> used(n + 1, 0);
    used[1] = 1;
    int all = 1;
    for (int i = 1; i <= n; ++i) {
        all = (all * (m % MOD)) % MOD;
        if (ans != 0) {
            if (!used[i]) {
                cur *= i;
                for (int j = i * i; j <= n; j += i) {
                    used[j] = 1;
                }
            }
            int k = (m / cur) % MOD;
            ans = (ans * k) % MOD;
        }
        /// cout << cur << endl;
        sum += all - ans;
        sum = (sum % MOD + MOD) % MOD;
    }
    cout << sum;
    return 0;
}