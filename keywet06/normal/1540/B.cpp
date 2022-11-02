#include <bits/stdc++.h>

using int64 = long long;

const int P = 1000000007;
const int I = P + 1 >> 1;
const int N = 205;
const int M = N << 1;

int n, ecn, x, y, clo, cnt;
int head[N], lst[N], ti[N], rot[N], ss[N], deep[N];
int next[M], to[M];

int64 ans;
int64 dp[N][N];

void insert(int x, int y) {
    next[++ecn] = head[x];
    head[x] = ecn;
    to[ecn] = y;
}

void addedge(int x, int y) { insert(x, y), insert(y, x); }

void dfs(int u) {
    ti[u] = ++clo, rot[clo] = u;
    for (int e = head[u]; e; e = next[e]) {
        if (ti[to[e]]) continue;
        deep[to[e]] = deep[u] + 1, dfs(to[e]);
    }
    lst[u] = clo;
}

void solve(int x) {
    clo = 0;
    memset(ti, 0, sizeof(ti));
    deep[x] = 0;
    dfs(x);
    // std::cerr << "deep = {";
    // for (int i = 1; i <= n; ++i) std::cerr << deep[i] << ", ";
    // std::cerr << "...};" << std::endl;
    // std::cerr << "ti = {";
    // for (int i = 1; i <= n; ++i) std::cerr << ti[i] << ", ";
    // std::cerr << "...};" << std::endl;
    // std::cerr << "lst = {";
    // for (int i = 1; i <= n; ++i) std::cerr << lst[i] << ", ";
    // std::cerr << "...};" << std::endl;
    // std::cerr << "rot = {";
    // for (int i = 1; i <= n; ++i) std::cerr << rot[i] << ", ";
    // std::cerr << "...};" << std::endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = ti[i] + 1; j <= lst[i]; ++j) ans += i > rot[j];
        cnt = 0;
        for (int e = head[i]; e; e = next[e]) {
            if (ti[to[e]] > ti[i]) ss[++cnt] = to[e];
        }
        for (int a = 1; a < cnt; ++a) {
            for (int b = a + 1; b <= cnt; ++b) {
                for (int c = ti[ss[a]]; c <= lst[ss[a]]; ++c) {
                    for (int d = ti[ss[b]]; d <= lst[ss[b]]; ++d) {
                        ans += rot[c] > rot[d] ? dp[deep[rot[c]] - deep[i]]
                                                   [deep[rot[d]] - deep[i]]
                                               : dp[deep[rot[d]] - deep[i]]
                                                   [deep[rot[c]] - deep[i]];
                    }
                }
            }
        }
    }
    ans %= P;
}

int64 power(int64 x, int y) {
    return y ? power(x * x % P, y >> 1) * (y & 1 ? x : 1) % P : 1;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        std::cin >> x >> y;
        addedge(x, y);
    }
    for (int i = 1; i <= n; ++i) dp[0][i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = I * (dp[i - 1][j] + dp[i][j - 1]) % P;
        }
    }
    for (int i = 1; i <= n; ++i) solve(i);
    std::cout << ans * power(n, P - 2) % P << std::endl;
    return 0;
}