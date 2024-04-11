#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    vector<char> good(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int sum2 = 0;
    for (int i = 0; i < k; i++) {
        int t; cin >> t;
        good[t - 1] = true;
        sum2 += c[t - 1];
    }

    int sum = accumulate(c.begin(), c.end(), 0LL);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (i + n - 1) % n;
        if (good[i]) {
            ans += 2 * c[i] * (sum - sum2);
            ans += c[i] * (sum2 - c[i]);
        } else {
            if (!good[j]) ans += c[i] * c[j];
            if (!good[k]) ans += c[i] * c[k];
        }
    }

    cout << ans / 2 << endl;
}