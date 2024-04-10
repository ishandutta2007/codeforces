#include <bits/stdc++.h>

using int64 = long long;

void solve() {
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;
    std::string s;
    std::cin >> s;
    int64 ans = 0;
    int To[2] = {};
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) ++To[s[i] - '0'];
    }
    std::vector<int> steps;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[i] == s[j]) ++j;
        if (s[i] == '0' && i != 0 && j != n) steps.push_back(j - i);
        i = j;
    }
    int k = steps.size();
    std::sort(steps.begin(), steps.end());
    std::vector<int> pre(k + 1);
    for (int i = 0; i < k; ++i) pre[i + 1] = pre[i] + steps[i];
    int cnt0 = std::count(s.begin(), s.end(), '0');
    for (int cnt = 0; cnt <= To[1] + k; ++cnt) {
        if (cnt0 >= cnt) {
            int t = std::max({0, cnt - To[1], cnt - To[0]});
            if (cnt >= pre[std::max(0, cnt - To[1])]) {
                ans = std::max(ans, 1LL * (cnt - t) * a + 1LL * cnt * b - 1LL * t * c);
            }
        }
        if (cnt0 >= cnt + 1) {
            int t = std::max({0, cnt - To[1], cnt + 1 - To[0]});
            if (cnt >= pre[std::max(0, cnt - To[1])]) {
                ans = std::max(ans, 1LL * (cnt + 1 - t) * a + 1LL * cnt * b - 1LL * t * c);
            }
        }
        if (cnt > 0 && cnt0 >= cnt - 1) {
            int t = std::max({0, cnt - To[1], cnt - 1 - To[0]});
            if (cnt - 1 >= pre[std::max(0, cnt - To[1])]) {
                ans = std::max(ans, 1LL * (cnt - 1 - t) * a + 1LL * cnt * b - 1LL * t * c);
            }
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}