#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c % 2 == 0) {
            x++;
        } else {
            y++;
        }
    }
    vector<vector<vector<int>>> dp(x + 1, vector<vector<int>> (y + 1, vector<int> (2, -1)));
    function<int(int, int, int)> solve = [&] (int x, int y, int z) {
        if (!x && !y) {
            return (int) (z == 0);
        }
        if (dp[x][y][z] != -1) {
            return dp[x][y][z];
        }
        int sum = y % 2;
        int res = 0;
        if (x) {
            int need = (sum + 1 - z) % 2;
            if (!solve(x - 1, y, need)) {
                res = 1;
            }
        }
        if (y) {
            int need = (sum + 3 - z) % 2;
            if (!solve(x, y - 1, need)) {
                res = 1;
            }
        }
        return dp[x][y][z] = res;
    };
    cout << (solve(x, y, 0) ? "Alice" : "Bob") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}