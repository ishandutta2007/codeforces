#include <bits/stdc++.h>

#ifndef OCT_MODINT_HPP
#define OCT_MODINT_HPP

namespace Oct {

template <typename Type, Type P, typename MulType = Type>
class ModInt {
   protected:
    Type x;

   public:
    using Self = ModInt<Type, P, MulType>;
    ModInt() : x(0) {}
    ModInt(Type c) : x(c) {}
    explicit operator Type() { return x; }
    Type &Data() { return x; }
    friend Self operator+(Self a, Self b) { return (a.x += b.x) >= P ? a.x - P : a.x; }
    friend Self operator-(Self a, Self b) { return (a.x -= b.x) < 0 ? a.x + P : a.x; }
    friend Self operator*(Self a, Self b) { return MulType(a.x) * b.x % P; }
    friend Self &operator+=(Self &a, Self b) { return (a.x += b.x) >= P ? a.x -= P, a : a; }
    friend Self &operator-=(Self &a, Self b) { return (a.x -= b.x) < 0 ? a.x += P, a : a; }
    friend Self &operator*=(Self &a, Self b) { return a.x = MulType(a.x) * b.x % P, a; }
#define templ template <typename ExpType>
    templ Self Pow(ExpType Exp) {
        Self Base(*this), Ret(1);
        while (Exp) {
            if (Exp & 1) Ret *= Base;
            Base *= Base, Exp >>= 1;
        }
        return Ret;
    }
    templ Self &Pows(ExpType Exp) { return *this = Pow(Exp); }
    templ Self &PowEq(ExpType Exp) { return Pows(Exp); }
    templ Self &PowEqual(ExpType Exp) { return Pows(Exp); }
    templ friend Self Pow(Self Base, ExpType Exp) { return Base.Pow(Exp); }
#undef templ
    Self Inv() { return Pow(P - 2); }
    Self &Invs() { return Pows(P - 2); }
    Self &InvEq() { return Invs(); }
    Self &InvEqual() { return Invs(); }
    friend Self Inv(Self x) { return x.Pow(P - 2); }
    friend Self operator~(Self x) { return x.Inv(); }
    friend Self operator/(Self a, Self b) { return a * ~b; }
    friend Self &operator/=(Self &a, Self b) { return a *= ~b; }
    friend Self &operator++(Self &a) { return a += 1; }
    friend Self &operator--(Self &a) { return a -= 1; }
    friend Self operator++(Self &a, int) {
        Self Tmp = a;
        return a += 1, Tmp;
    }
    friend Self operator--(Self &a, int) {
        Self Tmp = a;
        return a -= 1, Tmp;
    }
    friend Self operator+(Self a) { return a; }
    friend Self operator-(Self a) { return 0 - a; }
    bool operator==(Self a) { return x == int(a); }
};

}  // namespace Oct

#endif

using int64 = long long;

const int P = 1000000007;

using MInt = Oct::ModInt<int, P, int64>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> To(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        std::cin >> u >> v, --u, --v;
        To[u].push_back(v);
        To[v].push_back(u);
    }
    std::vector<MInt> Bi(n + 1);
    Bi[k] = 1;
    for (int i = k + 1; i <= n; ++i) Bi[i] = Bi[i - 1] * i / (i - k);
    MInt Ans = Bi[n] * n * n;
    std::vector<int> siz(n);
    std::vector<MInt> f(n);
    std::function<void(int, int)> Dfs1 = [&](int u, int p) {
        siz[u] = 1;
        for (auto v : To[u]) {
            if (v == p) continue;
            Dfs1(v, u), siz[u] += siz[v], f[u] -= Bi[siz[v]];
        }
        f[u] += Bi[siz[u]];
        if (u != 0) Ans += f[u] * siz[u] * (n - siz[u]), Ans -= Bi[siz[u]] * n;
    };
    Dfs1(0, -1);
    std::function<void(int, int)> Dfs2 = [&](int u, int p) {
        for (auto v : To[u]) {
            if (v == p) continue;
            Ans += (f[u] - Bi[siz[u]] + Bi[siz[v]] - Bi[n - siz[u]] + Bi[n - siz[v]]) * siz[v] * (n - siz[v]);
            Ans -= Bi[n - siz[v]] * n, Dfs2(v, u);
        }
    };
    Dfs2(0, -1);
    std::cout << int(Ans) << "\n";
    return 0;
}