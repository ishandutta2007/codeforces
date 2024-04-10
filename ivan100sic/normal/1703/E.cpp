// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector a(n, vector(n, 0));
        for (int i : ra(0, n)) {
            string s;
            cin >> s;
            for (int j : ra(0, n)) {
                a[i][j] = s[j] == '1';
            }
        }

        int m = n-1;
        int h = (n+1)/2;
        int z = 0;

        int ih = n/2, jh = n/2;
        if (n % 2) {
            ih++;
        }

        for (int i=0; i<ih; i++) {
            for (int j=0; j<jh; j++) {
                int c[2] = {0, 0};
                c[a[i][j]]++;
                c[a[m-j][i]]++;
                c[a[m-i][m-j]]++;
                c[a[j][m-i]]++;

                z += min(c[0], c[1]);
            }
        }

        cout << z << '\n';
    }
    
}