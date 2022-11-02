#include <bits/stdc++.h>

using int32 = int;
using int64 = long long;

inline int BiFfs(int32 x) { return __builtin_ffs(x); }
inline int BiClz(int32 x) { return __builtin_clz(x); }
inline int BiCtz(int32 x) { return __builtin_ctz(x); }
inline int BiPop(int32 x) { return __builtin_popcount(x); }
inline int BiPar(int32 x) { return __builtin_parity(x); }
inline int BiFfs(int64 x) { return __builtin_ffsll(x); }
inline int BiClz(int64 x) { return __builtin_clzll(x); }
inline int BiCtz(int64 x) { return __builtin_ctzll(x); }
inline int BiPop(int64 x) { return __builtin_popcountll(x); }
inline int BiPar(int64 x) { return __builtin_parityll(x); }

const int P = 998244353;

inline int Add(int x, int y) { return (x += y) >= P ? x - P : x; }
inline int Sub(int x, int y) { return (x -= y) < 0 ? x + P : x; }
inline int Mul(int x, int y) { return int64(x) * y % P; }
inline int &Adds(int &x, int y) { return (x += y) >= P ? x -= P : x; }
inline int &Subs(int &x, int y) { return (x -= y) < 0 ? x += P : x; }
inline int &Muls(int &x, int y) { return x = int64(x) * y % P; }

inline int Sqr(int x) { return Mul(x, x); }
inline int &Sqrs(int &x) { return Muls(x, x); }

inline int Pow(int Base, int64 Exp) {
    int Ret(1);
    while (Exp) {
        if (Exp & 1) Muls(Ret, Base);
        Sqrs(Base), Exp >>= 1;
    }
    return Ret;
}

inline int Inv(int x) { return Pow(x, P - 2); }

inline int &Pows(int &Base, int64 Exp) { return Base = Pow(Base, Exp); }
inline int &Invs(int &x) { return Pows(x, P - 2); }

inline int Div(int x, int y) { return Mul(x, Inv(y)); }
inline int &Divs(int &x, int y) { return Muls(x, Inv(y)); }

#define templ template <typename... Args>

templ int Add(int x, int y, Args... args) { return Add(Add(x, y), args...); }
templ int Sub(int x, int y, Args... args) { return Sub(Sub(x, y), args...); }
templ int Mul(int x, int y, Args... args) { return Mul(Mul(x, y), args...); }
templ int Div(int x, Args... args) { return Mul(x, Inv(Mul(args...))); }
templ int &Adds(int &x, int y, Args... args) { return Adds(Adds(x, y), args...); }
templ int &Subs(int &x, int y, Args... args) { return Subs(Subs(x, y), args...); }
templ int &Muls(int &x, int y, Args... args) { return Muls(Muls(x, y), args...); }
templ int &Divs(int &x, Args... args) { return Muls(x, Inv(Mul(args...))); }

#undef templ

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    const int N = 200001;
    std::vector<int> Num(N), Fen(N);
    auto Upd = [&](int i, int v) -> void {
        while (i < N) Adds(Fen[i], v), i += i & -i;
    };
    auto Sum = [&](int i) -> int {
        int Ret = 0;
        while (i) Adds(Ret, Fen[i]), i &= i - 1;
        return Ret;
    };
    int Mu = 1;
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x, ++Num[x], Divs(Muls(Mu, std::max(1, i)), Num[x]);
        Upd(x, 1);
    }
    int Ans = 0;
    for (int i = 0, x; i < m; ++i) {
        std::cin >> x, Adds(Ans, Mul(Mu, Sum(x - 1)));
        if (!Num[x]) break;
        if (i == n - 1 && m > n) Adds(Ans, 1);
        --Num[x], Upd(x, Sub(0, 1));
        Muls(Divs(Mu, n - i - 1), Num[x] + 1);
    }
    std::cout << Ans << std::endl;
    return 0;
}