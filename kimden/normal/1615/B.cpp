#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int a[20][400400];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i < 400000; ++i) {
        for (int j = 0; j < 20; ++j) {
            a[j][i] = a[j][i - 1];
            if ((i >> j) & 1) {
                ++a[j][i];
            }
        }
    }
    while (t--) {
        int l, r;
        cin >> l >> r;
        --l;
        int len = r - l;
        int ans = len;
        for (int u = 0; u < 20; ++u) {
            ans = min(ans, len - a[u][r] + a[u][l]);
        }
        cout << ans << "\n";
    }
    
}