#include <bits/stdc++.h>
using namespace std;

const int N = 2005, MX = 1E6 + 5;

int n, m, a[N], b[N], c[N], d[N], suf[MX];
int ans = 3 * MX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] <= c[j] && b[i] <= d[j]) {
                suf[d[j] - b[i]] = max(suf[d[j] - b[i]], c[j] - a[i] + 1);
            }
        }
    }
    for (int i = MX - 2; i >= 0; i--) {
        suf[i] = max(suf[i], suf[i + 1]);
        ans = min(ans, i + suf[i]);
    }
    cout << ans;
}