// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int compute(int x, int sgn, int y, int k) {
    if (x == 0 && y == 0) {
        return 0;
    }
    int z = compute(x / k, sgn, y / k, k);
    int r = (x + y * sgn) % k;
    if (r < 0) r += k;
    return z * k + r;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int sgn = 1, offs = 0;
        for (int x=0; x<n; x++) {
            int guess = compute(offs, sgn, x, k);
            cout << guess << '\n' << flush;
            int r;
            cin >> r;
            if (r == 1) {
                break;
            }
            sgn *= -1;
            offs = compute(guess, -1, offs, k);
        }
    }
}