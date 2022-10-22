#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, x, m;
        cin >> n >> x >> m;
        int lx = x, rx = x;
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            if (r >= lx && l <= rx) {
                lx = min(lx, l);
                rx = max(rx, r);
            }
        }

        cout << rx - lx + 1 << "\n";
    }
}