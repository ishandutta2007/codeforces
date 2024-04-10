#include <iostream>
#include <vector>
#include <iomanip>
int n;
std::vector<int> a;
std::vector<std::pair<long long, int>> stk;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i) {
        long long sum = a[i];
        int cnt = 1;
        while (!stk.empty() && sum * stk.back().second <= stk.back().first * cnt) {
            sum += stk.back().first;
            cnt += stk.back().second;
            stk.pop_back();
        }
        stk.emplace_back(sum, cnt);
    }
    std::cout << std::fixed << std::setprecision(9);
    for (auto [sum, cnt] : stk)
        for (int i = 0; i < cnt; ++i)
            std::cout << 1.0 * sum / cnt << "\n";
    return 0;
}