#include <bits/stdc++.h>

using uint64 = unsigned long long;
using float96 = long double;

const int N = 2222;

int n, k;

float96 fact[N];

std::vector<std::pair<int, int> > g[N];

inline float96 calc(int n, int k) { return fact[n] - fact[k] - fact[n - k]; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    fact[0] = 0;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] + logl(float96(i));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x;
            std::cin >> x;
            if (x != -1) {
                g[i].emplace_back(j, x);
                g[j].emplace_back(i, x);
            }
        }
    }
    float96 ans = 0;
    float96 denom = calc(n, k);
    for (int x = 0; x < n; ++x) {
        if (g[x].size() >= k) {
            float96 sum = 0;
            for (int i = 0; i < g[x].size(); ++i) sum += g[x][i].second;
            float96 factor = expl(calc(g[x].size() - 1, k - 1) - denom);
            ans += factor * sum;
        }
    }
    std::cout << uint64(ans + 1e-8) << std::endl;
    return 0;
}