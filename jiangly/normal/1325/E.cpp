#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
constexpr int N = 1e3, C = 169, A = 1e6;
int isPrime[N + 1];
std::vector<int> primes;
std::vector<int> e[A];
int d1[A], f1[A], d2[A], f2[A];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i] == 0) {
            primes.push_back(i);
            isPrime[i] = primes.size();
            for (int j = 2 * i; j <= N; j += i)
                isPrime[j] = -1;
        }
    }
    int n;
    std::cin >> n;
    int ans = n + 1;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        std::vector<int> d;
        for (int p : primes) {
            int t = 0;
            while (a % p == 0) {
                a /= p;
                ++t;
            }
            if (t % 2 == 1)
                d.push_back(isPrime[p]);
        }
        if (a == 1) {
            if (d.empty()) {
                std::cout << 1 << "\n";
                return 0;
            } else if (int(d.size()) == 1) {
                e[d[0]].push_back(0);
                e[0].push_back(d[0]);
            } else {
                e[d[0]].push_back(d[1]);
                e[d[1]].push_back(d[0]);
            }
        } else if (d.empty()) {
            e[0].push_back(a);
            e[a].push_back(0);
        } else {
            e[d[0]].push_back(a);
            e[a].push_back(d[0]);
        }
    }
    for (int i = 0; i < C; ++i) {
        std::fill(d1, d1 + A, -1);
        std::fill(d2, d2 + A, -1);
        std::sort(e[i].begin(), e[i].end());
        if (std::unique(e[i].begin(), e[i].end()) != e[i].end()) {
            std::cout << 2 << "\n";
            return 0;
        }
        std::queue<std::tuple<int, int, int>> q;
        for (int v : e[i])
            q.emplace(v, 1, v);
        while (!q.empty()) {
            auto [u, d, f] = q.front();
            q.pop();
            if (d1[u] == -1) {
                d1[u] = d;
                f1[u] = f;
            } else if (d2[u] == -1 && f1[u] != f) {
                d2[u] = d;
                f2[u] = f;
            } else {
                continue;
            }
            for (int v : e[u])
                if (v != i)
                    q.emplace(v, d + 1, f);
        }
        for (int v : e[i])
            if (d2[v] != -1)
                ans = std::min(ans, d2[v] + 1);
    }
    if (ans > n) {
        std::cout << -1 << "\n";
    } else {
        std::cout << ans << "\n";
    }
    return 0;
}