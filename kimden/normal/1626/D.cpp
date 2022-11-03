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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> prv(n, -1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int p = -1;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i - 1]) {
                p = i - 1;
            }
            prv[i] = p;
        }
        prv.push_back(n - 1);
        int ans = 100 * n;
        for (int q = 0; q <= 18; ++q) {
            for (int w = 0; w <= 18; ++w) {
                for (int e = 0; e <= 18; ++e) {
                    int ptr = -1;
                    ptr = min(n - 1, ptr + (1 << q));
                    ptr = prv[ptr + 1];
                    ptr = min(n - 1, ptr + (1 << w));
                    ptr = prv[ptr + 1];
                    ptr = min(n - 1, ptr + (1 << e));
                    ptr = prv[ptr + 1];
                    if (ptr == n - 1) {
                        ans = min(ans, (1 << q) + (1 << w) + (1 << e) - n);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}