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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        ll z = 0;
        for (int i=0; i<n-1; i++) {
            z = max(z, max(a[i], a[i+1]) * 1ll * min(a[i], a[i+1]));
        }
        cout << z << '\n';
    }
}