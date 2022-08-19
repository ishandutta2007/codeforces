#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> t1, t2, t3;
    std::vector<long long> s1, s2, s3;
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        std::cin >> t >> a >> b;
        if (a && b) {
            t3.push_back(t);
        } else if (a) {
            t1.push_back(t);
        } else if (b) {
            t2.push_back(t);
        }
    }
    std::sort(t1.begin(), t1.end());
    std::sort(t2.begin(), t2.end());
    std::sort(t3.begin(), t3.end());
    long long ans = -1;
    auto f = [&](const auto &a, auto &b) {
        b.resize(a.size() + 1);
        for (int i = 0; i < int(a.size()); ++i)
            b[i + 1] = b[i] + a[i];
    };
    f(t1, s1);
    f(t2, s2);
    f(t3, s3);
    for (int i = 0; i <= k; ++i) {
        if (int(t3.size()) >= i && int(t1.size()) >= k - i && int(t2.size()) >= k - i) {
            long long res = s3[i] + s2[k - i] + s1[k - i];
            if (ans == -1 || ans > res)
                ans = res;
        }
    }
    std::cout << ans << "\n";
    return 0;
}