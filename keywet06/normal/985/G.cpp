#include <bits/stdc++.h>

using uint64 = unsigned long long;

const uint64 N = 200005;

uint64 A, B, C, n, m, U[N], V[N], deg[N], ans, qz[N], hz[N];

std::vector<uint64> e[N];

inline void cala() {
    for (uint64 i = 1; i <= n; ++i) e[i].clear();
    memset(deg, 0, sizeof(deg));
    for (uint64 i = 1; i <= m; ++i) {
        if (U[i] < V[i])
            e[U[i]].push_back(V[i]);
        else
            e[V[i]].push_back(U[i]);
    }
    uint64 cnt = 0;
    for (uint64 i = n; i >= 1; --i) {
        uint64 qwq = cnt;
        for (auto v : e[i]) qwq -= deg[v]++;
        uint64 CNT = n - i - e[i].size();
        ans += A * (i - 1) * (CNT * (CNT - 1) / 2 - qwq);
        hz[i] = (CNT * (CNT - 1) / 2 - qwq);
        cnt += deg[i] = e[i].size();
    }
}

inline void calc() {
    for (uint64 i = 1; i <= n; ++i) e[i].clear();
    memset(deg, 0, sizeof deg);
    for (uint64 i = 1; i <= m; ++i) {
        if (U[i] > V[i])
            e[U[i]].push_back(V[i]);
        else
            e[V[i]].push_back(U[i]);
    }
    uint64 cnt = 0;
    for (uint64 i = 1; i <= n; ++i) {
        uint64 qwq = cnt;
        for (auto v : e[i]) qwq -= deg[v]++;
        uint64 CNT = i - 1 - e[i].size();
        ans += C * (i - 1) * (CNT * (CNT - 1) / 2 - qwq);
        qz[i] = (CNT * (CNT - 1) / 2 - qwq);
        cnt += deg[i] = e[i].size();
    }
}

inline void calb() {
    for (uint64 i = 1; i <= n; ++i) e[i].clear();
    memset(deg, 0, sizeof(deg));
    for (uint64 i = 1; i <= m; ++i) e[U[i]].push_back(V[i]), e[V[i]].push_back(U[i]);
    uint64 cnt = 0;
    for (uint64 i = 1; i <= n; ++i) deg[i] = e[i].size();
    for (uint64 i = 1; i <= n; ++i) {
        uint64 qwq = m;
        uint64 CNT = n - 1 - e[i].size();
        for (auto v : e[i]) qwq -= deg[v];
        ans += B * (i - 1) * ((CNT * (CNT - 1) / 2 - qwq) - qz[i] - hz[i]);
    }
}

inline uint64 w(uint64 x, uint64 y, uint64 z) {
    --x, --y, --z;
    if (x > y) std::swap(x, y);
    if (y > z) std::swap(z, y);
    if (x > y) std::swap(x, y);
    return x * A + y * B + z * C;
}

inline uint64 cal3() {
    uint64 tag[N] = {};
    for (uint64 i = 1; i <= n; ++i) e[i].clear();
    memset(deg, 0, sizeof(deg));
    for (uint64 i = 1; i <= m; ++i) ++deg[U[i]], ++deg[V[i]];
    for (uint64 i = 1; i <= m; ++i) {
        if (deg[U[i]] > deg[V[i]] || deg[U[i]] == deg[V[i]] && U[i] < V[i])
            e[U[i]].push_back(V[i]);
        else
            e[V[i]].push_back(U[i]);
    }
    uint64 rtn = 0;
    for (uint64 i = 1; i <= n; ++i) {
        for (auto v : e[i]) tag[v] = i;
        for (auto j : e[i]) {
            for (auto k : e[j]) {
                if (tag[k] == i) rtn += w(i, j, k);
            }
        }
    }
    return rtn;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m >> A >> B >> C;
    for (uint64 i = 1; i <= m; ++i) {
        std::cin >> U[i] >> V[i];
        ++U[i], ++V[i];
    }
    cala();
    calc();
    calb();
    std::cout << ans - cal3() << "\n";
    return 0;
}