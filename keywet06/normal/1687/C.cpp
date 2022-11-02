#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl

using int64 = long long;
// using int128 = __int128;
using uint64 = unsigned long long;
using fuint64 = uint_fast64_t;

inline int64 ChronoClock() { return std::chrono::system_clock::now().time_since_epoch().count(); }

inline std::mt19937_64 &RandMachine() {
    static std::mt19937_64 Ret(ChronoClock());
    return Ret;
}

inline std::mt19937_64 &SRand(const fuint64 Seed = ChronoClock()) { return RandMachine() = std::mt19937_64(Seed); }

inline fuint64 Random() { return RandMachine()(); }

template <typename Type>
inline Type Random(const Type n) {
    return Random() % n;
}

template <typename Type>
inline Type Random(Type l, Type r) {
    return Random(r - l) + l;
}

template <typename BType, typename EType, typename MType>
inline BType Pow(BType Base, EType Exp, MType Mod) {
    BType Ret(1);
    while (Exp) {
        if (Exp & 1) Ret = Ret * Base % Mod;
        Base = Base * Base % Mod, Exp >>= 1;
    }
    return Ret;
}

template <typename Type>
inline Type Gcd(Type x, Type y) {
    return y == Type(0) ? x : Gcd(y, x % y);
}

template <typename Type>
inline Type Abs(Type x) {
    return x > 0 ? x : -x;
}

const int MillerRabinTestElements[] = {2, 3, 5, 7, 11, 13, 82, 373};

template <typename Type>
inline bool MillerRabin(Type n) {
    if (n <= 2 || !(n & 1)) return n == 2;
    Type e = n - 1, u;
    size_t w = 0, i;
    while (!(e & 1)) ++w, e >>= 1;
    for (const int &t : MillerRabinTestElements) {
        if (!(t % n)) continue;
        u = Pow(Type(t), e, n);
        if (u == Type(1)) continue;
        for (i = 0; i < w; ++i) {
            if (u == Type(n - 1)) break;
            if (u == Type(1)) return false;
            u = u * u % n;
        }
        if (i == w) return false;
    }
    return true;
}

template <typename Type>
inline Type PollardRho(Type n) {
    Type x = Random(Type(1), n), c = Random(Type(1), n), y = x, p = 1, d;
    for (size_t k = 4; k <= 16384; k <<= 1) {
        for (size_t step = 0; step < k; ++step) {
            x = (x * x + c) % n;
            p = p * Abs(x - y) % n;
            if (!(step & 127)) {
                d = Gcd(p, n);
                if (d > 1) return d;
            }
        }
        d = Gcd(p, n), y = x, p = 1;
        if (d > 1) return d;
    }
    return 0;
}

template <typename Type, typename RetType = std::vector<Type>>
inline RetType &GetFac(Type n, RetType &Ret) {
    if (n <= 1) return Ret;
    if (MillerRabin(n)) return Ret.push_back(n), Ret;
    Type d = PollardRho(n);
    while (!d && d != n) d = PollardRho(n);
    return GetFac(d, Ret), GetFac(n / d, Ret);
}

template <typename Type, typename RetType = std::vector<Type>>
inline RetType GetFac(Type n) {
    RetType Ret;
    return GetFac(n, Ret);
}

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void Solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    DSU dsu(n + 2);

    std::vector<int64> sa(n + 1), sb(n + 1);
    for (int i = 0; i < n; ++i) sa[i + 1] = sa[i] + a[i], sb[i + 1] = sb[i] + b[i];

    std::vector<int> l(m), r(m), deg(m);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        std::cin >> l[i] >> r[i];
        --l[i], deg[i] = 2;
        g[l[i]].push_back(i);
        g[r[i]].push_back(i);
    }
    std::function<void(int)> set = [&](int i) {
        dsu.merge(i + 1, i);
        for (auto j : g[i]) {
            if (--deg[j] == 0) {
                int x = dsu.leader(l[j]);
                while (x <= r[j]) {
                    set(x);
                    x = dsu.leader(x);
                }
            }
        }
    };
    for (int i = 0; i <= n; ++i) {
        if (sa[i] == sb[i]) set(i);
    }
    if (dsu.leader(0) == n + 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}