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
        int ans = -1;
        sort(arr.begin(), arr.end());
        for (int i = 2; i < n; ++i) {
            ans = max(ans, arr[i] - arr[i - 1] + arr[i] - arr[0]);
        }
        for (int i = 0; i + 2 < n; ++i) {
            ans = max(ans, arr[i + 1] - arr[i] + arr[n - 1] - arr[i]);
        }
        cout << ans << endl;
    }
    return 0;
}