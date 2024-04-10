#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i], --a[i];
    std::vector<std::vector<int>> ans;
    while (!std::is_sorted(a.begin(), a.end())) {
        std::vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[a[i]] = i;
        int x = 0;
        while (pos[x] < pos[x + 1]) ++x;
        int y = x + 1;
        while (y + 1 < n && pos[y + 1] == pos[y] + 1) ++y;
        std::vector<int> v;
        if (pos[x + 1] != 0) v.push_back(pos[x + 1]);
        v.push_back(pos[y] - pos[x + 1] + 1);
        v.push_back(pos[x] - pos[y]);
        if (pos[x] != n - 1) v.push_back(n - pos[x] - 1);
        std::vector<int> b;
        for (int i = pos[x] + 1; i < n; ++i) b.push_back(a[i]);
        for (int i = pos[y] + 1; i <= pos[x]; ++i) b.push_back(a[i]);
        for (int i = pos[x + 1]; i <= pos[y]; ++i) b.push_back(a[i]);
        for (int i = 0; i < pos[x + 1]; ++i) b.push_back(a[i]);
        ans.push_back(v);
        a = b;
    }
    std::cout << ans.size() << "\n";
    for (auto v : ans) {
        std::cout << v.size();
        for (auto x : v) std::cout << " " << x;
            std::cout << "\n";
    }
    
    return 0;
}