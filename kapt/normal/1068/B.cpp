#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int n;
    cin >> n;
    int k = sqrt(n);
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        if (n % i == 0) {
            ans++;
        }
    }
    ans *= 2;
    if (k * k == n) {
        ans--;
    }
    cout << ans;
    return 0;
}