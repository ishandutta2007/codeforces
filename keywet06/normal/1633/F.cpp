#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl

template <typename Type1, typename Type2>
inline Type1 &Mid(Type1 &x, Type2 y) {
    return x < y ? x : (x = y);
}

template <typename Type1, typename Type2>
inline Type1 &Mad(Type1 &x, Type2 y) {
    return x > y ? x : (x = y);
}

using int32 = int;
using int64 = long long;

inline int BiClz(int32 x) { return __builtin_clz(x); }

inline int BiBlm(int32 x) { return 1 << 32 - BiClz(x - 1); }

template <typename Type>
inline std::ostream &operator<<(std::ostream &Out, const typename std::vector<Type> Vec) {
    Out << '[';
    for (int i = 1; i < Vec.size(); ++i) {
        Out << Vec[i];
        if (i + 1 < Vec.size()) Out << ", ";
    }
    return Out << ']';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int> > To(n + 1);
    std::vector<std::vector<std::pair<int, int> > > ToP(n + 1);
    for (int i = 1, x, y; i < n; ++i) {
        std::cin >> x >> y;
        To[x].push_back(y);
        To[y].push_back(x);
        ToP[x].emplace_back(y, i);
        ToP[y].emplace_back(x, i);
    }

    std::vector<int> Dfn(n + 1), Top(n + 1), Son(n + 1), Size(n + 1), Fa(n + 1), End(n + 1), FVal(n + 1);
    std::function<void(int, int)> Dfs1 = [&](int u, int F) -> void {
        Size[u] = 1, Fa[u] = F;
        for (auto [v, Val] : ToP[u]) {
            if (v == F) continue;
            Dfs1(v, u), Size[u] += Size[v], FVal[v] = Val;
            if (Size[v] > Size[Son[u]]) Son[u] = v;
        }
    };
    Dfs1(1, 1);

    std::function<void(int, int)> Dfs2 = [&](int u, int T) -> void {
        static int Clock = 0;
        Mad(End[Top[u] = T], Dfn[u] = ++Clock);
        if (Son[u]) Dfs2(Son[u], T);
        for (int v : To[u]) {
            if (v != Fa[u] && v != Son[u]) Dfs2(v, v);
        }
    };
    Dfs2(1, 1);

    struct Node {
        std::array<int, 3> F;
        std::array<int64, 3> S;
        Node() { F[2] = 2, S[0] = S[1] = S[2] = 0; }
        Node(int F0, int F1, int64 S0, int64 S1) { F[0] = F0, F[1] = F1, F[2] = 2, S[0] = S0, S[1] = S1, S[2] = 0; }
        inline std::pair<int, int64> Data() { return std::pair<int, int64>(F[0], S[0]); }
    };
    auto Combi = [&](Node A, Node B) -> Node {
        Node C;
        if ((C.F[0] = A.F[B.F[0]]) != 2) C.S[0] = B.S[0] + A.S[B.F[0]];
        if ((C.F[1] = A.F[B.F[1]]) != 2) C.S[1] = B.S[1] + A.S[B.F[1]];
        return C;
    };

    std::vector<int> Act(n + 1), Num(n + 1), LSta(n + 1);
    std::vector<int64> Sum(n + 1), LVal(n + 1);
    Act[0] = 1;

    int m = BiBlm(n) << 1;
    std::vector<Node> Seg(m);

    std::function<void(int, int, int)> Build = [&](int u, int l, int r) -> void {
        if (l == r) return void(Seg[u] = l == 1 ? Node(1, 0, 0, 0) : Node(0, 2, 0, 0));
        int Mid = l + r >> 1;
        Build(u << 1, l, Mid), Build(u << 1 | 1, Mid + 1, r);
        Seg[u] = Combi(Seg[u << 1], Seg[u << 1 | 1]);
    };
    Build(1, 1, n);

    std::function<Node(int, int, int, int, int)> Query = [&](int u, int l, int r, int x, int y) -> Node {
        if (l >= x && r <= y) return Seg[u];
        int Mid = l + r >> 1;
        if (y <= Mid) return Query(u << 1, l, Mid, x, y);
        if (x > Mid) return Query(u << 1 | 1, Mid + 1, r, x, y);
        return Combi(Query(u << 1, l, Mid, x, y), Query(u << 1 | 1, Mid + 1, r, x, y));
    };
    std::function<Node(int)> Querys = [&](int u) -> Node { return Query(1, 1, n, Dfn[u], End[u]); };

    std::function<void(int, int, int, int, int)> Update = [&](int u, int l, int r, int x, int i) -> void {
        if (l == r) {
            if (Num[i] >= 2) return void(Seg[u] = Node(2, 2, 0, 0));
            if (Num[i] == 1) return void(Seg[u] = Node(0, 2, Sum[i], 0));
            return void(Seg[u] = Node(1, 0, Sum[i] + FVal[i], Sum[i]));
        }
        int Mid = l + r >> 1;
        x <= Mid ? Update(u << 1, l, Mid, x, i) : Update(u << 1 | 1, Mid + 1, r, x, i);
        Seg[u] = Combi(Seg[u << 1], Seg[u << 1 | 1]);
    };
    std::function<void(int)> Updates = [&](int i) -> void { Update(1, 1, n, Dfn[i], i); };

    std::function<int64(int)> Active = [&](int u) -> int64 {
        Act[u] = 1;
        while (Top[u] != 1) {
            Updates(u), u = Top[u];
            auto [Sta, S] = Querys(u).Data();
            Num[Fa[u]] -= LSta[u], Sum[Fa[u]] -= LVal[u];
            Num[Fa[u]] += LSta[u] = Sta, Sum[Fa[u]] += LVal[u] = S;
            u = Fa[u];
        }
        Updates(u), u = Top[u];
        auto [Sta, S] = Querys(u).Data();
        return Sta == 0 ? S : 0;
    };

    std::vector<int> Ids;
    std::function<int(int)> Dfs3 = [&](int u) -> int {
        int Sum = 0;
        for (int v : To[u]) {
            if (v != Fa[u] && Act[v]) Sum += Dfs3(v);
        }
        return Sum ? 0 : (Ids.push_back(FVal[u]), 1);
    };

    while (true) {
        static int64 LastAns;
        int Op;
        std::cin >> Op;
        if (Op == 1) {
            int x;
            std::cin >> x;
            std::cout << (LastAns = Active(x)) << std::endl;
        } else if (Op == 2) {
            if (LastAns) Dfs3(1), std::sort(Ids.begin(), Ids.end());
            std::cout << Ids.size();
            for (int x : Ids) std::cout << ' ' << x;
            std::cout << std::endl;
            Ids.clear();
        } else {
            break;
        }
    }

    return 0;
}