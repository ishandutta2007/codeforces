#include <bits/stdc++.h>

#ifndef OCT_MODINT_HPP
#define OCT_MODINT_HPP

namespace Oct {

template <typename DataType, DataType Mod, typename OperType = DataType>
class ModInt {
   public:
    using CurrentType = ModInt<DataType, Mod, OperType>;
    using ThisType = CurrentType;

   protected:
    DataType Data;

   public:
    inline ModInt() : Data() {}
    inline ModInt(const DataType Val) : Data(Val) {}

    inline const DataType Value() const { return this->Data; }
    inline DataType &LValue() { return this->Data; }

    inline bool operator==(CurrentType x) const {
        return this->Value() == x.Value();
    }
    inline bool operator!=(CurrentType x) const {
        return this->Value() != x.Value();
    }

    inline CurrentType operator+(CurrentType x) const {
        return (x.LValue() += this->Value()) >= Mod ? x.Value() - Mod
                                                    : x.Value();
    }
    inline CurrentType &operator+=(CurrentType x) {
        if ((this->LValue() += x.Value()) >= Mod) this->LValue() -= Mod;
        return *this;
    }

    inline CurrentType operator-(CurrentType x) const {
        x.LValue() = this->Value() + Mod - x.Value();
        return x.Value() >= Mod ? x.Value() - Mod : x.Value();
    }
    inline CurrentType &operator-=(CurrentType x) {
        x.LValue() = this->Value() + Mod - x.Value();
        if (x.Value() >= Mod) x.LValue() -= Mod;
        return *this;
    }

    inline CurrentType operator+() { return *this; }
    inline CurrentType operator-() { return 0 - *this; }

    inline CurrentType operator*(CurrentType x) const {
        return this->Value() * OperType(x.Value()) % Mod;
    }
    inline CurrentType &operator*=(CurrentType x) {
        this->LValue() = this->Value() * OperType(x.Value()) % Mod;
        return *this;
    }

    inline CurrentType Pow(DataType Exp) const {
        CurrentType x = *this, ret = 1;
        while (Exp) {
            if (Exp & 1) ret *= x;
            x *= x, Exp >>= 1;
        }
        return ret;
    }

    inline CurrentType Inv() const { return this->Pow(Mod - 2); }

    inline CurrentType operator/(CurrentType x) const {
        return *this * x.Inv();
    }
    inline CurrentType &operator/=(CurrentType x) { return *this *= x.Inv(); }
};

}  // namespace Oct

#endif

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl

using int64 = long long;

const int P = 1000100009;
const int E = 101;
const int D = 37;
const int C = 20;
const int N = 300005;

using mint = Oct::ModInt<int, P, int64>;

const int F = mint(E).Inv().Value();

char s[N];

int R, maxd, n, q, x, y, pu, pv, ps, px, py, qu, qv, qx, qy, qs, d, c, flag, l,
    r, mid, e, pl, ql, pd, qd, pt, qt, da, db, dc;
int deep[N], len[N], son[N], top[N], dif[N], lgs[N];
int fa[N][C];

mint pre[N], re[N], ha1[N], ha2[N];

std::vector<int> to[N], us[N];

inline void dfs1(int u, int f) {
    fa[u][0] = f, deep[u] = deep[f] + 1;
    ha1[u] = ha1[f] * E + s[u];
    ha2[u] = ha2[f] + pre[deep[u] - 1] * s[u];
    maxd = std::max(maxd, deep[u]);
    for (int i = 1; i < C; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : to[u]) {
        if (v == f) continue;
        dfs1(v, u);
        if (len[v] > len[son[u]]) son[u] = v;
    }
    len[u] = len[son[u]] + 1;
}

inline void dfs2(int u, int Top) {
    if (son[fa[u][0]] != u) {
        us[u].resize(len[u] << 1);
        for (int l = len[u] - 1, v = fa[u][0]; l >= 0; --l, v = fa[v][0]) {
            us[u][l] = v;
        }
        dif[u] = deep[u] - len[u];
    }
    us[Top][deep[u] - dif[Top]] = u, top[u] = Top;
    if (son[u]) dfs2(son[u], Top);
    for (int v : to[u]) {
        if (v == fa[u][0] || v == son[u]) continue;
        dfs2(v, v);
    }
}

inline int up(int u, int x) {
    if (x == 0) return u;
    int T = top[fa[u][lgs[x]]];
    return x == 0 ? u : us[T][deep[u] - x - dif[T]];
}

inline int dis(int u, int s, int v) { return deep[u] + deep[v] - deep[s] * 2; }

inline int lca(int u, int v) {
    if (deep[u] < deep[v]) std::swap(u, v);
    int x = deep[u] - deep[v];
    for (int i = 0; x; ++i) {
        if (x & (1 << i)) u = fa[u][i], x -= 1 << i;
    }
    for (int i = R; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    }
    return u == v ? u : fa[u][0];
}

inline int ddis(int u, int v) { return std::abs(deep[u] - deep[v]); }

inline mint uphs(int u, int v) {
    return ha1[u] - ha1[fa[v][0]] * pre[deep[u] - deep[v] + 1];
}

inline mint dohs(int u, int v) {
    return (ha2[v] - ha2[fa[u][0]]) * re[deep[u] - 1];
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> s + 1;
    for (int i = 0; 1 << i <= n; ++i) {
        for (int j = 1 << i; j < 1 << i + 1 && j <= n; ++j) lgs[j] = i;
    }
    for (int i = 1; i <= n; ++i) s[i] = s[i] - 'a' + D;
    pre[0] = re[0] = 1;
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] * E;
    for (int i = 1; i <= n; ++i) re[i] = re[i - 1] * F;
    for (int i = 1; i < n; ++i) {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    dfs1(1, 0), dfs2(1, 1);
    while ((1 << R + 1) <= maxd) ++R;
    std::cin >> q;
    while (q--) {
        std::cin >> pu >> pv >> qu >> qv;
        ps = lca(pu, pv), qs = lca(qu, qv);
        if (dis(pu, ps, pv) < dis(qu, qs, qv)) {
            std::swap(pu, qu), std::swap(ps, qs), std::swap(pv, qv);
        }
        d = dis(pu, ps, pv) - dis(qu, qs, qv);
        if (ddis(ps, pv) >= d) {
            pv = up(pv, d);
        } else {
            ps = pv = up(pu, dis(qu, qs, qv));
        }
        if (ddis(pu, ps) < ddis(qu, qs)) {
            std::swap(pu, qu), std::swap(ps, qs), std::swap(pv, qv);
        }
        pt = up(pu, da = ddis(qu, qs));
        db = ddis(pu, ps) - ddis(qu, qs);
        qt = up(qv, dc = ddis(ps, pv));
        if (uphs(pu, pt) != uphs(qu, qs)) {
            l = 0, r = da;
            while (l < r) {
                mid = l + r >> 1;
                if (uphs(pu, up(pu, mid)) != uphs(qu, up(qu, mid))) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            std::cout << l << '\n';
        } else if (uphs(pt, ps) != dohs(qs, qt)) {
            l = 0, r = db;
            while (l < r) {
                mid = l + r >> 1;
                if (uphs(pt, up(pt, mid)) != dohs(qs, up(qt, db - mid))) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            std::cout << da + l << '\n';
        } else if (dohs(ps, pv) != dohs(qt, qv)) {
            l = 0, r = dc;
            while (l < r) {
                mid = l + r >> 1;
                if (dohs(ps, up(pv, dc - mid)) != dohs(qt, up(qv, dc - mid))) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            std::cout << da + db + l << '\n';
        } else {
            std::cout << da + db + dc + 1 << '\n';
        }
    }
    return 0;
}