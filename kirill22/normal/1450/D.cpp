#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1);
        int ok = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            g[x].push_back(i);
            ok &= ((int) g[x].size() <= 1);
        }
        string ans(n, '0');
        int l = 0, r = n - 1;
        for (int x = 1; x <= n; x++) {
            int m = (int) g[x].size();
            if (m >= 2) {
                ans[r - l] = '1';
                break;
            }
            if (m == 0) {
                if (r - l + 1 < n) {
                    ans[r - l + 1] = '1';
                }
                break;
            }
            if (m == 1) {
                if (g[x][0] == l) {
                    l++;
                } else if (g[x][0] == r) {
                    r--;
                } else {
                    ans[r - l] = '1';
                    break;
                }
            }
            if (x == n) {
                ans = string(n, '1');
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            if (ans[i] == '1') {
                ans[i + 1] = '1';
            }
        }
        if (ok) {
            ans[0] = '1';
        }
        cout << ans << '\n';
    }
}