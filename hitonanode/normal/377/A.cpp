#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for (auto &s : S) cin >> s;

    int s = 0, t = 0;
    int req = -K;
    REP(i, H) REP(j, W) {
        if (S[i][j] == '.') s = i, t = j, S[i][j] = 'X', req++;
    }

    const array<int, 4> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};

    auto dfs = [&](auto &&self, int x, int y) -> void {
        if (!req) return;
        req--;
        S[x][y] = '.';
        REP(d, 4) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 and nx < H and ny >= 0 and ny < W and S[nx][ny] == 'X') {
                self(self, nx, ny);
            }
        }
    };
    dfs(dfs, s, t);

    for (auto s : S) cout << s << '\n';
}