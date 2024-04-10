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
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        if (b >= 0) {
            cout << n*(a+b) << '\n';
        } else {
            int c = 1;
            for (int i=0; i<n-1; i++) {
                if (s[i] != s[i+1]) {
                    c++;
                }
            }
            cout << n*a + b*((c+2)/2) << '\n';
        }
    }
}