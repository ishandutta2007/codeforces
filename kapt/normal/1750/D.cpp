#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 32e3;

int f(int m, int t) {
    int t1 = t;
    vector<int> prm;
    for (int i = 2; i * i <= t; ++i) {
        if (t % i) continue;
        prm.push_back(i);
        while (t % i == 0) t /= i;
    }
    if (t != 1) {
        prm.push_back(t);
    }
    if (t1 <= MAXN) {
        int ans = 0;
        for (int i = 1; i <= m % t1; ++i) {
            if (__gcd(i, t1) == 1) {
                ans++;
            }
        }
        int phi = t1 * (m / t1);
        for (int p : prm) {
            phi -= phi / p;
        }
        return ans + phi;
    }
    int sz = prm.size();
    assert(sz <= 9);
    int ans = 0;
    for (int mask = 0; mask < (1 << sz); ++mask) {
        int c = 1, mlt = 1;
        for (int i = 0; i < sz; ++i) {
            if (mask & (1 << i)) {
                c *= -1;
                mlt *= prm[i];
            }
        }
        ans += c * (m / mlt);
    }
    return ans;
}

const int MOD = 998244353;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] % arr[i] != 0) {
                ans = 0;
            }
        }
        if (ans == 0) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] % arr[i] != 0) {
                ans = 0;
            } else {
                ans = (ans * f(m / arr[i], arr[i - 1] / arr[i])) % MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}