#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        int x, y, x1, y1, x2, y2;
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        bool f = 1;
        int k = x + b - a;
        if (k > x2 || k < x1) f = 0;
        if (x1 == x2 && a != 0) f = 0;
        k = y + d - c;
        if (k > y2 || k < y1) f = 0;
        if (y1 == y2 && c != 0) f = 0;
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}