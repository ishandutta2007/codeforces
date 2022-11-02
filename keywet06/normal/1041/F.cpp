#include <bits/stdc++.h>

using int64 = long long;

const int N = 200100;

int n, m, y, ur;
int A[N], B[N];
std::map<int, int> Map;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> y;
    for (int i = 0; i < n; ++i) std::cin >> A[i];
    std::cin >> m >> ur;
    for (int i = 0; i < m; ++i) std::cin >> B[i];
    int v = 1;
    int ans = 0;
    for (int p2 = 0; p2 <= 30; ++p2) {
        Map.clear();
        int v2 = v * 2;
        if (p2 == 30) v2 = v;
        for (int i = 0; i < n; ++i) ++Map[A[i] % v2];
        for (int i = 0; i < m; ++i) ++Map[(B[i] + v) % v2];
        for (auto it : Map) ans = std::max(ans, it.second);
        v = v2;
    }
    std::cout << ans << "\n";
}