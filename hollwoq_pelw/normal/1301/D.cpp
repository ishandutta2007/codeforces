#include <bits/stdc++.h>

int n, m, k;
std::vector<std::pair<int, char>> vec, ans;

inline void insert(int x, char c) {
    if (x > 0) { vec.push_back({x, c}); }
}
inline void insertt(int x, char c) {
    if (x > 0) { ans.push_back({x, c}); }
}

bool solve() {
    for (auto i : vec) {
        insertt(std::min(i.first, k), i.second);
        k -= std::min(i.first, k);
    }
    return k <= 0;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i < n; i++) {
        insert(m - 1, 'R');
        insert(m - 1, 'L');
        insert(1, 'D');
    }
    insert(m - 1, 'R');
    for (int i = 1; i < m; i++) {
        insert(n - 1, 'U');
        insert(n - 1, 'D');
        insert(1, 'L');
    }
    insert(n - 1, 'U');
    if (!solve()) {
        printf("NO\n");
    } else {
        printf("YES\n");
        printf("%d\n", ans.size());
        for (auto i : ans) {
            printf("%d %c\n", i.first, i.second);
        }
    }
    return 0;
}