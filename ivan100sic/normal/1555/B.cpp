// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int wr, hr;
        cin >> wr >> hr;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int w, h;
        cin >> w >> h;

        int gx = max(x1, wr - x2);
        int gy = max(y1, hr - y2);

        if (w <= gx || h <= gy) {
            cout << "0\n";
        } else {
            int mgx = wr - (x2-x1);
            int mgy = hr - (y2-y1);

            if (w > mgx && h > mgy) {
                cout << "-1\n";
            } else {
                int lo = 1e9;
                if (w <= mgx) lo = min(lo, w - gx);
                if (h <= mgy) lo = min(lo, h - gy);
                cout << lo << '\n';
            }
        }
    }
}