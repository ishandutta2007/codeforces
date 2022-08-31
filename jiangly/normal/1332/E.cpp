#include <iostream>
#include <vector>
#include <algorithm>
constexpr int P = 998244353;
struct P2 {
    int x, y;
    P2(int x, int y) : x(x), y(y) {}
    friend P2 operator*(const P2 &a, const P2 &b) {
        return P2((1ll * a.x * b.x + 1ll * a.y * b.y) % P, (1ll * a.x * b.y + 1ll * a.y * b.x) % P);
    }
};
P2 power(P2 base, long long e) {
    P2 res(1, 0);
    while (e > 0) {
        if (e % 2 == 1)
            res = res * base;
        base = base * base;
        e /= 2;
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, L, R;
    std::cin >> n >> m >> L >> R;
    R = R - L + 1;
    if (n % 2 == 0 || m % 2 == 0) {
        std::cout << power(P2(R / 2, R - R / 2), 1ll * n * m).x << "\n";
    } else {
        std::cout << power(P2(R, 0), 1ll * n * m).x << "\n";
    }
    return 0;
}