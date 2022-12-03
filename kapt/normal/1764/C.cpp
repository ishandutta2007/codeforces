#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (arr[0] == arr[n - 1]) {
            cout << n / 2 << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] != arr[i - 1]) {
                ans = max(ans, i * (n - i));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}