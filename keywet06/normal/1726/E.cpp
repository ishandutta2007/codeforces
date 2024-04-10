#include <bits/stdc++.h>

using int32 = int;
using int64 = long long;
using uint32 = unsigned int;
using uint64 = unsigned long long;

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

inline int BiBlm(int32 x) { return 1 << 32 - BiClz(x - 1); }

const int P = 998244353;

inline std::ostream &operator<<(std::ostream &out, std::vector<int> A) {
    out << '[';
    for (int i = 0, f = 0; i < A.size(); ++i) {
        if (f) out << ", ";
        f = 1, out << (A[i] > P / 2 ? A[i] - P : A[i]);
    }
    out << ']';
    return out;
}

const int G = 3;

inline int Add(int x, int y) { return (x += y) >= P ? x - P : x; }
inline int Sub(int x, int y) { return (x -= y) < 0 ? x + P : x; }
inline int Mul(int x, int y) { return int64(x) * y % P; }
inline int &Adds(int &x, int y) { return (x += y) >= P ? (x -= P) : x; }
inline int &Subs(int &x, int y) { return (x -= y) < 0 ? (x += P) : x; }
inline int &Muls(int &x, int y) { return x = int64(x) * y % P; }

template <typename... Args>
inline int Mul(int x, int y, Args... args) {
    return Mul(Mul(x, y), args...);
}

inline int Pow(int Base, int Exp) {
    int Ret(1);
    while (Exp) {
        if (Exp & 1) Muls(Ret, Base);
        Muls(Base, Base), Exp >>= 1;
    }
    return Ret;
}

inline int Inv(int x) { return Pow(x, P - 2); }

const int M = 1 << 21;

inline std::vector<int> NTT(std::vector<int> f, bool Flag) {
    static struct NTTBase {
        std::vector<int> Rev, W;
        NTTBase(int n) : Rev(n), W(n) {
            int c = BiCtz(n) - 1;
            for (int i = 1; i < n; ++i) {
                Rev[i] = Rev[i >> 1] >> 1 | (i & 1) << c;
            }
            int x = Pow(G, (P - 1) >> c);
            W[n >> 1] = 1;
            for (int i = n >> 1 | 1; i < n; ++i) W[i] = Mul(W[i - 1], x);
            for (int i = (n >> 1) - 1; i >= 0; --i) W[i] = W[i << 1];
        }
    } Base(M);
    int n = f.size(), e = BiBlm(n);
    int Shift = BiCtz(M) - BiCtz(e);
    f.resize(n = e);
    for (int i = 1; i < n; ++i) {
        int x = Base.Rev[i] >> Shift;
        if (x > i) std::swap(f[x], f[i]);
    }
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; ++k) {
                int x = f[j | k], y = Mul(f[j | i | k], Base.W[i << 1 | k]);
                f[j | k] = Add(x, y);
                f[j | i | k] = Sub(x, y);
            }
        }
    }
    if (Flag) {
        std::reverse(f.begin() + 1, f.end());
        int x = Inv(n);
        for (int i = 0; i < n; ++i) Muls(f[i], x);
    }
    return f;
}

inline std::vector<int> NTT(std::vector<int> f) { return NTT(f, false); }
inline std::vector<int> INTT(std::vector<int> f) { return NTT(f, true); }

inline std::vector<int> Mul(int x, std::vector<int> A) {
    for (int &u : A) Muls(u, x);
    return A;
}

inline std::vector<int> Sub(std::vector<int> A, std::vector<int> B) {
    int d = std::max(A.size(), B.size());
    A.resize(d), B.resize(d);
    std::vector<int> C(d);
    for (int i = 0; i < d; ++i) C[i] = Sub(A[i], B[i]);
    return C;
}

inline std::vector<int> Mul(std::vector<int> A, std::vector<int> B) {
    int n = A.size(), m = B.size(), d = n + m - 1, r = BiBlm(d);
    std::vector<int> TA(A), TB(B);
    A.resize(r), B.resize(r);
    A = NTT(A), B = NTT(B);
    for (int i = 0; i < r; ++i) Muls(A[i], B[i]);
    A = INTT(A);
    A.resize(d);
    return A;
}

inline std::vector<int> Inv(std::vector<int> A) {
    if (A.size() == 1) return A[0] = Inv(A[0]), A;
    int n = A.size(), m = n + 1 >> 1;
    std::vector<int> C(A);
    C.resize(m), C = Inv(C);
    std::vector<int> B(Sub(Mul(2, C), Mul(A, Mul(C, C))));
    B.resize(n);
    return B;
}

const int N = 300000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    std::vector<int> f(N + 1), g(N + 1), h(N + 1), Fac(N + 1), Iac(N + 1);
    Fac[0] = 1;
    for (int i = 1; i <= N; ++i) Fac[i] = Mul(Fac[i - 1], i);
    Iac[N] = Inv(Fac[N]);
    for (int i = N; i; --i) Iac[i - 1] = Mul(Iac[i], i);
    g[0] = h[0] = 1;
    for (int i = 0; i <= N; ++i) f[i] = 1;
    for (int i = 2; i <= N; i += 2) g[i] = Mul(g[i - 2], i - 1);
    for (int i = 4; i <= N; i += 4) h[i] = Mul(h[i - 4], i - 2);
    for (int i = N; i; --i) f[i] = Mul(f[i], Iac[i]), g[i] = Mul(g[i], Iac[i]);
    f = Mul(f, g), f.resize(N + 1);
    for (int i = 1; i <= N; ++i) f[i] = Mul(f[i], Fac[i]);
    while (T--) {
        int n;
        std::cin >> n;
        int Ans = 0;
        for (int i = 0; i <= n; i += 4) Adds(Ans, Mul(h[i], f[n - i], Fac[i / 2 + (n - i)], Iac[i / 2], Iac[n - i]));
        std::cout << Ans << '\n';
    }
    return 0;
}