#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T --> 0) {
        long long x, y, p, q;
        cin >> x >> y >> p >> q;
        
        if (x * q  == y * p) {
            cout << 0 << '\n';
        } else if (p == 1 && q == 1) {
            if (x == y) {
                cout << 0 << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (p == 0) {
            cout << -1 << '\n';
        } else {
            long long L = 0;
            long long R = 2e9;

            while (L + 1 < R) {
                long long M = (L + R) / 2;

                long long P = p * M;
                long long Q = q * M;
                long long steps = Q - y;
                long long diff = P - x;
                if (diff >= 0 && diff <= steps) {
                    R = M;
                } else {
                    L = M;
                }
            }
            cout << (q * R - y) << '\n';
        }
    }
}