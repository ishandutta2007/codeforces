#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
int n;
std::vector<int> a;
std::vector<long long> ans;
std::map<std::vector<int>, long long> res;
std::vector<long long> chain;
std::vector<std::vector<long long>> chaint;
void dfs(int r, int x, std::vector<long long> g) {
    if (r == 0) {
        long long v = 0;
        for (int i = 0; i < (1 << n); ++i)
            v += __builtin_parity(((1 << n) - 1) ^ i) ? -g[i] : g[i];
        res[a] = v;
        return;
    }
    for (int i = x; i <= r; ++i) {
        if (i != r && 2 * i > r)
            continue;
        a.push_back(i);
        auto g0 = g;
        for (int j = 0; j < (1 << n); ++j)
            g0[j] *= chaint[i][j];
        dfs(r - i, i, g0);
        a.pop_back();
    }
}
void f(std::vector<long long> &v) {
    for (int i = 1; i < (1 << n); i *= 2)
        for (int j = 0; j < (1 << n); j += 2 * i)
            for (int k = 0; k < i; ++k)
                v[i + j + k] += v[j + k];
}
void h(std::vector<long long> &v) {
    for (int i = 1; i < (1 << n); i *= 2)
        for (int j = 0; j < (1 << n); j += 2 * i)
            for (int k = 0; k < i; ++k)
                v[j + k] -= v[i + j + k];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    std::vector<std::vector<bool>> g(n, std::vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            std::cin >> c;
            g[i][j] = c - '0';
        }
    }
    chaint.assign(1 << n, std::vector<long long>(n));
    chain.resize(1 << n);
    for (int s = 1; s < (1 << n); ++s) {
        if ((s & -s) == s) {
            chaint[s][__builtin_ctz(s)] = 1;
        } else {
            for (int v = 0; v < n; ++v)
                if (s >> v & 1)
                    for (int u = 0; u < n; ++u)
                        if (g[u][v] && (s >> u & 1))
                            chaint[s][v] += chaint[s ^ 1 << v][u];
        }
        for (int i = 0; i < n; ++i)
            chain[s] += chaint[s][i];
    }
    chaint.assign(n + 1, std::vector<long long>(1 << n));
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < (1 << n); ++s)
            if (__builtin_popcount(s) == i)
                chaint[i][s] = chain[s];
        f(chaint[i]);
    }
    dfs(n, 1, std::vector<long long>(1 << n, 1));
    ans.resize(1 << n);
    for (int s = 0; s < (1 << (n - 1)); ++s) {
        std::vector<int> a;
        int l = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (~s >> i & 1) {
                a.push_back(i - l);
                l = i;
            }
        }
        a.push_back(n - 1 - l);
        std::sort(a.begin(), a.end());
        ans[s] = res[a];
    }
    --n;
    h(ans);
    for (int i = 0; i < (1 << n); ++i)
        std::cout << ans[i] << " \n"[i == (1 << n) - 1];
    return 0;
}