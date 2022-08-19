#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, s, l;
    std::cin >> n >> s >> l;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> dp(n + 1);
    std::deque<int> qmx, qmn, qdp;
    for (int i = 0, j = 0; i < n; i++) {
        while (!qmx.empty() && a[i] > a[qmx.back()]) {
            qmx.pop_back();
        }
        qmx.push_back(i);
        while (!qmn.empty() && a[i] < a[qmn.back()]) {
            qmn.pop_back();
        }
        qmn.push_back(i);
        if (i + 1 - l >= j) {
            while (!qdp.empty() && dp[i + 1 - l] < dp[qdp.back()]) {
                qdp.pop_back();
            }
            qdp.push_back(i + 1 - l);
        }
        while (a[qmx.front()] - a[qmn.front()] > s) {
            if (qmx.front() == j) {
                qmx.pop_front();
            }
            if (qmn.front() == j) {
                qmn.pop_front();
            }
            if (!qdp.empty() && qdp.front() == j) {
                qdp.pop_front();
            }
            j++;
        }
        if (!qdp.empty()) {
            dp[i + 1] = dp[qdp.front()] + 1;
        } else {
            dp[i + 1] = n + 1;
        }
    }
    int ans = dp[n];
    if (ans > n) {
        ans = -1;
    }
    std::cout << ans << "\n";
    return 0;
}