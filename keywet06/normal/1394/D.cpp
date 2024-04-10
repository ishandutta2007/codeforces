#include <bits/stdc++.h>

using int64 = long long;
using PQ = std::priority_queue<int64, std::vector<int64>, std::greater<int64> >;

const int N = 200005;

int n;
int t[N], h[N];

std::vector<int> To[N];

inline int64 Solve(int InN, int OuN, int t, PQ InQ, PQ OuQ) {
    int64 Ans = 0;
    while (OuN - InN >= 2 && InQ.size() && InQ.top() < t) Ans += InQ.top(), ++InN, --OuN, InQ.pop();
    while (InN - OuN >= 2 && OuQ.size() && OuQ.top() < t) Ans += OuQ.top(), ++OuN, --InN, OuQ.pop();
    return Ans += std::max(InN, OuN) * int64(t);
}

inline std::pair<int64, int64> Dfs(int u, int f) {
    int InNum = 0, OutNum = 0;
    int64 Ans = 0;
    PQ InQue, OutQue;
    for (auto v : To[u]) {
        if (v == f) continue;
        auto [Inc, Outc] = Dfs(v, u);
        if (Inc != -1 && (Inc <= Outc || Outc == -1)) {
            Ans += Inc, ++InNum;
            if (Outc != -1) OutQue.push(Outc - Inc);
        } else {
            Ans += Outc, ++OutNum;
            if (Inc != -1) InQue.push(Inc - Outc);
        }
    }
    if (f == -1) return std::make_pair(Ans + Solve(InNum, OutNum, t[u], InQue, OutQue), 0ll);
    return std::make_pair(h[u] <= h[f] ? Ans + Solve(InNum, OutNum + 1, t[u], InQue, OutQue) : -1,
                          h[u] >= h[f] ? Ans + Solve(InNum + 1, OutNum, t[u], InQue, OutQue) : -1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> t[i];
    for (int i = 1; i <= n; ++i) std::cin >> h[i];
    for (int i = 1, u, v; i < n; ++i) {
        std::cin >> u >> v;
        To[u].push_back(v);
        To[v].push_back(u);
    }
    std::cout << Dfs(1, -1).first << std::endl;
    return 0;
}