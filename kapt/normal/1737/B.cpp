#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int sq(int x) {
    int ans = sqrt(x);
    ans = max((int64_t)0, ans - 2);
    while ((ans + 1) * (ans + 1) <= x) {
        ans++;
    }
    return ans;
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int l, r;
        cin >> l >> r;
        int ans = (sq(r + 1) - sq(l)) * 3;
        int n = sq(r + 1);
        if (n * n <= r && n * n >= l) ans++;
        if (n * n + n <= r && n * n + n >= l) ans++;
        if (n * n + n + n <= r && n * n + n + n >= l) ans++;
        n = sq(l);
        if (sq(l) != sq(r + 1)) {
            if (n * n > r || n * n < l) ans--;
            if (n * n + n > r || n * n + n < l) ans--;
            if (n * n + n + n > r && n * n + n + n < l) ans--;
        }
        cout << ans << endl;
    }
    return 0;
}