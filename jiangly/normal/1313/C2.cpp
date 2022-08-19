#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::vector<int> a;
std::vector<long long> f;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    f.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    long long sum = 0;
    std::vector<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && a[i] <= a[stk.back()]) {
            int j = stk.back();
            stk.pop_back();
            sum -= 1ll * (j - (stk.empty() ? -1 : stk.back())) * a[j];
        }
        sum += 1ll * (i - (stk.empty() ? -1 : stk.back())) * a[i];
        f[i] += sum;
        stk.push_back(i);
    }
    sum = 0;
    stk.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && a[i] <= a[stk.back()]) {
            int j = stk.back();
            stk.pop_back();
            sum -= 1ll * ((stk.empty() ? n : stk.back()) - j) * a[j];
        }
        sum += 1ll * ((stk.empty() ? n : stk.back()) - i) * a[i];
        f[i] += sum - a[i];
        stk.push_back(i);
    }
    int p = std::max_element(f.begin(), f.end()) - f.begin();
    for (int i = p - 1; i >= 0; --i)
        a[i] = std::min(a[i], a[i + 1]);
    for (int i = p + 1; i < n; ++i)
        a[i] = std::min(a[i], a[i - 1]);
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " \n"[i == n - 1];
    return 0;
}