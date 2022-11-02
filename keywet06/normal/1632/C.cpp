// Luogu Remote

#include <bits/stdc++.h>

template <typename Type1, typename Type2>
inline Type1 &Mid(Type1 &x, Type2 y) {
    return x < y ? x : (x = y);
}

inline int Get(int a, int b) {
    int Ret = 0;
    for (int i = 20; i >= 0; --i) {
        if ((b >> i) & 1) {
            Ret |= 1 << i;
        } else {
            if ((a >> i) & 1) return (Ret | a) - b + 1;
        }
    }
    return Ret - b + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int a, b;
        std::cin >> a >> b;
        int Ans = 1e9;
        Mid(Ans, b - a);
        for (int i = a; i < b; ++i) Mid(Ans, Get(i, b) + i - a);
        std::cout << Ans << '\n';
    }
    return 0;
}