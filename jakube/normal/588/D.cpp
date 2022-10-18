#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
#define ADDMOD(x, y) x += (y); if (x >= MOD) x -= MOD;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long result = 0;

    // first compute without broken
    long long L = l - (l % n);
    vector<int> b(a);
    vector<int> c(a.begin(), a.begin() + (l % n));
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    
    vector<long long> dp(n, 0), dp_broken(l % n, 0);
    dp[0] = 1;

    long long times = L / n;
    long long times2 = times + (l % n > 0);
    for (int i = 0; i < k; i++) {
        int idx = 0;
        for (int j = 0; j < dp_broken.size(); j++) {
            dp_broken[j] = j ? dp_broken[j-1] : 0;
            while (idx < n && b[idx] <= c[j]) {
                ADDMOD(dp_broken[j], dp[idx]);
                idx++;
            }
        }

        if (i < times2) {
            result = (result + accumulate(dp_broken.begin(), dp_broken.end(), 0LL)) % MOD;
        }

        idx = 0;
        vector<long long> dp2(n, 0);
        for (int j = 0; j < n; j++) {
            if (j) dp2[j] = dp2[j-1];
            while (idx < n && b[idx] <= b[j]) {
                ADDMOD(dp2[j], dp[idx]);
                idx++;
            }
        }
        dp = dp2;

        if (i < times) {
            result = (result + (accumulate(dp.begin(), dp.end(), 0LL) % MOD) * ((times - i) % MOD)) % MOD;
        }
    }

    cout << result << endl;
}