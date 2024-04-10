#include <bits/stdc++.h>

#ifndef OCT_MIAD_HPP
#define OCT_MIAD_HPP

#define templ template <typename Type1, typename Type2>
templ inline Type1 Min(Type1 x, Type2 y) { return x < y ? x : y; }
templ inline Type1 Max(Type1 x, Type2 y) { return y < x ? x : y; }
templ inline Type1 &Mid(Type1 &x, Type2 y) { return x < y ? x : x = y; }
templ inline Type1 &Mad(Type1 &x, Type2 y) { return y < x ? x : x = y; }
#undef templ

#define templ template <typename Type1, typename Type2, typename... Args>
templ inline Type1 Min(Type1 x, Type2 y, Args... args) { return Min(Min(x, y), args...); }
templ inline Type1 Max(Type1 x, Type2 y, Args... args) { return Max(Max(x, y), args...); }
templ inline Type1 &Mid(Type1 &x, Type2 y, Args... args) { return Mid(Mid(x, y), args...); }
templ inline Type1 &Mad(Type1 &x, Type2 y, Args... args) { return Mad(Mad(x, y), args...); }
#undef templ

#endif

using int64 = long long;

const int N = 300005;
const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int cc[255];
int n, m, p, q, pn[2];
int px[2][N], py[2][N];

std::string Map[N];

std::vector<int64> Dis[2][N];

inline int Dir(int x, int y) { return (x ^ y) == 2 ? 0 : std::abs(x - y) & 1 ? p : q; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    cc['L'] = 0, cc['U'] = 1, cc['R'] = 2, cc['D'] = 3;
    std::cin >> n >> m >> p >> q;
    for (int i = 1; i <= n; ++i) std::cin >> Map[i], Map[i] = '#' + Map[i] + '#';
    Map[0].resize(m + 2);
    for (int i = 0; i <= m + 1; ++i) Map[0][i] = '#';
    Map[n + 1] = Map[0];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (Map[i][j] == '.') {
                int c = (i ^ j) & 1;
                px[c][pn[c]] = i, py[c][pn[c]] = j, ++pn[c];
            }
        }
    }
    Dis[0][0] = Dis[1][0] = std::vector<int64>(m + 2, INT64_MAX / 2);
    for (int i = 1; i <= n + 1; ++i) Dis[0][i] = Dis[1][i] = Dis[0][0];
    for (int c = 0; c < 2; ++c) {
        std::priority_queue<std::tuple<int64, int, int> > Que;
        for (int i = 0; i < pn[c]; ++i) Que.emplace(Dis[c][px[c][i]][py[c][i]] = 0, px[c][i], py[c][i]);
        while (!Que.empty()) {
            auto [D, x, y] = Que.top();
            if (Que.pop(), (D = -D) != Dis[c][x][y]) continue;
            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i][0], ny = y + d[i][1];
                if (Map[nx][ny] == '#' || Map[nx][ny] == '.') continue;
                int Di = cc[Map[nx][ny]], Dr = Dir(i, Di);
                int nnx = nx + d[Di][0], nny = ny + d[Di][1];
                if (Dr && D + Dr < Dis[c][nnx][nny]) Que.emplace(-(Dis[c][nnx][nny] = D + Dr), nnx, nny);
            }
        }
    }
    int64 Ans = INT64_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            Mid(Ans, Dis[0][i][j] + Dis[1][i][j + 1]);
            Mid(Ans, Dis[0][i][j] + Dis[1][i + 1][j]);
            Mid(Ans, Dis[1][i][j] + Dis[0][i][j + 1]);
            Mid(Ans, Dis[1][i][j] + Dis[0][i + 1][j]);
        }
    }
    std::cout << (Ans >= Dis[0][0][0] ? -1 : Ans) << '\n';
    return 0;
}