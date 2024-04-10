#include <bits/stdc++.h>

int n;

std::vector<long long> a;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

int randNum(int n) { return rnd() % n; }

long long solvePrime(long long p) {
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long l = a[i] - a[i] % p;
        if (l != 0) {
            res += std::min(a[i] - l, l + p - a[i]);
        } else {
            res += p - a[i];
        }
    }
    return res;
}

long long solve(long long x) {
    long long res = n;
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            res = std::min(res, solvePrime(i));
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) res = std::min(res, solvePrime(x));
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    long long ans = n;
    std::random_shuffle(a.begin(), a.end(), randNum);
    for (int i = 0; i < std::min(30, n); ++i) {
        if (a[i] > 1) ans = std::min(ans, solve(a[i] - 1));
        ans = std::min(ans, solve(a[i]));
        ans = std::min(ans, solve(a[i] + 1));
    }
    std::cout << ans << "\n";
    return 0;
}