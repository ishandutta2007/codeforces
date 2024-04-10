#include <bits/stdc++.h>

#define mkp std::make_pair
#define fi first
#define se second
#define fro fornt
#define pop pop
#define pob pop_back
#define pus push
#define pub push_back

using pair = std::pair<int, int>;

const int N = 505;

int n, m, x, y, z, c, f;
int a[N][N], b[N][N];

pair p[N];

std::string s[N];

std::map<pair, std::vector<pair> > map;

inline void dfs(pair u) {
    for (pair v : map[u]) {
        if (s[v.fi][v.se] == 'X' || b[v.fi][v.se]) {
            if (b[u.fi][u.se] + b[v.fi][v.se] != 5) return void(f = 1);
            continue;
        }
        b[v.fi][v.se] = 5 - b[u.fi][u.se], dfs(v);
        if (f) return;
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') continue;
            x = (s[i][j - 1] == '.') + (s[i][j + 1] == '.') +
                (s[i - 1][j] == '.') + (s[i + 1][j] == '.');
            if (x & 1) return std::cout << "NO" << '\n', 0;
            if (x == 2) {
                c = 0;
                if (s[i][j - 1] == '.') p[c++] = mkp(i, j - 1);
                if (s[i][j + 1] == '.') p[c++] = mkp(i, j + 1);
                if (s[i - 1][j] == '.') p[c++] = mkp(i - 1, j);
                if (s[i + 1][j] == '.') p[c++] = mkp(i + 1, j);
                map[p[0]].pub(p[1]);
                map[p[1]].pub(p[0]);
                b[i][j] = 5;
            } else if (x == 4) {
                map[mkp(i - 1, j)].pub(mkp(i, j - 1));
                map[mkp(i, j - 1)].pub(mkp(i - 1, j));
                map[mkp(i + 1, j)].pub(mkp(i, j + 1));
                map[mkp(i, j + 1)].pub(mkp(i + 1, j));
                b[i][j] = 10;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!b[i][j] && s[i][j] != 'X') b[i][j] = 1, dfs(mkp(i, j));
            if (f) return std::cout << "NO" << '\n', 0;
        }
    }
    std::cout << "YES" << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) std::cout << b[i][j] << " \n"[j == m - 1];
    }
    return 0;
}