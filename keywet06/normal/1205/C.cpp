#include <bits/stdc++.h>
using namespace std;
class Solver {
   private:
    static constexpr int MAX_N = 50;
    static constexpr pair<int, int> moves[] = {{1, 0}, {0, 1}};
    int n;
    int a[MAX_N][MAX_N];
    bool dp[2][MAX_N][MAX_N][MAX_N][MAX_N];
    int b[MAX_N][MAX_N];
    int ask(int x1, int y1, int x2, int y2) {
        cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' '
             << y2 + 1 << endl;
        int ans;
        cin >> ans;
        return ans;
    }

   public:
    Solver() : dp{} {}
    void solve() {
        cin >> n;
        a[0][0] = 1;
        a[0][1] = 0;
        a[n - 1][n - 1] = 0;
        for (int i = 2; i < n; ++i) {
            a[0][i] = a[0][i - 2] ^ 1 ^ ask(0, i - 2, 0, i);
        }
        a[1][2] = a[0][1] ^ 1 ^ ask(0, 1, 1, 2);
        a[1][0] = a[1][2] ^ 1 ^ ask(1, 0, 1, 2);
        for (int i = 2; i < n; ++i) {
            a[i][0] = a[i - 2][0] ^ 1 ^ ask(i - 2, 0, i, 0);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if ((i != 1 || j != 2) && (i != n - 1 || j != n - 1)) {
                    a[i][j] = a[i - 1][j - 1] ^ 1 ^ ask(i - 1, j - 1, i, j);
                }
            }
        }
        for (int cur = 0; cur < 2; ++cur) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    b[i][j] = a[i][j] ^ ((i + j) & 1 & cur);
                }
            }
            queue<tuple<int, int, int, int>> que;
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    dp[cur][x][y][x][y] = true;
                    que.emplace(x, y, x, y);
                    for (auto [dx, dy] : moves) {
                        int to_x = x + dx;
                        int to_y = y + dy;
                        if (to_x < n && to_y < n && b[x][y] == b[to_x][to_y]) {
                            dp[cur][x][y][to_x][to_y] = true;
                            que.emplace(x, y, to_x, to_y);
                        }
                    }
                }
            }
            while (!que.empty()) {
                auto [x1, y1, x2, y2] = que.front();
                que.pop();
                for (auto [dx1, dy1] : moves) {
                    int to_x1 = x1 - dx1;
                    int to_y1 = y1 - dy1;
                    if (to_x1 >= 0 && to_y1 >= 0) {
                        for (auto [dx2, dy2] : moves) {
                            int to_x2 = x2 + dx2;
                            int to_y2 = y2 + dy2;
                            if (to_x2 < n && to_y2 < n &&
                                b[to_x1][to_y1] == b[to_x2][to_y2] &&
                                !dp[cur][to_x1][to_y1][to_x2][to_y2]) {
                                dp[cur][to_x1][to_y1][to_x2][to_y2] = true;
                                que.emplace(to_x1, to_y1, to_x2, to_y2);
                            }
                        }
                    }
                }
            }
        }
        for (int x1 = 0; x1 < n; ++x1) {
            for (int y1 = 0; y1 < n; ++y1) {
                for (int x2 = x1; x2 < n; ++x2) {
                    for (int y2 = y1; y2 < n; ++y2) {
                        if (x1 + y1 + 2 <= x2 + y2 &&
                            dp[0][x1][y1][x2][y2] != dp[1][x1][y1][x2][y2]) {
                            int ans =
                                (ask(x1, y1, x2, y2) == dp[1][x1][y1][x2][y2]);
                            cout << "!" << endl;
                            for (int i = 0; i < n; ++i) {
                                for (int j = 0; j < n; ++j) {
                                    cout << (a[i][j] ^ ((i + j) & 1 & ans));
                                }
                                cout << endl;
                            }
                            return;
                        }
                    }
                }
            }
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}