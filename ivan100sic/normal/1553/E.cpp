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
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i], a[i]--;

        map<int, int> mp;
        for (int i=0; i<n; i++) {
            mp[(i-a[i]+n) % n]++;
        }

        vector<int> sol;

        for (auto [k, v] : mp) {
            if (v >= n-2*m) {
                // mozda?
                // derange?
                vector<int> b(n);
                for (int i=0; i<n; i++) {
                    b[i] = a[(i+k+n)%n];
                }

                // swaps?
                vector<bool> vis(n);
                int swaps = 0;
                for (int i=0; i<n; i++) {
                    if (!vis[i]) {
                        int c = 1;
                        vis[i] = 1;
                        for (int j=b[i]; !vis[j]; j=b[j]) vis[j] = 1, c++;
                        swaps += c - 1;
                    }
                }

                // cerr << "test rot " << k << " has swaps " << swaps << '\n';
                // for (int x : b) cerr << x << ' ';
                // cerr << '\n';

                if (swaps <= m) {
                    sol.push_back(k);
                }
            }
        }

        cout << sol.size();
        for (int k : sol) cout << ' ' << k;
        cout << '\n';
    }
}