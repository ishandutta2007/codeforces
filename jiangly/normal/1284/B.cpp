#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> s, t;
    for (int i = 0; i < n; ++i) {
        int l;
        std::cin >> l;
        std::vector<int> a(l);
        for (int i = 0; i < l; ++i)
            std::cin >> a[i];
        if ([&]() {
            for (int i = 0; i < l - 1; ++i)
                if (a[i] < a[i + 1])
                    return false;
            return true;
        }()) {
            s.push_back(a[0]);
            t.push_back(a.back());
        }
    }
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    long long ans = 1LL * n * n;
    for (int i = 0, j = 0; i < int(t.size()); ++i) {
        while (j < int(s.size()) && s[j] <= t[i])
            ++j;
        ans -= j;
    }
    std::cout << ans << "\n";
    return 0;
}