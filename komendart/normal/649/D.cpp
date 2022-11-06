#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            sum += cnt[a[i]];
            cnt[a[i]] = 0;
            if (i >= sum) ans++;
        }
    }

    cout << ans << '\n';
}