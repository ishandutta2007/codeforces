#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int dp[100][360];
int block[100][360];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(dp, 0, sizeof dp);
        memset(block, 0, sizeof block);
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            char op;
            cin >> op;
            if (op == 'C') {
                int r, d1, d2;
                cin >> r >> d1 >> d2;
                r *= 2;
                for (int d = d1; d != d2; d = (d + 1) % 360) {
                    dp[r][d] = -1;
                }
            } else {
                int r1, r2, d;
                cin >> r1 >> r2 >> d;
                r1 *= 2, r2 *= 2;
                for (int r = r1; r <= r2; r++) {
                    block[r][d] = 1;
                }
            }
        }
        queue<pair<int, int>> que;
        que.push({0, 0});
        while (!que.empty()) {
            auto q = que.front();
            que.pop();
            if (q.first <= 40 && !dp[q.first + 1][q.second]) {
                dp[q.first + 1][q.second] = 1;
                que.push({q.first + 1, q.second});
            }
            if (q.first != 0 && !dp[q.first - 1][q.second]) {
                dp[q.first - 1][q.second] = 1;
                que.push({q.first - 1, q.second});
            }
            int pre = (q.second + 359) % 360;
            int nxt = (q.second + 1) % 360;
            if (block[q.first][q.second] == 0 && !dp[q.first][pre]) {
                dp[q.first][pre] = 1;
                que.push({q.first, pre});
            }
            if (block[q.first][nxt] == 0 && !dp[q.first][nxt]) {
                dp[q.first][nxt] = 1;
                que.push({q.first, nxt});
            }
        }
        if (dp[41][0]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}