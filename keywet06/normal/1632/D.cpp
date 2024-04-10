// Luogu Remote

#include <bits/stdc++.h>

using int64 = long long;

template <typename Type>
inline Type Gcd(Type x, Type y) {
    return y ? Gcd(y, x % y) : x;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    auto Set = [&](int x, int c) -> void {
        x = n - x + 1;
        while (x <= n) a[x] = Gcd(a[x], c), x += x & -x;
    };
    auto Query = [&](int x) -> int {
        x = n - x + 1;
        int Ret = 0;
        while (x) Ret = Gcd(Ret, a[x]), x &= x - 1;
        return Ret;
    };
    int Num = 0, Max = 0, Left = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x, ++Max;
        Set(i, x);
        while (Query(Left) < i - Left + 1) ++Left;
        if (Query(Left) == i - Left + 1 && i - Left + 1 <= Max) Max = 0, ++Num;
        std::cout << Num << " \n"[i == n];
    }
    return 0;
}