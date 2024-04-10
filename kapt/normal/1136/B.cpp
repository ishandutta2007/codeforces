#include <bits/stdc++.h>
using namespace std;

main() {
    int n, k;
    cin >> n >> k;
    int ans = n + 1;
    ans += n;
    ans += min(n + k - 2, 2 * n - k - 1);
    cout << ans;
    return 0;
}