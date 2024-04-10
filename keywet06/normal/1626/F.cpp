#include <bits/stdc++.h>

template <typename Type>
inline Type Gcd(Type x, Type y) {
    return y ? Gcd(y, x % y) : x;
}

template <typename Type>
inline Type Lcm(Type x, Type y) {
    return x / Gcd(x, y) * y;
}

template <typename Type>
inline auto Vector(size_t n) {
    return std::vector<Type>(n);
}

template <typename Type, typename... Args>
inline auto Vector(size_t n, Args... args) {
    return std::vector<decltype(Vector<Type>(args...))>(n, Vector<Type>(args...));
}

using int64 = long long;

const int P = 998244353;

inline int Add(int x, int y) { return (x += y) >= P ? x - P : x; }
inline int Sub(int x, int y) { return (x -= y) < 0 ? x + P : x; }
inline int Mul(int x, int y) { return int64(x) * y % P; }
inline int &Adds(int &x, int y) { return (x += y) >= P ? x -= P : x; }
inline int &Subs(int &x, int y) { return (x -= y) < 0 ? x += P : x; }
inline int &Muls(int &x, int y) { return x = int64(x) * y % P; }

template <typename... Args>
inline int Add(int x, int y, Args... args) {
    return Add(Add(x, y), args...);
}

template <typename... Args>
inline int Mul(int x, int y, Args... args) {
    return Mul(Mul(x, y), args...);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, a, x, y, k, M;
    std::cin >> n >> a >> x >> y >> k >> M;
    int m = 1;
    for (int i = 1; i < k; ++i) m = Lcm(m, i);
    std::vector<int> Po(1, 1);
    for (int i = 1; i <= k; ++i) Po.push_back(Mul(Po.back(), n));
    auto F = Vector<int>(k + 1, m);
    for (int i = 0; i < m; ++i) F[k][i] = i;
    for (int i = k - 1; i; --i) {
        for (int j = 0; j < m; ++j) {
            F[i][j] = Add(F[i + 1][j - j % i], Mul(Po[k - i], j), Mul(n - 1, F[i + 1][j]));
        }
    }
    auto GAns = [&](int n) -> int {
        return Add(F[1][n % m], Mul(n - n % m, k, Po[k - 1]));
    };
    int Ans = GAns(a);
    for (int i = 1; i < n; ++i) Adds(Ans, GAns(a = (int64(a) * x + y) % M));
    std::cout << Ans << std::endl;
    return 0;
}