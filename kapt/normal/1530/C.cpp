#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int a[MAXN], b[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a, a + n); reverse(a, a + n);
        sort(b, b + n); reverse(b, b + n);
        int l = n - 1, r = 4 * n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            int k = min(n, m - m / 4);
            int sa = 0, sb = 0;
            for (int i = 0; i < k; ++i) {
                sb += b[i];
            }
            k = max(0, n - m / 4);
            for (int i = 0; i < k; ++i) {
                sa += a[i];
            }
            sa += 100 * (m - m / 4 - k);
            if (sa >= sb) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r - n << endl;
    }
    return 0;
}