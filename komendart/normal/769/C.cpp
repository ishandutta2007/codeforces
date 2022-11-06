#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

const vector< pair<int, int> > directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
const string lexdir = "DLRU";

int n, m, k;
int dist[maxn][maxn];
char used[maxn][maxn];
char empty[maxn][maxn];

bool fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

void bfs(int r0, int c0) {
    deque< pair<int, int> > q;
    q.push_back({r0, c0});
    used[r0][c0] = true;
    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop_front();
        for (auto p: directions) {
            int rn, cn;
            rn = r + p.first;
            cn = c + p.second;
            if (empty[rn][cn] && !used[rn][cn]) {
                used[rn][cn] = true;
                dist[rn][cn] = dist[r][c] + 1;
                q.push_back({rn, cn});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    int r0, c0;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            if (s[j - 1] == 'X') {
                r0 = i, c0 = j;
            }
            if (s[j - 1] != '*') {
                empty[i][j] = true;
            }
        }
    }

    bfs(r0, c0);
    string ans;
    int r = r0, c = c0;
    for (int d = 0; d < k; ++d) {
        for (int i = 0; i < 4; ++i) {
            int rn = r + directions[i].first;
            int cn = c + directions[i].second;
            if (empty[rn][cn] && dist[rn][cn] <= k - d - 1) {
                ans += lexdir[i];
                r = rn;
                c = cn;
                break;
            }
        }
        if (ans.size() == d) {
            fail();
        }
    }
    cout << ans << '\n';
}