#include <bits/stdc++.h>

#define Deb std::cerr
#define Debug Deb << "Debug(" << __LINE__ << "): "
#define fi first
#define se second
#define mkp std::make_pair

using int64 = long long;
using pair = std::pair<int, int>;

const int64 P = 998244353;
const int C = 26;
const int N = 10;
const int M = 50;
const int L = 200;

int n, l, m, c, d, u, v, u1, u2, v1, v2, g;
int fin[M];
int tr[M][C];
int use[M][M], id[M][M];

int64 out;

pair p;
pair va[L];

std::string s;

std::queue<pair> q;

inline int getid(int u, int v) { return id[std::min(u, v)][std::max(u, v)]; }

inline std::vector<std::vector<int64> > times(
    const std::vector<std::vector<int64> > x,
    const std::vector<std::vector<int64> > y) {
    std::vector<std::vector<int64> > ret(c, std::vector<int64>(c));
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < c; ++k) ret[i][j] += x[i][k] * y[k][j] % P;
            ret[i][j] %= P;
        }
    }
    return ret;
}

inline std::vector<std::vector<int64> > power(
    const std::vector<std::vector<int64> > x, const int y) {
    return y == 1  ? x
           : y & 1 ? times(power(times(x, x), y / 2), x)
                   : power(times(x, x), y / 2);
}

inline int check(int x, int y) {
    if (x > y) std::swap(x, y);
    if (x && y && use[x][y] != d) use[x][y] = d, q.push(mkp(x, y));
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    ++d;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s, u = 1;
        for (char &ch : s) {
            if (!tr[u][ch -= 'a']) tr[u][ch] = ++d;
            u = tr[u][ch];
        }
        fin[u] = 1;
    }
    q.push(mkp(1, 1)), d = use[1][1] = 1;
    while (!q.empty()) {
        p = q.front(), q.pop();
        va[(id[p.fi][p.se] = ++c) - 1] = p;
        for (int i = 0; i < C; ++i) {
            u1 = tr[p.fi][i], u2 = fin[p.fi] ? tr[1][i] : 0;
            v1 = tr[p.se][i], v2 = fin[p.se] ? tr[1][i] : 0;
            check(u1, v1), check(u1, v2), check(u2, v1), check(u2, v2);
        }
    }
    std::vector<std::vector<int64> > st(c, std::vector<int64>(c));
    q.push(mkp(1, 1)), d = use[1][1] = 0;
    while (!q.empty()) {
        p = q.front(), q.pop(), g = id[p.fi][p.se];
        for (int i = 0; i < C; ++i) {
            u1 = tr[p.fi][i], u2 = fin[p.fi] ? tr[1][i] : 0;
            v1 = tr[p.se][i], v2 = fin[p.se] ? tr[1][i] : 0;
            check(u1, v1), check(u1, v2), check(u2, v1), check(u2, v2);
            if (!g) continue;
            if (getid(u1, v1)) ++st[getid(u1, v1) - 1][g - 1];
            if (getid(u1, v2)) ++st[getid(u1, v2) - 1][g - 1];
            if (getid(u2, v1)) ++st[getid(u2, v1) - 1][g - 1];
            if (getid(u2, v2)) ++st[getid(u2, v2) - 1][g - 1];
        }
    }
    auto ans = power(st, m);
    fin[1] = 1;
    for (int i = 0; i < c; ++i) {
        if (!fin[va[i].fi] || !fin[va[i].se]) continue;
        out += ans[i][0];
    }
    std::cout << out % P << std::endl;
    return 0;
}