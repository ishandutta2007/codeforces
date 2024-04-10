#include <bits/stdc++.h>

using int64 = long long;

const int P = 1000000007;

int t;
int64 n, r, aux;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        n /= 2;
        aux = ((n + 1) / 2) % P;
        r = aux * (aux + 1) % P;
        if (n % 2 == 0) r += n / 2 + 1;
        r %= P;
        std::cout << r << '\n';
    }
    return 0;
}