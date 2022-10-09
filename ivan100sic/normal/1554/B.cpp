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
        cin >> n >> k;
        ll z = -1e18;
        vector<int> a(n+1);
        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=max(1, n-200); i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                z = max(z, i*1ll*j - k*(a[i] | a[j]));
            }
        }
        cout << z << '\n';
    }
}