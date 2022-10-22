#include <bits/stdc++.h>

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
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> used(n, vector<int> (n));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!used[i][j]) {
                    int x = 0, y = 0, vi = i, vj = j;
                    while (!used[vi][vj]) {
                        if (a[vi][vj] == '1') {
                            x++;
                        } else {
                            y++;
                        }
                        used[vi][vj] = 1;
                        swap(vi, vj);
                        vi = n - vi - 1;
                    }
                    ans += min(x, y);
                }
            }
        }
        cout << ans << '\n';
    }
}