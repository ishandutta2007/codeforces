#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 5e5;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            ans += arr[i];
            continue;
        }
        arr[i] = max((int64_t)0, min(arr[i + 1] - 1, arr[i]));
        // cout << arr[i] << endl;
        ans += arr[i];
    }
    cout << ans;
    return 0;
}