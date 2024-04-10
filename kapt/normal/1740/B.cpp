#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<array<int, 2>> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i][0] >> arr[i][1];
            if (arr[i][0] < arr[i][1]) swap(arr[i][0], arr[i][1]);
        }
        sort(arr.begin(), arr.end());
        int mx = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, arr[i][1]);
            sum += arr[i][0];
        }
        int ans = mx + sum;
        for (int i = 0; i < n; ++i) {
            sum += arr[i][1] - arr[i][0];
            mx = max(mx, arr[i][0]);
            ans = min(ans, mx + sum);
        }
        cout << ans * 2 << endl;
    }
    return 0;
}