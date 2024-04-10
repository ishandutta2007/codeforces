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
        int ans = arr[0] * arr[1];
        for (int i = 1; i < n; ++i) {
            ans = max(ans, arr[i] * arr[i - 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}