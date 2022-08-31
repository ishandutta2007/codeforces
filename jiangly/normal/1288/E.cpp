#include <iostream>
#include <numeric>
constexpr int N = 300'000;
int n, m;
int l[N], r[N], fen[2 * N + 1], pos[N];
void add(int p, int v) {
    for (int i = p + 1; i <= n + m; i += i & -i)
        fen[i] += v;
}
int sum(int p) {
    int ans = 0;
    for (int i = p; i > 0; i -= i & -i)
        ans += fen[i];
    return ans;
}
int sum(int l, int r) {
    return sum(r) - sum(l);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    std::iota(l, l + n, 0);
    std::iota(r, r + n, 0);
    for (int i = 0; i < n; ++i)
        pos[i] = n - i - 1;
    for (int i = 0; i < n; ++i)
        add(i, 1);
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        --x;
        l[x] = 0;
        r[x] = std::max(r[x], sum(pos[x] + 1, n + i));
        add(pos[x], -1);
        pos[x] = n + i;
        add(pos[x], 1);
    }
    for (int i = 0; i < n; ++i)
        r[i] = std::max(r[i], sum(pos[i] + 1, n + m));
    for (int i = 0; i < n; ++i)
        std::cout << l[i] + 1 << " " << r[i] + 1 << "\n";
    return 0;
}