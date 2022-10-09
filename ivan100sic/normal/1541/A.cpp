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
        int n, k;
        cin >> n;
        if (n % 2) {
            cout << "2 3 1";
            k = 4;
        } else {
            cout << "2 1";
            k = 3;
        }
        for (; k<n; k+=2) {
            cout << ' ' << k+1 << ' ' << k;
        }
        cout << '\n';
    }
}