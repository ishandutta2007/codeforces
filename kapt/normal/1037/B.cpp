#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int l = -1, r = n;
    while (r - l != 1) {
        int m = (l + r) / 2;
        if (arr[m] <= s) {
            l = m;
        } else {
            r = m;
        }
    }
    if (arr[n / 2] == s) {
        cout << 0;
        return 0;
    }
    if (l == n / 2) {
        cout << s - arr[n / 2];
        return 0;
    }
    int ans = 0;
    if (l > n / 2) {
        for (int i = n / 2; i <= l; ++i) {
            ans += s - arr[i];
        }
        cout << ans;
    } else {
        for (int i = r; i <= n / 2; ++i) {
            ans += arr[i] - s;
        }
        cout << ans;
    }
    return 0;
}