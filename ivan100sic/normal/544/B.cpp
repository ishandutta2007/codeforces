// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, k;
    cin >> n >> k;
    if (k <= (n*n+1) / 2) {
        cout << "YES\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << ((i+j) % 2 == 0 && (k-- > 0) ? 'L' : 'S');
            }
            cout << '\n';
        }
    } else {
        cout << "NO\n";
    }
}