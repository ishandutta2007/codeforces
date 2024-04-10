#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint t, n, p, k;
llint a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> p >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        llint sum = 0, res = 0;
        for (int i = 0; i < k; i++) {
            if (i > 0) sum += a[i];
            llint tot = sum, br = i;
            if (tot > p) break;
            for (int j = i + k; j <= n; j += k) {
                if (tot + a[j] > p) break;
                tot += a[j];
                br += k;
            }
            res = max(res, br);
        }
        cout << res << '\n';
    }
    return 0;
}