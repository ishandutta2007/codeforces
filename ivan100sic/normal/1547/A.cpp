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
        int ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> cx >> cy >> bx >> by;


        bool ok = true;
        if (ax == bx && bx == cx && (ay <= by && by <= cy || ay >= by && by >= cy)) {
            ok = false;
        }

        if (ay == by && by == cy && (ax <= bx && bx <= cx || ax >= bx && bx >= cx)) {
            ok = false;
        }

        if (ok) {
            cout << abs(cx-ax) + abs(cy-ay) << '\n';
        } else {
            cout << abs(cx-ax) + abs(cy-ay) + 2 << '\n';
        }
    }
}