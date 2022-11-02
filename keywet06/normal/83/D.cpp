#include <bits/stdc++.h>

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

using int64 = long long;

const int N = 5005;

int a, b, k, m;
int pr[N];

int64 res = 0;

void rec(int index, int64 lcm, int coef = 1) {
    if (lcm > b) return;
    int64 t = int64(b) / lcm - int64(a - 1) / lcm;
    res += coef == 1 ? t : -t;
    for (int i = index; i < m && pr[i] < k && pr[i] * lcm <= int64(b); ++i) {
        rec(i + 1, lcm * pr[i], -coef);
    }
}

int main() {
    std::cin >> a >> b >> k;
    if (!isPrime(k)) return std::cout << 0 << std::endl, 0;
    for (int i = 2; i < 45000; ++i) {
        if (isPrime(i)) pr[m++] = i;
    }
    if (k > 45000) {
        int res = 0;
        for (int64 i = k; i <= b; i += k) {
            if (i < a) continue;
            bool ok = true;
            for (int j = 0; j < m; ++j) {
                if (i % pr[j] == 0 && (ok = false, 1)) break;
            }
            res += ok;
        }
        return std::cout << res << std::endl, 0;
    }
    rec(0, k);
    std::cout << res << std::endl;
    return 0;
}