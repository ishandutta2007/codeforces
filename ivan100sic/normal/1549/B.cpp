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
        int n, c = 0;
        string a, b;
        cin >> n >> a >> b;
        for (int i=0; i<n; i++) {
            if (b[i] == '1') {
                if (i > 0 && a[i-1] == '1') {
                    c++;
                    a[i-1] = '0';
                } else if (a[i] == '0') {
                    c++;
                } else if (i+1 < n && a[i+1] == '1') {
                    c++;
                    a[i+1] = '0';
                }
            }
        }
        cout << c << '\n';
    }
}