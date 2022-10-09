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
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i=0; i<m; i++) cin >> a[i];

        int z = 0;
        for (int i=0; i<m; i++) {
            z += count_if(a.begin(), a.begin() + i, [&](int x) { return x < a[i]; });
        }

        cout << z << '\n';
    }
}