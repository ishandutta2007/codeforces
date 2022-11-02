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

const int P = 998244353;

using MInt = Oct::ModInt<int, P, int64>;

const int N = 100005;

MInt Fac[N], Far[N];

inline MInt C(int m, int n) { return Fac[m] * Far[n] * Far[m - n]; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    Fac[0] = 1;
    for (int i = 1; i < N; ++i) Fac[i] = Fac[i - 1] * i;
    Far[N - 1] = ~Fac[N - 1];
    for (int i = N - 1; i; --i) Far[i - 1] = Far[i] * i;
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int l = 0, r = n - 1;
        int64 sl = 0, sr = 0, s = 0;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i], s += a[i];
        MInt Ans = 1;
        while (true) {
            if ((sl += a[l++]) << 1 >= s) break;
            while (sr < sl) sr += a[r--];
            if (sl != sr) continue;
            if (sl == 0 && !a[0] && a[n - 1]) continue;
            r -= l == 1 && a[0] == 0;
            int ln = 1, rn = 1;
            while (a[l] == 0) ++ln, ++l;
            while (a[r] == 0) ++rn, --r;
            MInt b = 1;
            for (int i = 1; i <= ln && i <= rn; ++i) b += C(ln, i) * C(rn, i);
            Ans *= b;
        }
        if (sl + sl == s) {
            Ans += s ? Ans : 0;
            while (l < n && a[l++] == 0) Ans *= 2;
        }
        std::cout << int(Ans) << '\n';
    }
    return 0;
}