#include <bits/stdc++.h>

template <typename Type1, typename Type2>
inline Type1 &Mid(Type1 &x, Type2 y) {
    return x < y ? x : (x = y);
}

const int M = 10000005;

struct Node {
    int l, r, s;
    Node() {}
    Node(int L, int R, int S) : l(L), r(R), s(S) {}
};

int Cnt = 0;

Node Seg[M];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> Root;
    std::function<void(int &, int, int)> Build = [&](int &u, int l, int r) -> void {
        u = Cnt++, Seg[u] = Node(0, 0, r - l + 1);
        if (l == r) return;
        int Mid = l + r >> 1;
        Build(Seg[u].l, l, Mid);
        Build(Seg[u].r, Mid + 1, r);
    };
    Root.push_back(0), Build(Root[0], 1, n);
    std::function<void(int &, int, int, int, int)> Clear = [&](int &u, int l, int r, int x, int y) -> void {
        Seg[Cnt++] = Seg[u], u = Cnt - 1;
        if (l >= x && r <= y || !Seg[u].s) return void(Seg[u].s = 0);
        int Mid = l + r >> 1;
        if (x <= Mid) Clear(Seg[u].l, l, Mid, x, y);
        if (y > Mid) Clear(Seg[u].r, Mid + 1, r, x, y);
        Seg[u].s = Seg[Seg[u].l].s + Seg[Seg[u].r].s;
    };
    std::function<int(int, int, int, int, int)> Query = [&](int u, int l, int r, int x, int y) -> int {
        if (l >= x && r <= y || !Seg[u].s) return Seg[u].s;
        int Mid = l + r >> 1, Ret = 0;
        if (x <= Mid) Ret += Query(Seg[u].l, l, Mid, x, y);
        if (y > Mid) Ret += Query(Seg[u].r, Mid + 1, r, x, y);
        return Ret;
    };
    std::function<int(int, int, int, int, int)> Get = [&](int u, int l, int r, int x, int y) -> int {
        if (!Seg[u].s) return 0;
        if (l == r) return l;
        int Mid = l + r >> 1, Ret = 0;
        if (x <= Mid) Ret += Get(Seg[u].l, l, Mid, x, y);
        if (y > Mid) Ret += Get(Seg[u].r, Mid + 1, r, x, y);
        return Ret;
    };
    struct Oper {
        int o, l, r, t;
    };
    std::vector<Oper> Op(q + 1);
    std::vector<int> Time(n + 1, q + 1);
    std::vector<int> Ans(q + 1);
    for (int i = 1; i <= q; ++i) {
        Root.push_back(Root.back());
        std::cin >> Op[i].o;
        if (Op[i].o == 0) {
            std::cin >> Op[i].l >> Op[i].r >> Op[i].t;
            if (Op[i].t == 0) Clear(Root.back(), 1, n, Op[i].l, Op[i].r);
        } else {
            std::cin >> Op[i].l;
            Ans[i] = !Query(Root.back(), 1, n, Op[i].l, Op[i].l);
        }
    }
    for (int i = 1; i <= q; ++i) {
        if (Op[i].o != 0 || Op[i].t != 1) continue;
        if (Op[i].l == Op[i].r) {
            Mid(Time[Op[i].l], i);
            continue;
        }
        if (Query(Root.back(), 1, n, Op[i].l, Op[i].r) > 1) continue;
        int l = i, r = q;
        while (l < r) {
            int Mid = l + r >> 1;
            if (Query(Root[Mid], 1, n, Op[i].l, Op[i].r) > 1) {
                l = Mid + 1;
            } else {
                r = Mid;
            }
        }
        Mid(Time[Get(Root.back(), 1, n, Op[i].l, Op[i].r)], l);
    }
    for (int i = 1; i <= q; ++i) {
        if (Op[i].o == 0) continue;
        if (Ans[i]) {
            std::cout << "NO" << '\n';
        } else if (Time[Op[i].l] < i) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "N/A" << '\n';
        }
    }
    return 0;
}