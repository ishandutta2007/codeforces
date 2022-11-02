#include <bits/stdc++.h>

using int64 = long long;

const int N = 1505;
const int C = 45136;
const int64 P = 998244353017;

int n, m, c, d, u;
int last[N], next[N], num[N], pa[N], pb[N], p[N], used[N];
int a[N][N], b[N][N];

int64 ha[N], hb[N];

std::stack<int> ans, que, rem;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
            ha[i] = (ha[i] * C + a[i][j]) % P;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> b[i][j];
            hb[i] = (hb[i] * C + b[i][j]) % P;
        }
    }
    for (int i = 1; i <= n; ++i) pa[i] = pb[i] = i;
    std::sort(pa + 1, pa + n + 1, [](int x, int y) { return ha[x] < ha[y]; });
    std::sort(pb + 1, pb + n + 1, [](int x, int y) { return hb[x] < hb[y]; });
    for (int i = 1; i <= n; ++i) {
        if (ha[pa[i]] != hb[pb[i]]) return std::cout << -1 << "\n", 0;
    }
    // 
    //  a  b 
    // 
    // 
    c = 1;
    for (int i = 2; i <= n + 1; ++i) {
        if (ha[pa[i]] == ha[pa[i - 1]]) continue;
        std::sort(pa + c, pa + i), std::sort(pb + c, pb + i);
        while (c < i) p[pb[c]] = pa[c], ++c;
    }
    for (int i = 0; i <= n; ++i) last[next[i] = i + 1] = i;
    for (int i = 1; i <= m; ++i) b[n + 1][i] = n + 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) num[j] += b[i][j] > b[i + 1][j];
    }
    for (int i = 1; i <= m; ++i) {
        if (!num[i]) que.push(i), used[i] = 1;
    }
    while (!que.empty()) {
        c = que.top(), que.pop(), ans.push(c);
        for (u = next[0]; u != n; u = next[u]) {
            if (b[u][c] < b[u + 1][c]) rem.push(u);
        }
        while (!rem.empty()) {
            d = rem.top(), rem.pop();
            next[last[d]] = next[d], last[next[d]] = last[d];
            for (int i = 1; i <= m; ++i) num[i] -= b[d][i] > b[d + 1][i];
        }
        for (int i = 1; i <= m; ++i) {
            if (!num[i] && !used[i]) que.push(i), used[i] = 1;
        }
    }
    for (u = next[0]; u != n; u = next[u]) {
        if (p[u] > p[u + 1]) return std::cout << -1 << std::endl, 0;
    }
    std::cout << ans.size() << std::endl;
    while (!ans.empty()) std::cout << ans.top() << ' ', ans.pop();
    std::cout << std::endl;
    return 0;
}