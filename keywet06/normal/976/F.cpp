#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
const int N = 4005;

int n1, n2, m, num = 1, T = N - 1, K = INF;
int Lev[N], Cur[N], h[N], Du[N];

std::vector<int> Ans[N >> 1];

struct Edge {
    int To, Next, Val;
} Ed[12100];

inline void Add(int x, int y, int Val) {
    Ed[++num].To = y;
    Ed[num].Next = h[x];
    h[x] = num;
    Ed[num].Val = Val;
    Ed[++num].To = x;
    Ed[num].Next = h[y];
    h[y] = num;
    Ed[num].Val = 0;
}

inline bool Bfs() {
    std::queue<int> q;
    memset(Lev, 0, sizeof(Lev));
    q.push(0);
    Lev[0] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = h[x]; i; i = Ed[i].Next) {
            int y = Ed[i].To;
            if (Lev[y] || !Ed[i].Val) continue;
            Lev[y] = Lev[x] + 1;
            if (y == T) return 1;
            q.push(y);
        }
    }
    return 0;
}

inline int Dinic(int x, int low) {
    if (x == T) return low;
    int Tmp = low;
    for (int &i = Cur[x]; i; i = Ed[i].Next) {
        int y = Ed[i].To;
        if (Lev[y] != Lev[x] + 1 || !Ed[i].Val) continue;
        int Res = Dinic(y, std::min(Tmp, Ed[i].Val));
        if (!Res) {
            Lev[y] = 0;
        } else {
            Tmp -= Res, Ed[i].Val -= Res, Ed[i ^ 1].Val += Res;
        }
        if (!Tmp) return low;
    }
    return low - Tmp;
}

int main() {
    std::cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        std::cin >> x >> y;
        Add(x, y + n1, 1);
        ++Du[x], ++Du[y + n1];
    }
    for (int i = 1; i <= n1 + n2; ++i) K = std::min(K, Du[i]);
    for (int i = 1; i <= n1; ++i) {
        if (Du[i] > K) Add(0, i, Du[i] - K);
    }
    for (int i = 1; i <= n2; ++i) {
        if (Du[i + n1] > K) Add(i + n1, T, Du[i + n1] - K);
    }
    for (int j = K; j >= 1; --j) {
        while (Bfs()) {
            memcpy(Cur, h, sizeof(h));
            Dinic(0, INF);
        }
        for (int i = 1; i <= m; ++i) {
            if (Ed[i << 1].Val) Ans[j].push_back(i);
        }
        for (int i = 1; i <= n1; ++i) Add(0, i, 1);
        for (int i = 1; i <= n2; ++i) Add(i + n1, T, 1);
    }
    std::cout << 0 << '\n';
    for (int i = 1; i <= K; ++i) {
        std::cout << Ans[i].size();
        for (int j = 0; j < Ans[i].size(); ++j) std::cout << ' ' << Ans[i][j];
        std::cout << '\n';
    }
    return 0;
}