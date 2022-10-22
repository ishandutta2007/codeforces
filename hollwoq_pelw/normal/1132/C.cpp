#include <bits/stdc++.h>
using namespace std;

const int MX = 5007;
int l[MX], r[MX];
int a[MX];
int md[MX];
int f[MX];
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
    }
    int ans = 0;
    for (int x = 1; x <= q; x++) {
        memset(a, 0, sizeof(a));
        memset(md, 0, sizeof(md));
        for (int i = 1; i <= q; i++) {
            if (i != x) {
                md[l[i]]++;
                md[r[i] + 1]--;
            }
        }
        int sm = 0;
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            sm += md[i];
            if (sm > 0) {
                tot++;
            }
            f[i] = f[i - 1];
            if (sm == 1) {
                f[i]++;
            }
        }
        for (int y = 1; y <= q; y++) {
            if (x == y) {
                continue;
            }
            int cur = tot - (f[r[y]] - f[l[y] - 1]);
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
    return 0;
}