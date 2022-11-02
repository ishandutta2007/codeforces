#include <bits/stdc++.h>

using int32 = int;

inline int BiClz(int32 x) { return __builtin_clz(x); }

inline int BiBlm(int32 x) { return 1 << 32 - BiClz(x - 1); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    struct Edge {
        int u, v, w;
        Edge() : u(0), v(0), w(0) {}
        Edge(int U, int V, int W) : u(U), v(V), w(W) {}
    };
    std::vector<Edge> Ed(n - 1);
    for (Edge &l : Ed) std::cin >> l.u >> l.v >> l.w, --l.u, --l.v;
    std::sort(Ed.begin(), Ed.end(), [](Edge x, Edge y) { return x.w < y.w; });
    std::vector<int> f(n * 2 - 1);
    for (int i = 0; i < f.size(); ++i) f[i] = i;
    std::function<int(int)> Find = [&](int x) {
        return f[x] == x ? x : f[x] = Find(f[x]);
    };
    std::vector<int> Val(n * 2 - 1, -1);
    std::vector<std::array<int, 2> > No(n * 2 - 1, {-1, -1});
    int Cnt = n;
    for (Edge &l : Ed) {
        f[l.u = Find(l.u)] = f[l.v = Find(l.v)] = Cnt;
        Val[Cnt] = l.w, No[Cnt++] = {l.u, l.v};
    }
    std::vector<int> Deep(n * 2 - 1), Dfn(n * 2 - 1, -1), RDfn(n);
    const int C = 20;
    std::vector<std::array<int, C> > Fa(n * 2 - 1);
    int Clock = 0;
    std::function<void(int)> Dfs = [&](int u) -> void {
        for (int i = 1; i < C; ++i) Fa[u][i] = Fa[Fa[u][i - 1]][i - 1];
        if (Val[u] == -1) return void(RDfn[Dfn[u] = Clock++] = u);
        Deep[No[u][0]] = Deep[No[u][1]] = Deep[u] + 1;
        Fa[No[u][0]][0] = Fa[No[u][1]][0] = u;
        Dfs(No[u][0]), Dfs(No[u][1]);
    };
    Fa[n * 2 - 2][0] = n * 2 - 2, Dfs(n * 2 - 2);
    auto LCA = [&](int x, int y) -> int {
        if (Deep[x] < Deep[y]) std::swap(x, y);
        int d = Deep[x] - Deep[y];
        for (int i = 0; i < C; ++i) {
            if ((d >> i) & 1) x = Fa[x][i];
        }
        if (x == y) return x;
        for (int i = C - 1; i >= 0; --i) {
            if (Fa[x][i] != Fa[y][i]) x = Fa[x][i], y = Fa[y][i];
        }
        return Fa[x][0];
    };
    struct Node {
        int Min, Max, SMin, SMax, Tag;
        Node() : Min(INT_MAX), Max(-1), SMin(INT_MAX), SMax(-1), Tag(0) {}
        Node(int x) : Min(INT_MAX), Max(-1), SMin(x), SMax(x), Tag(0) {}
        Node(int MIN, int MAX, int SMIN, int SMAX, int TAG)
            : Min(MIN), Max(MAX), SMin(SMIN), SMax(SMAX), Tag(TAG) {}
    };
    auto Add = [](Node x, Node y) -> Node {
        return Node(std::min(x.Min, y.Min), std::max(x.Max, y.Max),
                    std::min(x.SMin, y.SMin), std::max(x.SMax, y.SMax), 0);
    };
    auto Tag = [](Node &x, int Tag) -> void {
        if (Tag == 1) {
            x.Tag = 1, x.Min = x.SMin, x.Max = x.SMax;
        } else if (Tag == 2) {
            x.Tag = 2, x.Min = INT_MAX, x.Max = -1;
        }
    };
    auto Pus = [&](Node &x, Node &L, Node &R) -> void {
        if (x.Tag) Tag(L, x.Tag), Tag(R, x.Tag), x.Tag = 0;
    };
    std::vector<Node> Tree(BiBlm(n) << 1);
    using BuildType = std::function<void(int, int, int)>;
    BuildType Build = [&](int u, int l, int r) {
        if (l == r) return void(Tree[u] = Dfn[l]);
        int Mid = l + r >> 1;
        Build(u << 1, l, Mid);
        Build(u << 1 | 1, Mid + 1, r);
        Tree[u] = Add(Tree[u << 1], Tree[u << 1 | 1]);
    };
    using UpdType = std::function<void(int, int, int, int, int, int)>;
    UpdType Upd = [&](int u, int l, int r, int x, int y, int t) -> void {
        if (l >= x && r <= y) return Tag(Tree[u], t);
        int Mid = l + r >> 1;
        Pus(Tree[u], Tree[u << 1], Tree[u << 1 | 1]);
        if (x <= Mid) Upd(u << 1, l, Mid, x, y, t);
        if (y > Mid) Upd(u << 1 | 1, Mid + 1, r, x, y, t);
        Tree[u] = Add(Tree[u << 1], Tree[u << 1 | 1]);
    };
    Build(1, 0, n - 1);
    for (int T = 0, t, l, r, x; T < q; ++T) {
        std::cin >> t;
        if (t <= 2) {
            std::cin >> l >> r, Upd(1, 0, n - 1, --l, --r, t);
        } else {
            std::cin >> x, --x;
            int Min = std::min(Dfn[x], Tree[1].Min),
                Max = std::max(Dfn[x], Tree[1].Max);
            std::cout << Val[LCA(RDfn[Min], RDfn[Max])] << '\n';
        }
    }
    return 0;
}