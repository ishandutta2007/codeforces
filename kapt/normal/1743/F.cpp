#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

const int MAXN = 3e5 + 100;
vector<int> open[MAXN], close[MAXN];

main() {
    int n;
    cin >> n;
    vector<array<int, 3>> event;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        open[l].push_back(i);
        close[r].push_back(i);
    }
    vector<int64_t> power2(n, 1), power3(n, 1);
    for (int i = 1; i < n; ++i) {
        power2[i] = (power2[i - 1] * 2) % MOD;
        power3[i] = (power3[i - 1] * 3) % MOD;
    }
    sort(event.begin(), event.end());
    set<int> st;
    int64_t ans = 0;
    for (int i = 0; i < MAXN; ++i) {
        for (auto j : open[i]) {
            st.insert(j);
        }
        if (!st.empty()) {
            auto it = st.end();
            it--;
            int x = *it;
            if (x == 0) {
                ans += power2[n - 1];
            } else {
                ans += power3[x - 1] * power2[n - x];
            }
            ans %= MOD;
        }
        for (auto j : close[i]) {
            st.erase(j);
        }
    }
    cout << ans;
    return 0;
}