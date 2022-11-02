#include <bits/stdc++.h>

using int64 = long long;

const int N = 120000;

int n;
int tp[N], nx[N];

int64 c, d;
int64 t[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> c >> d;
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
        char c;
        std::cin >> c;
        tp[i] = c != 'W';
    }
    std::cin >> t[n];
    tp[n] = 2;
    for (int i = n - 1; i >= 0; --i) nx[i] = tp[i] != tp[i + 1] ? i + 1 : nx[i + 1];
    int64 ans = d * n, cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (tp[i + 1] == tp[i]) cur += std::min(d, (t[nx[i + 1]] - t[i + 1]) * c);
        ans = std::min(ans, i * d + cur + (t[n] - t[i]) * c);
    }
    std::cout << ans << "\n";
    return 0;
}