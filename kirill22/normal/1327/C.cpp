#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
    }
    string ans = "";
    for (int i = 0; i < m - 1; i++) ans += 'L';
    for (int i = 0; i < n - 1; i++) ans += 'U';
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 1; j < n; j++) ans += 'D';
        }
        else for (int j = 1; j < n; j++) ans += 'U';
        ans += 'R';
    }
    cout << ans.size() << endl;
    cout << ans;
}