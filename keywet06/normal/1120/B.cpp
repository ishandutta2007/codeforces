#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 200005;

char a[N], b[N];

int64 n, d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    d[0] = b[0] - a[0];
    for (int i = 1; i < n - 1; ++i) d[i] = b[i] - (d[i - 1] + a[i]);
    if (a[n - 1] + d[n - 2] != (int)b[n - 1]) {
        cout << "-1\n";
    } else {
        int64 c = 0;
        for (int i = 0; i < n - 1; ++i) c += abs(d[i]);
        cout << c << "\n";
        c = min(c, 100000LL);
        int p = 0, r = 0;
        while (c > 0) {
            while (d[p] == 0) ++p, ++r;
            while (d[r] < 0 && a[r + 1] == '0' || d[r] > 0 && a[r + 1] == '9') ++r;
            cout << r + 1 << " " << (d[r] > 0 ? 1 : -1) << "\n";
            a[r] += (d[r] > 0 ? 1 : -1);
            a[r + 1] += (d[r] > 0 ? 1 : -1);
            d[r] -= (d[r] > 0 ? 1 : -1);
            r = max(r - 1, p);
            --c;
        }
    }
    return 0;
}