#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
double l, v1, v2;

bool f(double time) {
    if (l <= v1 * time) return true;
    double cur = 0;
    double place = 0;
    for (int i = n; ; i -= k) {
        double t = (place - v1 * cur) / (v1 + v2);
        cur += t;
        place -= v2 * t;
        if (cur > time) return false;
        if (i <= k) {
            cur += (l - place) / v2;
            break;
        }
        double x = (l - place - v1 * (time - cur)) / (v2 - v1);
        if (x < 0 || x > time - cur) return false;
        cur += x;
        place += v2 * x;
    }
    return cur <= time;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed; cout.precision(10);

    cin >> n >> l >> v1 >> v2 >> k;

    double left = 0, right = 2e9;
    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        if (f(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << left << endl;
}