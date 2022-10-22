#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i + 1] - a[i];
    }
    k = n - k;
    int ans = 0;
    sort(b.begin(), b.end());
    for (int i = 0; i < k; i++) {
        ans += b[i];
    }
    cout << ans;
}