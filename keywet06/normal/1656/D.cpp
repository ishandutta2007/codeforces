#include <bits/stdc++.h>

using int64 = long long;
using int128 = __int128;
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

int64 T, N, Ans;

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

template <typename Type>
inline void GetFac(Type n) {
    if (Ans != -1) return;
    if (n <= 1) return;
    if (MillerRabin(n)) {
        if (n > 2 && N >= n * (n + 1) / 2) Ans = n;
        return;
    }
    Type d = PollardRho(n);
    while (!d && d != n) d = PollardRho(n);
    return GetFac(d), GetFac(n / d);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        Ans = -1;
        for (int128 i = 2; i <= N; i *= 2) {
            if (i * (i + 1) / 2 % i == N % i && N >= i * (i + 1) / 2) {
                Ans = i;
                break;
            }
        }
        GetFac(int128(N));
        std::cout << Ans << '\n';
    }
    return 0;
}