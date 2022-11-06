#include <bits/stdc++.h>

using namespace std;

#define double long double
#define int long long

void update(double &left, double &right, int x, int vx, int x1, int x2) {
    if (vx == 0) {
        if (x <= x1 || x >= x2) left = right + 1;
        return;
    }
    if (vx < 0) {
        swap(x1, x2);
    }
    left = max(left, (x1 - x) * 1.0L / vx);
    right = min(right, (x2 - x) * 1.0L / vx);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed; cout.precision(12);

    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double left = 0, right = 1e18;
    for (int i = 0; i < n; ++i) {
        int x, y, vx, vy; cin >> x >> y >> vx >> vy;
        update(left, right, x, vx, x1, x2);
        update(left, right, y, vy, y1, y2);
    }
    if (left < right - 1e-10) {
        cout << left;
    } else {
        cout << -1;
    }
}