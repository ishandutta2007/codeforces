#include <bits/stdc++.h>
using namespace std;

int n, k, a[100005], ans, idx;

main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; i = idx - 1) {
        for (idx = i; idx < n && a[idx] - a[i] <= k; ++idx);
        if (i + 1 == idx)
            cout << -1, exit(0);
        ++ans;
    }
    cout << ans;
}