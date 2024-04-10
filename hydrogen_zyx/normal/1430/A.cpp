#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool f = 1;
        for (int i = 0; i <= n / 7 && f; i++) {
            for (int j = 0; j <= (n - i * 7) / 5 && f; j++) {
                if ((n - i * 7 - j * 5) % 3 == 0) {
                    cout << ((n - i * 7 - j * 5) / 3) << ' ' << j << ' ' << i
                         << endl;
                    f = 0;
                }
            }
        }
        if (f) cout << -1 << endl;
    }
}