#include <bits/stdc++.h>

const int N = 100005;

int cnt, n, f, u, d, c, g;
int num[N];

std::string s;

std::vector<int> ans;

inline void add(int x) {
    ++num[x], ++cnt;
    if (x < 2) return;
    if (x & 1) ++num[1];
    for (int i = 2; i <= x - 2; ++i) ++num[i];
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> s, n = s.size();
    for (int i = 0; i < n; ++i) {
        g += s[i] == '#';
        if (s[i] == '_' && ++u || !f && (add(u), u = 0, f = 1) || !u) continue;
        add(--u), u = 0;
    }
    if (!g) return std::cout << g << std::endl, 0;
    add(u), u = -1;
    for (int i = 0; i <= n; ++i) u = num[i] == cnt ? i : u;
    if (u == -1) return std::cout << u << std::endl, 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == '_' || s[i - 1] == '#') continue;
        for (int j = 1; j <= u; ++j) s[i - j] = '#';
    }
    for (int i = 0; i < n - u; ++i) {
        if (s[i] == '_') {
            if (c) ans.push_back(d), d = -1, c = 0;
            ++d;
        } else {
            if (!c) {
                if (!d && (d = c = 1)) continue;
                for (int j = 1; j < d / 2; ++j) ans.push_back(1);
                ans.push_back((d & 1) + 1), d = 0, c = 1;
            }
            ++d;
        }
    }
    if (c) {
        ans.push_back(d);
    } else {
        ++d;
        for (int i = 1; i < d / 2; ++i) ans.push_back(1);
        ans.push_back((d & 1) + 1);
    }
    std::cout << ans.size() << std::endl;
    for (int x : ans) std::cout << x << ' ';
    std::cout << std::endl;
    return 0;
}