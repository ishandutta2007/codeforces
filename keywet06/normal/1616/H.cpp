#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << ": "
#define Deline Delin << std::endl

using int32 = int;
using int64 = long long;

namespace Mods {

const int P = 998244353;

inline int Add(int x, int y) { return (x += y) >= P ? x - P : x; }
inline int Sub(int x, int y) { return (x -= y) < 0 ? x + P : x; }
inline int Mul(int x, int y) { return int64(x) * y % P; }
inline int &Adds(int &x, int y) { return (x += y) >= P ? x -= P : x; }
inline int &Subs(int &x, int y) { return (x -= y) < 0 ? x += P : x; }
inline int &Muls(int &x, int y) { return x = int64(x) * y % P; }

inline int Sqr(int x) { return Mul(x, x); }
inline int &Sqrs(int &x) { return Muls(x, x); }

inline int Pow(int Base, int Exp) {
    int Ret = 0;
    while (Exp) {
        if (Exp & 1) Muls(Ret, Base);
        Sqrs(Base), Exp >>= 1;
    }
    return Ret;
}
inline int &Pows(int &Base, int Exp) { return Base = Pow(Base, Exp); }

inline int Inv(int x) { return Pow(x, P - 2); }
inline int Invs(int x) { return Pows(x, P - 2); }

#define templ template <typename... Args>

templ inline int Add(int x, int y, Args... args) { return Add(Add(x, y), args...); }
templ inline int Sub(int x, int y, Args... args) { return Sub(Sub(x, y), args...); }
templ inline int Mul(int x, int y, Args... args) { return Mul(Mul(x, y), args...); }
templ inline int &Adds(int &x, int y, Args... args) { return Adds(Adds(x, y), args...); }
templ inline int &Subs(int &x, int y, Args... args) { return Subs(Subs(x, y), args...); }
templ inline int &Muls(int &x, int y, Args... args) { return Muls(Muls(x, y), args...); }
templ inline void Sqrs(int &x, Args... args) { Sqrs(x), Sqrs(args...); }
templ inline int Pow(int Base, int Exp, Args... args) { return Pow(Pow(Base, Exp), args...); }
templ inline int &Pows(int &Base, int Exp, Args... args) { return Pows(Pows(Base, Exp), args...); }
templ inline void Invs(int &x, Args... args) { Invs(x), Invs(args...); }

#undef templ

}  // namespace Mods

using namespace Mods;

const int B = 2;
const int C = 30;
const int N = 150005;
const int M = N * C;

int n, Cnt = 1, x;
int Pow2[N];
int Size[M], Son[M][B];

inline int O(int x) { return Sub(Pow2[x], 1); }

inline int f(int u, int v, int c) {
    if (!u || !v) return 0;
    if (c < 0) return Mul(O(Size[u]), O(Size[v]));
    if (!(x >> c & 1)) return Add(f(Son[u][0], Son[v][0], c - 1), f(Son[u][1], Son[v][1], c - 1));
    int x = f(Son[u][0], Son[v][1], c - 1), y = f(Son[u][1], Son[v][0], c - 1);
    int ul = O(Size[Son[u][0]]), ur = O(Size[Son[u][1]]), vl = O(Size[Son[v][0]]), vr = O(Size[Son[v][1]]);
    return Add(Mul(ul, vl), Mul(ur, vr), Mul(Add(ur, vl, 1), x), Mul(Add(ul, vr, 1), y), Mul(x, y));
}

inline int f(int u, int c) {
    if (!u) return 0;
    if (c < 0) return O(Size[u]);
    if (!(x >> c & 1)) return Add(f(Son[u][0], c - 1), f(Son[u][1], c - 1));
    return Add(O(Size[Son[u][0]]), O(Size[Son[u][1]]), f(Son[u][0], Son[u][1], c - 1));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> x;
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x;
        for (int c = C - 1, u = 1; c >= 0; --c) {
            ++Size[u = Son[u][x >> c & 1] ? Son[u][x >> c & 1] : (Son[u][x >> c & 1] = ++Cnt)];
        }
    }
    Pow2[0] = 1;
    for (int i = 1; i <= n; ++i) Pow2[i] = Mul(Pow2[i - 1], 2);
    std::cout << f(1, C - 1) << std::endl;
    return 0;
}