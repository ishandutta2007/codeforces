#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> deg(n), s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> deg[i] >> s[i];
    }
    int m = std::accumulate(deg.begin(), deg.end(), 0) / 2;
    std::cout << m << "\n";
    for (int i = 0; i < n; i++) {
        int j = i;
        while (deg[j] == 1) {
            std::cout << j << " " << s[j] << "\n";
            s[s[j]] ^= j;
            deg[j]--;
            deg[s[j]]--;
            j = s[j];
        }
    }
    return 0;
}