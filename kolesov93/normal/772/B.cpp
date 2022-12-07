#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i =0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    x.push_back(x[0]);
    y.push_back(y[0]);
    x.push_back(x[1]);
    y.push_back(y[1]);
    double ans = 1e300;
    for (int i = 0; i < n; ++i) {
        i64 A = y[i+2] - y[i];
        i64 B = x[i] - x[i+2];
        i64 C = -A * x[i] - B * y[i];
        double dist = fabs((A * x[i+1] + B * y[i+1] + C) / sqrt(A * A + B * B));
        if (dist < ans) {
            ans = dist;
        }
    }

    cout.precision(12);
    cout << fixed << ans / 2 << '\n';

    return 0;
}