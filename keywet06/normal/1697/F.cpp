#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Debug << std::endl

#define templ template <typename Type1, typename Type2>
templ inline Type1 &Mid(Type1 &x, Type2 y) { return x < y ? x : x = y; }
templ inline Type1 &Mad(Type1 &x, Type2 y) { return x > y ? x : x = y; }
#undef tmepl

const int N = 20005;
const int K = 10;
const int M = N * K * 2;

int T, n, m, k, p;

int DfnClock, SscNum, Dfn[M], Low[M], Ssc[M], Ins[M], Out[M], Ans[M], AMin[N], AMax[N];
std::stack<int> TarSta;

std::vector<int> To[M], ST[M], Ps[M], TS[M];

inline int GetP(int i, int x, int o) { return (i - 1 << 1 | o) * k + x; }
inline std::tuple<int, int, int> GetT(int u) { return --u, std::make_tuple((u / k >> 1) + 1, u % k + 1, u / k & 1); }

inline void Tarjan(int u) {
    Dfn[u] = Low[u] = ++DfnClock, Ins[u] = true, TarSta.push(u);
    for (auto v : To[u]) {
        if (!Dfn[v]) {
            Tarjan(v), Mid(Low[u], Low[v]);
        } else if (Ins[v]) {
            Mid(Low[u], Low[v]);
        }
    }
    if (Low[u] == Dfn[u]) {
        int v;
        ++SscNum;
        do {
            v = TarSta.top(), TarSta.pop();
            Ins[v] = false, Ssc[v] = SscNum, Ps[SscNum].push_back(v);
        } while (v != u);
    }
}

inline std::ostream &operator<<(std::ostream &Out, std::tuple<int, int, int> t) {
    auto [i, x, o] = t;
    return Out << "[a[" << i << "] "
               << "<>"[o] << "= " << x << "]";
    return Out << "[" << i << ", " << x << ", " << o << "]";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> k, p = n * k * 2;
        DfnClock = SscNum = 0;
        memset(Dfn, 0, sizeof(int) * (p + 1));
        memset(Low, 0, sizeof(int) * (p + 1));
        memset(Ssc, 0, sizeof(int) * (p + 1));
        memset(Ans, 0, sizeof(int) * (p + 1));
        for (int i = 1; i <= p; ++i) To[i].clear(), ST[i].clear(), Ps[i].clear(), TS[i].clear();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < k; ++j) {
                To[GetP(i, j, 0)].push_back(GetP(i, j + 1, 0));
                To[GetP(i, j + 1, 1)].push_back(GetP(i, j, 1));
                // Debug << GetT(GetP(i, j, 0)) << " => " << (GetT(GetP(i, j + 1, 0))) << '\n';
                // Debug << GetT(GetP(i, j + 1, 1)) << " => " << (GetT(GetP(i, j, 1))) << '\n';
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                To[GetP(i, j, 1)].push_back(GetP(i + 1, j, 1));
                To[GetP(i + 1, j, 0)].push_back(GetP(i, j, 0));
            }
        }
        for (int c = 1, o, i, j, x; c <= m; ++c) {
            std::cin >> o;
            if (o == 1) {
                std::cin >> i >> x;
                To[GetP(i, x, 0)].push_back(x > 1 ? GetP(i, x - 1, 0) : GetP(i, x + 1, 1));
                To[GetP(i, x, 1)].push_back(x < k ? GetP(i, x + 1, 1) : GetP(i, x - 1, 0));
                // Debug << GetT(GetP(i, x, 0)) << " => " << (x > 1 ? GetT(GetP(i, x - 1, 0)) : GetT(GetP(i, x + 1,
                // 1)))<< '\n'; Debug << GetT(GetP(i, x, 1)) << " => " << (x < k ? GetT(GetP(i, x + 1, 1)) :
                // GetT(GetP(i, x - 1, 0)))       << '\n';
            } else if (o == 2) {
                std::cin >> i >> j >> x;  // a[i] + a[j] <= x, a[i] <= x - a[j] <= x - c <=> a[j] >= c
                for (int c = 1; c <= k; ++c) {
                    if (x - c < 1) {
                        To[GetP(i, c, 1)].push_back(GetP(i, c - 1, 0));
                        To[GetP(j, c, 1)].push_back(GetP(j, c - 1, 0));
                        // Debug << GetT(GetP(i, c, 1)) << " => " << (GetT(GetP(i, c - 1, 0))) << '\n';
                        // Debug << GetT(GetP(j, c, 1)) << " => " << (GetT(GetP(j, c - 1, 0))) << '\n';
                    } else if (x - c < k) {
                        To[GetP(i, c, 1)].push_back(GetP(j, x - c, 0));
                        To[GetP(j, c, 1)].push_back(GetP(i, x - c, 0));
                        // Debug << GetT(GetP(i, c, 1)) << " => " << (GetT(GetP(j, x - c, 0))) << '\n';
                        // Debug << GetT(GetP(j, c, 1)) << " => " << (GetT(GetP(i, x - c, 0))) << '\n';
                    }
                }
            } else if (o == 3) {
                std::cin >> i >> j >> x;  // a[i] + a[j] >= x, a[i] >= x - a[j] >= x - c <=> a[j] <= c
                for (int c = 1; c <= k; ++c) {
                    if (x - c > k) {
                        To[GetP(i, c, 0)].push_back(GetP(i, c + 1, 1));
                        To[GetP(j, c, 0)].push_back(GetP(j, c + 1, 1));
                        // Debug << GetT(GetP(i, c, 0)) << " => " << (GetT(GetP(i, c + 1, 1))) << '\n';
                        // Debug << GetT(GetP(j, c, 0)) << " => " << (GetT(GetP(j, c + 1, 1))) << '\n';
                    } else if (x - c > 1) {
                        To[GetP(i, c, 0)].push_back(GetP(j, x - c, 1));
                        To[GetP(j, c, 0)].push_back(GetP(i, x - c, 1));
                        // Debug << GetT(GetP(i, c, 0)) << " => " << (GetT(GetP(j, x - c, 1))) << '\n';
                        // Debug << GetT(GetP(j, c, 0)) << " => " << (GetT(GetP(i, x - c, 1))) << '\n';
                    }
                }
            }
        }
        for (int i = 1; i <= p; ++i) {
            if (!Dfn[i]) Tarjan(i);
        }
        int Continue = false;
        for (int i = 1; i <= n && !Continue; ++i) {
            for (int c = 1; c < k && !Continue; ++c) {
                if (Ssc[GetP(i, c, 0)] == Ssc[GetP(i, c + 1, 1)]) std::cout << -1 << '\n', Continue = true;
            }
        }
        if (Continue) continue;
        for (int u = 1; u <= p; ++u) {
            for (auto v : To[u]) {
                if (Ssc[u] != Ssc[v]) ST[Ssc[v]].push_back(Ssc[u]), TS[Ssc[u]].push_back(Ssc[v]), ++Out[Ssc[u]];
            }
        }
        std::queue<int> Que;
        for (int u = 1; u <= SscNum; ++u) {
            if (!Out[u]) Que.emplace(u);
        }
        while (!Que.empty()) {
            int x = Que.front();
            Que.pop();
            int Flag = true;
            for (auto y : TS[x]) Flag &= Ans[Ps[y].front()];
            // Debug << "Check";
            for (auto u : Ps[x]) {
                // Deb << " " << GetT(u);
                auto [i, x, o] = GetT(u);
                if (o == 0 && x != k) Flag &= !Ans[GetP(i, x + 1, 1)];
                if (o == 1 && x != 1) Flag &= !Ans[GetP(i, x - 1, 0)];
            }
            // Deb << '\n';
            if (Flag) {
                // Debug << "Enable";
                for (auto u : Ps[x]) Ans[u] = 1;  // Deb << " " << GetT(u);
                // Deb << '\n';
            }
            for (auto y : ST[x]) {
                if (!--Out[y]) Que.push(y);
            }
        }
        for (int i = 1; i <= n; ++i) AMin[i] = k, AMax[i] = 1;
        for (int u = 1; u <= p; ++u) {
            auto [i, x, o] = GetT(u);
            if (o == 0 && Ans[u] == 0) Mad(AMax[i], x + 1);
            if (o == 0 && Ans[u] == 1) Mid(AMin[i], x);
            if (o == 1 && Ans[u] == 0) Mid(AMin[i], x - 1);
            if (o == 1 && Ans[u] == 1) Mad(AMax[i], x);
        }
        for (int i = 1; i <= n; ++i) std::cout << AMax[i] << " \n"[i == n];
        // std::cout << "[" << AMax[i] << ", " << AMin[i] << "] "
        //           << " \n"[1 || i == n];
    }
    return 0;
}