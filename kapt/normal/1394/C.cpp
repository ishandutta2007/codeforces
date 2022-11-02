#include <bits/stdc++.h>
using namespace std;

array<int, 2> ans;
int maxx = -1e9, maxy = -1e9, minx = 1e9, miny = 1e9, maxd = -1e9, mind = 1e9;

bool check(int k) {
    int lx = maxx - k;
    int rx = minx + k;
    int ly = maxy - k;
    int ry = miny + k;
    int ld = maxd - k;
    int rd = mind + k;
    if (lx > rx || ly > ry || ld > rd) {
        return false;
    }
    int l = lx - ry;
    int r = rx - ly;
    if (l > rd || r < ld) {
        return false;
    }
    int d = max(ld, l);
    int x = max(lx, ly + d), y = max(lx - d, ly);
    if (x == 0 && y == 0) {
        if (rx == 0) {
            return false;
        }
        x++;
        if (d == min(r, rd)) {
            if (ry == 0) {
                return false;
            }
            y++;
        }
    }
    ans = {x, y};
    return true;
}

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        int x = 0, y = 0;
        cin >> s;
        for (auto ch : s) {
            if (ch == 'B') {
                x++;
            } else {
                y++;
            }
        }
        /// cout << x << " " << y << endl;
        maxx = max(maxx, x);
        maxy = max(maxy, y);
        maxd = max(maxd, x - y);
        minx = min(minx, x);
        miny = min(miny, y);
        mind = min(mind, x - y);
    }
    int l = -1, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        /// cout << m << endl;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    check(r);
    cout << r << endl;
    for (int i = 0; i < ans[0]; ++i) {
        cout << "B";
    }
    for (int i = 0; i < ans[1]; ++i) {
        cout << "N";
    }
    return 0;
}