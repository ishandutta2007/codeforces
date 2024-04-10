#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e6;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        arr[b - i + n] += b;
    }
    int ans = -1;
    for (int i = 0; i < MAXN; ++i) {
        ans = max(ans, arr[i]);
    }
    cout << ans;
    return 0;
}