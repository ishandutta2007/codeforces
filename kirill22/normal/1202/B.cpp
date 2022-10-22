#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int dp[10][10][10];
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int j = 0; j < 10; j++) {
                dp[x][y][j] = -1;
            }
        }
    }
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    for (int k2 = 0; k2 < 10; k2++) {
                        if (k + k2 == 0) {
                            continue;
                        }
                        int res = (x * k + y * k2) % 10;
                        if (dp[x][y][res] == -1) {
                            dp[x][y][res] = k + k2;
                        }
                        else {
                            dp[x][y][res] = min(dp[x][y][res], k2 + k);
                        }
                    }
                }
            }
        }
    }
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            int ans = 0;
            bool f = true;
            for (int i = 1; i < n; i++) {
                int x2 = (s[i] - s[i - 1] + 10) % 10;
                if (dp[x][y][x2] == -1) {
                    f = false;
                    break;
                }
                ans += dp[x][y][x2] - 1;
            }
            if (f) {
                cout << ans << " ";
            }
            else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
}