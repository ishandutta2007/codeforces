#include <bits/stdc++.h>

const int N = 500;

int n, m, q;

std::vector<int> X1, Y1, X2, Y2, ql, qr;
std::vector<std::vector<int>> sG, sY, sR, sB, span, fen;
std::vector<std::pair<int, int>> queries;
std::vector<std::vector<std::pair<int, int>>> pos;

void prefixSum(std::vector<std::vector<int>> &s) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) s[i][j] += s[i][j - 1];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) s[i][j] += s[i - 1][j];
    }
}

int getSum(std::vector<std::vector<int>> &s, int X1, int Y1, int X2, int Y2) {
    return s[X2][Y2] - s[X1][Y2] - s[X2][Y1] + s[X1][Y1];
}

void add(int x, int y) {
    for (int i = x + 1; i <= n + 1; i += i & -i) {
        for (int j = y + 1; j <= m + 1; j += j & -j) ++fen[i - 1][j - 1];
    }
}

int sum(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) res += fen[i - 1][j - 1];
    }
    return res;
}

int querySum(int X1, int Y1, int X2, int Y2) {
    return sum(X2, Y2) - sum(X1, Y2) - sum(X2, Y1) + sum(X1, Y1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> q;
    sG.assign(n + 1, std::vector<int>(m + 1));
    sY.assign(n + 1, std::vector<int>(m + 1));
    sR.assign(n + 1, std::vector<int>(m + 1));
    sB.assign(n + 1, std::vector<int>(m + 1));
    span.assign(n + 1, std::vector<int>(m + 1));
    X1.resize(q);
    X2.resize(q);
    Y1.resize(q);
    Y2.resize(q);
    ql.resize(q);
    qr.resize(q);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'G') {
                ++sG[i + 1][j + 1];
            } else if (s[j] == 'Y') {
                ++sY[i + 1][j + 1];
            } else if (s[j] == 'R') {
                ++sR[i + 1][j + 1];
            } else {
                ++sB[i + 1][j + 1];
            }
        }
    }
    prefixSum(sG);
    prefixSum(sY);
    prefixSum(sR);
    prefixSum(sB);
    int mx = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int l = 0, r = std::min(std::min(i, n - i), std::min(j, m - j));
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (getSum(sR, i - m, j - m, i, j) == m * m &&
                    getSum(sG, i - m, j, i, j + m) == m * m &&
                    getSum(sY, i, j - m, i + m, j) == m * m &&
                    getSum(sB, i, j, i + m, j + m) == m * m) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            span[i][j] = l;
            mx = std::max(mx, l);
        }
    }
    pos.resize(mx + 1);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) pos[span[i][j]].emplace_back(i, j);
    for (int i = 0; i < q; ++i) {
        std::cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        --X1[i], --Y1[i], ql[i] = 0;
        qr[i] = std::min(X2[i] - X1[i], Y2[i] - Y1[i]) / 2;
    }
    while (true) {
        queries.clear();
        for (int i = 0; i < q; ++i) {
            if (ql[i] != qr[i]) {
                int m = (ql[i] + qr[i] + 1) / 2;
                queries.emplace_back(m, i);
            }
        }
        if (queries.empty()) break;
        std::sort(queries.begin(), queries.end(), std::greater<>());
        fen.assign(n + 1, std::vector<int>(m + 1));
        for (int i = mx, j = 0; i >= 0; --i) {
            while (j < int(queries.size()) && queries[j].first > i) {
                auto [m, k] = queries[j];
                if (querySum(X1[k] + m, Y1[k] + m, X2[k] - m + 1,
                             Y2[k] - m + 1) > 0) {
                    ql[k] = m;
                } else {
                    qr[k] = m - 1;
                }
                ++j;
            }
            if (i == 0) break;
            for (auto [x, y] : pos[i]) add(x, y);
        }
    }
    for (int i = 0; i < q; ++i) std::cout << 4 * ql[i] * ql[i] << "\n";
    return 0;
}