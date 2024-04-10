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
        int n, f=0;
        string a[3], p, q;
        cin >> n >> a[0] >> a[1] >> a[2];
        char d[3], t;

        auto dom = [&](const string& s) {
            return count(begin(s), end(s), '0') >= n ? '0' : '1';
        };

        for (int i=0; i<3; i++) {
            d[i] = dom(a[i]);
        }

        for (int i=0; i<3 && !f; i++) {
            for (int j=i+1; j<3 && !f; j++) {
                if (d[i] == d[j]) {
                    p = a[i];
                    q = a[j];
                    t = d[i];
                    break;
                }
            }
        }

        int i=0, j=0;
        while (i < 2*n || j < 2*n) {
            while (i < 2*n && p[i] != t) {
                cout << p[i];
                i++;
            }

            while (j < 2*n && q[j] != t) {
                cout << q[j];
                j++;
            }

            if (i < 2*n && j < 2*n && p[i] == q[j] && p[i] == t) {
                cout << t;
                i++;
                j++;
            } else {
                while (i < 2*n) cout << p[i++];
                while (j < 2*n) cout << q[j++];
                break;
            }
        }
        cout << '\n';
    }
}