// bonjour
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, l;
        cin >> n >> l;
        vector<vector<int>> a(30, vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            for (int j = 0; j < 30; ++j) {
                ++a[j][(x >> j) & 1];
            }
        }
        int ans = 0;
        for (int j = 0; j < 30; ++j) {
            if (a[j][1] * 2 >= n) {
                ans ^= (1 << j);
            }
        }
        cout << ans << "\n";
    }
}