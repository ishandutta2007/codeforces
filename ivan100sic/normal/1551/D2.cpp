// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool moze(int n, int m, int k) {
    int maxhor = n*(m/2);
    int maxver = m*(n/2);

    return k <= maxhor && n*m/2 - k <= maxver && k % 2 == maxhor % 2;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (!moze(n, m, k)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";

        bool transp = false;
        if (n % 2) {
            transp = 1;
            swap(n, m);
            k = n*m/2 - k;
        }

        vector<string> a(n, string(m, '.'));
        for (int j=0; j+1<m; j+=2) {
            for (int i=0; i<n; i++) {
                if (k > 0) {
                    k--;
                    a[i][j] = a[i][j+1] = (i%4+j%4*4)+'a';
                }
            }
        }
        for (int i=0; i+1<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == '.' && a[i+1][j] == '.') {
                    a[i][j] = a[i+1][j] = (i%4+j%4*4)+'a';
                }
            }
        }

        if (transp) {
            for (int j=0; j<m; j++) {
                for (int i=0; i<n; i++) {
                    cout << a[i][j];
                }
                cout << '\n';
            }

        } else {
            for (string s : a) cout << s << '\n';
        }
    }
}