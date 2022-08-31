#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::vector<bool> a;
std::vector<int> stk, cnt, mu;
std::vector<std::vector<int>> divisors;
long long ans;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (int(a.size()) <= x)
            a.resize(x + 1);
        a[x] = true;
        ans = std::max(ans, 1LL * x);
    }
    int m = a.size() - 1;
    mu.resize(m + 1);
    mu[1] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 2 * i; j <= m; j += i)
            mu[j] -= mu[i];
    divisors.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; j += i) { 
            if (mu[i] != 0)
                divisors[j].push_back(i);
            a[i] = a[i] || a[j];
        }
    }
    cnt.resize(m + 1);
    for (int i = m; i >= 1; --i) {
        if (!a[i])
            continue;
        int num = 0;
        for (int j : divisors[i])
            num += mu[j] * cnt[j];
        while (num > 0) {
            int lst = num;
            for (int j : divisors[stk.back()]) {
                --cnt[j];
                if (i % j == 0)
                    num -= mu[j];
            }
            if (lst != num)
                ans = std::max(ans, 1LL * i * stk.back());
            stk.pop_back();
        }
        for (int j : divisors[i])
            ++cnt[j];
        stk.push_back(i);
    }
    std::cout << ans << "\n";
    return 0;
}