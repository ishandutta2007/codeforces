#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int cnt = 0;
    int cntR = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            cnt += cntR;
        } else {
            ++cntR;
        }
    }
    if (cnt < k) {
        std::cout << -1 << "\n";
        return 0;
    }
    std::vector<int> pos;
    for (int i = 0; i < n - 1; ++i)
        if (s[i] == 'R' && s[i + 1] == 'L')
            pos.push_back(i);
    int p = 0;
    std::vector<std::vector<int>> ans(k);
    for (int i = 0; i < k; ++i) {
        int t = std::min(int(pos.size()) - p, cnt - (k - i) + 1);
        for (int j = 0; j < t; ++j, ++p) {
            std::swap(s[pos[p]], s[pos[p] + 1]);
            ans[i].push_back(pos[p]);
            if (pos[p] > 0 && s[pos[p] - 1] == 'R')
                pos.push_back(pos[p] - 1);
            if (pos[p] + 1 < n - 1 && s[pos[p] + 2] == 'L')
                pos.push_back(pos[p] + 1);
        }
        cnt -= t;
    }
    if (cnt > 0) {
        std::cout << -1 << "\n";
        return 0;
    }
    for (auto v : ans) {
        std::cout << v.size();
        for (auto a : v)
            std::cout << " " << a + 1;
        std::cout << "\n";
    }
    return 0;
}