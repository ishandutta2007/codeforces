#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);
    i64 suma = 0, sumb = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        suma += a[i];
        sumb += b[i];
    }

    if (suma <= p) {
        puts("-1");
        return 0;
    }

    const double eps = 1e-8;
    double left = 0;
    double right = double(sumb) / (suma - p);
    for (int it = 0; it < 100; ++it) {
        double center = (left + right) / 2;
        double tocharge = 0;
        for (int i = 0; i < n; ++i) {
            const double need = center * a[i] - b[i];
            if (need > eps) {
                tocharge += need / p;
            }
        }
        if (tocharge < center + eps) {
            left = center;
        } else {
            right = center;
        }
    }

    cout.precision(12);
    cout << fixed << (left + right) / 2 << '\n';

    return 0;
}