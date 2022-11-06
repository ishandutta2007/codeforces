#include <bits/stdc++.h>

using namespace std;

const int maxw = 1e4 + 5;

int n, k;
int cnt[maxw];

void zero() {
    long long ans = 0;
    for (int i = 0; i < maxw; ++i) {
        ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        ++cnt[t];
    }

    if (k == 0) {
        zero();
        return 0;
    }

    long long ans = 0;
    for (int i = 0; i < maxw; ++i) {
        for (int j = i + 1; j < maxw; ++j) {
            if (__builtin_popcount(i ^ j) == k) {
                ans += 1LL * cnt[i] * cnt[j];
            }
        }
    }
    cout << ans << '\n';
}