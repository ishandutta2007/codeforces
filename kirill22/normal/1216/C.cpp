#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, x1, y1;
    int x2, y2, x3, y3;
    int x4, y4, x5, y5;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;
    for (double t = x; t <= x1; t += 0.5) {
        int a = -1, b = -1, c = -1, d = -1;
        if (x2 <= t && t <= x3) {
            a = y2, b = y3;
        }
        if (x4 <= t && t <= x5) {
            c = y4, d = y5;
        }
        int tmp = y;
        if (a <= tmp && b >= tmp) {
            tmp = b;
        }
        if (c <= tmp && d >= tmp) {
            tmp = d;
        }
        if (a <= tmp && b >= tmp) {
            tmp = b;
        }
        if (tmp < y1) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}