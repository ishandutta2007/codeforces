#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> m(n), k(n);
    for (int i = 0; i < n; i++) {
        std::cin >> m[i] >> k[i];
        m[i]--;
    }
    
    const int N = 2E5;
    
    i64 resn = 0, resd = 1;
    std::vector<int> idx;
    for (int c = 1; c <= 20; c++) {
        std::vector<int> s(N);
        for (int i = 0; i < n; i++) {
            s[m[i]] += std::min(c, k[i]);
        }
        std::vector<int> p(N);
        std::iota(p.begin(), p.end(), 0);
        std::nth_element(p.begin(), p.end() - c, p.end(), [&](int i, int j) { return s[i] < s[j]; });
        i64 sum = 0;
        for (int i = N - c; i < N; i++) {
            sum += s[p[i]];
        }
        if (sum * resd > resn * c) {
            resn = sum;
            resd = c;
            idx.assign(p.end() - c, p.end());
        }
    }
    
    std::cout << idx.size() << '\n';
    for (auto x : idx) {
        std::cout << x + 1 << " \n"[x == idx.back()];
    }
    
    return 0;
}