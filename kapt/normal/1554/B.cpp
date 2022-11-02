#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int val = n * (n - 1) - k * (arr[n - 1] | arr[n - 2]);
        for (int i = 1; i <= n; ++i) {
            for (int j = max(i + 1, (val + i - 1) / i); j <= n; ++j) {
                if (i * j - k * (arr[i - 1] | arr[j - 1]) > val) {
                    val = i * j - k * (arr[i - 1] | arr[j - 1]);
                }
            }
        }
        cout << val << "\n";
    }
    return 0;
}