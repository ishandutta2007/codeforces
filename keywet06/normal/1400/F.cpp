#include <bits/stdc++.h>

struct Node {
    int nxt[10];
    int link;
    int bad;
    Node() : nxt{}, link(0), bad(0) {}
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int x;
    std::cin >> x;
    std::vector<int> a;
    std::vector<Node> t(2);
    for (int i = 0; i < 10; ++i) t[0].nxt[i] = 1;
    auto add = [&]() {
        int p = 1;
        for (auto c : a) {
            if (!t[p].nxt[c]) {
                t[p].nxt[c] = t.size();
                t.emplace_back();
            }
            p = t[p].nxt[c];
        }
        t[p].bad = 1;
    };
    std::function<void(int)> dfs = [&](int s) {
        if (s == x) {
            bool ok = true;
            int n = a.size();
            for (int i = 0; i < n; ++i) {
                int d = 0;
                for (int j = i; j < n; ++j) {
                    d += a[j];
                    if (s % d == 0 && d < s) ok = false;
                }
            }
            if (ok) add();
            return;
        }
        for (int c = 1; c <= 9 && s + c <= x; ++c) {
            a.push_back(c);
            dfs(s + c);
            a.pop_back();
        }
    };
    dfs(0);
    std::queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int c = 0; c < 10; ++c) {
            if (t[u].nxt[c]) {
                t[t[u].nxt[c]].link = t[t[u].link].nxt[c];
                que.push(t[u].nxt[c]);
            } else {
                t[u].nxt[c] = t[t[u].link].nxt[c];
            }
        }
    }
    std::vector<std::vector<int>> dp(2, std::vector<int>(t.size(), 1e9));
    dp[0][1] = 0;
    int cur = 0;
    for (auto c : s) {
        cur ^= 1;
        std::fill(dp[cur].begin(), dp[cur].end(), 1e9);
        for (int i = 1; i < int(t.size()); ++i) {
            dp[cur][i] = std::min(dp[cur][i], dp[!cur][i] + 1);
            int v = t[i].nxt[c - '0'];
            if (!t[v].bad) dp[cur][v] = std::min(dp[cur][v], dp[!cur][i]);
        }
    }
    std::cout << *std::min_element(dp[cur].begin(), dp[cur].end()) << "\n";
    return 0;
}