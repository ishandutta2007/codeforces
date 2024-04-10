#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            a[i] = min(a[i], a[i - 1] * 2);
        }
    }
    auto cost = [&] (int l) {
        long long ans = 0;
        for (int j = 0; j < 31; j++) {
            if (l >> j & 1) {
                int i = min(n - 1, j);
                ans += a[i] * 1ll * (1 << (j - i));
            }
        }
        return ans;
    };
    long long ans = cost(l);
    for (int j = 0; j < 31; j++) {
        if (!(l >> j & 1)) {
            l -= l % (1ll << j);
            l += (1ll << j);
            ans = min(ans, cost(l));
        }
    }
    cout << ans;
}