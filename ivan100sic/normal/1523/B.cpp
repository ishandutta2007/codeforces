// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    // for (int l=1; l<=10; l++) {
    //     for (int mask=0; mask<(1<<l); mask++) {
    //         complex<int> a(1, 0), b(0, 1);
    //         for (int j=0; j<l; j++) {
    //             if (mask & (1 << j)) {
    //                 a += b;
    //             } else {
    //                 b -= a;
    //             }
    //         }
    //         if (a == complex<int>{-1, 0} && b == complex<int>{0, -1}) {
    //             cout << l << ' ' << mask << '\n';
    //             return 0;
    //         }
    //     }
    // }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
        }

        cout << 3*n << '\n';
        for (int i=1; i<=n; i+=2) {
            for (int x : {1, 0, 0, 1, 0, 0}) {
                cout << x+1 << ' ' << i << ' ' << i+1 << '\n';
            }
        }
    }
}