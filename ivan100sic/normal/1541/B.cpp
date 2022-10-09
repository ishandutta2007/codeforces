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
        int n, z = 0;
        cin >> n;
        vector<int> a(n+1), b(2*n+1);
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            b[a[i]] = i;
        }

        for (int x=1; x<=2*n; x++) {
            for (int p=x, y=1; p<=2*n; p+=x, y++) {
                if (b[x] && b[y] && b[x] + b[y] == p && b[x] < b[y]) {
                    z++;
                }
            }
        }

        cout << z << '\n';
    }
}