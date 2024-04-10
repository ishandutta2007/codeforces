#include <bits/stdc++.h>

template <typename Type1, typename Type2>
inline Type1 &Mad(Type1 &x, Type2 y) {
    return x > y ? x : (x = y);
}

const int N = 4005;

int n, m;
int a[N], ls[N], rs[N], sz[N];

long long tmp[N];
long long f[N][N];

std::stack<int> stk;

void dfs(int x) {
    sz[x] = 1;
    f[x][1] = a[x] * (m - 1ll);
    auto recur = [&](int y) {
        if (y) {
            dfs(y);
            std::fill(tmp, tmp + sz[x] + sz[y] + 1, -1e18);
            for (int i = 0; i <= sz[x]; ++i) {
                for (int j = 0; j <= sz[y]; ++j) {
                    Mad(tmp[i + j], f[x][i] + f[y][j] - 2ll * a[x] * i * j);
                }
            }
            sz[x] += sz[y];
            std::copy(tmp, tmp + sz[x] + 1, f[x]);
        }
    };
    recur(ls[x]), recur(rs[x]);
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int x = 0;
        while (!stk.empty() && a[i] < a[stk.top()]) x = stk.top(), stk.pop();
        ls[i] = x;
        if (!stk.empty()) rs[stk.top()] = i;
        stk.push(i);
    }
    int rt = std::min_element(a + 1, a + n + 1) - a;
    dfs(rt);
    std::cout << f[rt][m] << '\n';
    return 0;
}