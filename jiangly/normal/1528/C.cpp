#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n, -1), b(n, -1);
        for (int i = 1; i < n; i++) {
            std::cin >> a[i];
            a[i]--;
        }
        for (int i = 1; i < n; i++) {
            std::cin >> b[i];
            b[i]--;
        }
        std::vector<std::vector<int>> e(n);
        for (int i = 1; i < n; i++) {
            e[b[i]].push_back(i);
        }
        std::vector<int> in(n), out(n), id(n);
        int timeStamp = 0;
        std::function<void(int)> dfs1 = [&](int u) {
            in[u] = timeStamp++;
            id[in[u]] = u;
            for (auto v : e[u]) {
                dfs1(v);
            }
            out[u] = timeStamp;
        };
        dfs1(0);
        for (int i = 0; i < n; i++) {
            e[i].clear();
        }
        for (int i = 1; i < n; i++) {
            e[a[i]].push_back(i);
        }
        int ans = 0;
        std::set<int> s;
        std::function<void(int)> dfs2 = [&](int u) {
            bool add = false;
            int del = -1;
            auto it = s.lower_bound(in[u]);
            if (it == s.end() || *it >= out[u]) {
                if (it != s.begin()) {
                    it--;
                    if (out[id[*it]] > in[u]) {
                        del = *it;
                        s.erase(it);
                    }
                }
                s.insert(in[u]);
                add = true;
            }
            ans = std::max(ans, int(s.size()));
            for (auto v : e[u]) {
                dfs2(v);
            }
            if (add) {
                s.erase(in[u]);
                if (del != -1) {
                    s.insert(del);
                }
            }
        };
        dfs2(0);
        std::cout << ans << "\n";
    }
    return 0;
}