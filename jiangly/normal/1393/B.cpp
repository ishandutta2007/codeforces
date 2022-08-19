#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int cnt[100000] = {};
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        --a;
        ++cnt[a];
    }
    std::multiset<int> s;
    for (int i = 0; i < 100000; ++i)
        s.insert(cnt[i]);
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        char op;
        std::cin >> op;
        int a;
        std::cin >> a;
        --a;
        s.erase(s.find(cnt[a]));
        if (op == '+') {
            ++cnt[a];
        } else {
            --cnt[a];
        }
        s.insert(cnt[a]);
        auto it = s.rbegin();
        int m1 = *it;
        ++it;
        int m2 = *it;
        ++it;
        int m3 = *it;
        if (m1 >= 8 || (m1 >= 6 && m2 >= 2) || (m1 >= 4 && m2 >= 4) || (m1 >= 4 && m2 >= 2 && m3 >= 2)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}