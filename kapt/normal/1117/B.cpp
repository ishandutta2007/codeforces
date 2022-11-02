#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
int arr[MAXN];

main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int x = arr[n - 1], y = arr[n - 2];
    int ans = 0;
    ans += (m / (k + 1)) * (x * k + y);
    ans += (m % (k + 1)) * x;
    cout << ans;
    return 0;
}