#include <bits/stdc++.h>

const int P = 1000000007;

inline void Add(int &a, int b) {
    a += b;
    if (a >= P) a -= P;
}

inline int Mul(int a, int b) { return (long long)a * b % P; }

inline int Pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = Mul(res, a);
        a = Mul(a, a), b >>= 1;
    }
    return res;
}

inline int inv(int x) { return Pow(x, P - 2); }

int deg[1234567];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0, foo, bar; i < n - 1; ++i) std::cin >> foo >> bar, --foo, --bar, ++deg[foo], ++deg[bar];
    if (n == 1) return std::cout << 1 << std::endl, 0;
    int Lea = 0;
    for (int i = 0; i < n; ++i) Lea += (deg[i] == 1);
    int Ans = 0;
    for (int i = 0; i < n; ++i) Add(Ans, Pow(2, n - (Lea - (deg[i] == 1))));
    std::cout << Ans << std::endl;
    return 0;
}