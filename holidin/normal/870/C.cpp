#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k, j, i, q, a;
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> a;
        if (a < 4) {
            cout << -1 << "\n";
            continue;

        }
        if (a == 15) {
            cout << 2 << "\n";
            continue;
        }
        if (a == 19) {
            cout << 3 << "\n";
            continue;
        }
        if (a % 4 == 0) {
            cout << a/4 << "\n";
            continue;
        }
        if (a % 4 == 2) {
            cout << (a - 6) /4 + 1 << "\n";
            continue;
        }
        if (a % 4 == 1) {
            if (a < 9) {
                 cout << -1 << "\n";
                 continue;
            }
            cout << (a - 9) /4 + 1 << "\n";
            continue;
        }

        if (a % 4 == 3) {
            if (a < 15) {
                 cout << -1 << "\n";
                 continue;
            }
            cout << (a - 15) /4 + 2 << "\n";
            continue;
        }
    }
}