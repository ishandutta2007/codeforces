#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        a.emplace_back(x + y, x);
    }
    std::priority_queue<i64> hl;
    std::priority_queue<i64, std::vector<i64>, std::greater<>> hr;
    for (int i = 0; i < n + 5; i++) {
        hl.push(0);
        hr.push(0);
    }
    i64 tag = 0, mn = 0;
    int last = 0;
    std::sort(a.begin(), a.end());
    for (auto [s, x] : a) {
        int d = s - last;
        last = s;
        tag += d;
        if (x <= hl.top()) {
            mn += hl.top() - x;
            hl.push(x);
            hl.push(x);
            hr.push(hl.top() - tag);
            hl.pop();
        } else if (x >= hr.top() + tag) {
            mn += x - (hr.top() + tag);
            hr.push(x - tag);
            hr.push(x - tag);
            hl.push(hr.top() + tag);
            hr.pop();
        } else {
            hl.push(x);
            hr.push(x - tag);
        }
    }
    std::cout << mn << "\n";
    return 0;
}