#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t --> 0) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << "1 1" << endl;
        } else {
            bool found = false;
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    // n - a == d
                    // n + a == x / d
                    // 2 * n = d + x / d
                    int r = d + x / d;
                    if (r % 2) continue;
                    int n = r / 2;
                    int a = n - d;
                    if (a == 0) continue;
                    int m = n / a;
                    if (m <= n / (a + 1)) continue;
                    cout << n << " " << m << endl;
                    found = true;
                    break;
                }
            }
            if (!found) 
                cout << -1 << endl;
        }
    }
}