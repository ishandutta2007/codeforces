#include <bits/stdc++.h>

using pi5 = std::pair<int, int>;

const int C = 20;
const int N = 100005;
const int M = 262144;
const int INF = 2e9;

int n, q, x, y, z, DLen, D1, D2, Last;
int Deep[N];

std::vector<pi5> to[N];

inline int dfs(int u, int f) {
    int Ret = u, Low = u, Tmp;
    for (pi5 &e : to[u]) {
        if (e.first == f) continue;
        Deep[e.first] = Deep[u] + e.second;
        Tmp = dfs(e.first, u);
        if (Deep[Tmp] > Deep[Ret]) {
            Low = Ret, Ret = Tmp;
        } else if (Deep[Tmp] > Deep[Low]) {
            Low = Tmp;
        }
    }
    Tmp = Deep[Low] + Deep[Ret] - 2 * Deep[u];
    if (Tmp > DLen) DLen = Tmp, D1 = Ret, D2 = Low;
    return Ret;
}

template <typename _Tp>
inline void Mem(_Tp &x) {
    memset(x, 0, sizeof(x));
}

template <typename _Tp, typename... Args>
inline void Mem(_Tp &x, Args &...args) {
    Mem(x), Mem(args...);
}

struct Solver {
    struct Node {
        int id, val, plus;

        Node() : id(), val(), plus(0) {}
        Node(int _id, int _val, int _plus = 0)
            : id(_id), val(_val), plus(_plus) {}

        Node &Get(Node x, Node y) {
            if (x.val > y.val) {
                return *this = Node(x.id, x.val + plus, plus);
            } else {
                return *this = Node(y.id, y.val + plus, plus);
            }
        }

        Node &operator-=(int x) { return val -= x, plus -= x, *this; }
    };

    int R, DfnC, LeafC;
    int Deep[N], Col[N], Dfn[N], RDfn[N], Low[N], Give[N], FLen[N], Len[N],
        Id[N];
    int Ans[M];
    int Fa[N][C];

    Node No[M];

    inline void Build(int u, int l, int r) {
        if (l == r) return void(No[u] = Node(l, Give[l]));
        int mid = l + r >> 1;
        Build(u << 1, l, mid);
        Build(u << 1 | 1, mid + 1, r);
        No[u].Get(No[u << 1], No[u << 1 | 1]);
    }
    inline void Build() { Build(1, 1, n); }

    inline void Update(int u, int l, int r, int x, int y, int z) {
        if (l >= x && r <= y) return void(No[u] -= z);
        int mid = l + r >> 1;
        if (x <= mid) Update(u << 1, l, mid, x, y, z);
        if (y > mid) Update(u << 1 | 1, mid + 1, r, x, y, z);
        No[u].Get(No[u << 1], No[u << 1 | 1]);
    }
    inline void Update(int x, int y, int z) { Update(1, 1, n, x, y, z); }

    inline void Dfs(int u, int f) {
        Fa[u][0] = f, Dfn[u] = ++DfnC, RDfn[DfnC] = u, Id[u] = u;
        for (int i = 1; i < C; ++i) Fa[u][i] = Fa[Fa[u][i - 1]][i - 1];
        for (pi5 &e : to[u]) {
            if (e.first == f) continue;
            Deep[e.first] = Deep[u] + (FLen[e.first] = e.second);
            Dfs(e.first, u);
            if (Deep[Id[e.first]] > Deep[Id[u]]) Id[u] = Id[e.first];
        }
        Give[Dfn[u]] = to[u].size() == 1 && u != R ? (++LeafC, Deep[u]) : -INF;
        Low[u] = DfnC;
    }

    inline void Init(int r) {
        R = r, LeafC = DfnC = 0;
        Mem(Deep, Col, Dfn, Low, Give, Ans, FLen, Len, Id, Fa, No);
        Dfs(R, 0), Build();
        for (int i = 1, u; i <= LeafC; ++i) {
            u = RDfn[No[1].id], Ans[i] = Ans[i - 1] + (Len[i] = No[1].val);
            while (u && !Col[u]) {
                Col[u] = i, Update(Dfn[u], Low[u], FLen[u]), u = Fa[u][0];
            }
        }
        for (int i = LeafC + 1; i <= n << 1; ++i) Ans[i] = Ans[i - 1];
    }

    inline Solver() {}
    inline Solver(int r) { Init(r); }

    inline int Query(int x, int k) {
        k = k * 2 - 1;
        if (Col[x] <= k) return Ans[k];
        if (k == 1) return Deep[Id[x]];
        int Ret, u = Id[x], Tmp = Ans[k - 1] + Deep[u];
        for (int i = C - 1; ~i; --i) {
            if (Col[Fa[u][i]] >= k) u = Fa[u][i];
        }
        if (Col[u] >= k) u = Fa[u][0];
        Ret = Tmp - Deep[u], u = Id[x], Tmp = Ans[k] + Deep[u];
        for (int i = C - 1; ~i; --i) {
            if (Col[Fa[u][i]] > k) u = Fa[u][i];
        }
        u = Fa[u][0], Tmp -= Len[Col[u]];
        for (int i = C - 1; ~i; --i) {
            if (Col[Fa[u][i]] == Col[u]) u = Fa[u][i];
        }
        u = Fa[u][0], Tmp -= Deep[u];
        return std::max(Ret, Tmp);
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        std::cin >> x >> y >> z;
        to[x].emplace_back(y, z);
        to[y].emplace_back(x, z);
    }
    dfs(1, 0);
    Solver S1(D1), S2(D2);
    while (q--) {
        std::cin >> x >> y;
        x = (x + Last - 1) % n + 1;
        y = (y + Last - 1) % n + 1;
        std::cout << (Last = std::max(S1.Query(x, y), S2.Query(x, y))) << '\n';
    }
    return 0;
}