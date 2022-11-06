#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(5);
    vector<int> b(5);
    for (int i = 1; i <= n; i++) a[i % 5]++;
    for (int i = 1; i <= m; i++) b[i % 5]++;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i + j == 5 || i + j == 0) {
                ans += a[i] * b[j];
            }
        }
    }

    cout << ans << endl;
}