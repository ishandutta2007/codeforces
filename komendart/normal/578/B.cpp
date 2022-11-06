#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pref(n + 2, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] | a[i - 1];
        suf[n + 1 - i] = suf[n + 2 - i] | a[n - i];
    }

    int mul = 1;
    for (int i = 0; i < k; i++) mul *= x;

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, pref[i] | (a[i] * mul) | suf[i + 2]);
    }
    cout << result << '\n';
}