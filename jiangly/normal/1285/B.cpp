#include <iostream>
#include <vector>
#include <numeric>
int t, n;
std::vector<int> a;
void solve() {
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    long long tot = std::accumulate(a.begin(), a.end(), 0LL);
    long long sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += a[i];
        if (sum <= 0 || sum >= tot) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}