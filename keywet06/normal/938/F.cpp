#include <bits/stdc++.h>

const int N = 5006;

bool v[N][N];

char a[N];

int n;

std::string ans;

std::vector<std::pair<int, int>> f[26], g;

void dfs(int x, int s) {
    if (v[x][s]) return;
    v[x][s] = true;
    if (x + 1 + s <= n) f[a[x + 1] - 'a'].push_back({x + 1, s});
    for (int i = 0; s >> i; ++i) {
        if (s >> i & 1) dfs(x + (1 << i), s - (1 << i));
    }
}

int main() {
    scanf("%s", a + 1);
    n = strlen(a + 1);
    int u = 1;
    while (u * 2 <= n) u *= 2;
    --u;
    dfs(0, u);
    while (true) {
        int c = -1;
        for (int i = 0; i < 26; ++i) {
            if (f[i].size()) {
                c = i;
                break;
            }
        }
        if (c == -1) break;
        ans.push_back('a' + c);
        g.swap(f[c]);
        for (auto &i : f) i = {};
        for (auto i : g) dfs(i.first, i.second);
    }
    std::cout << ans << std::endl;
    return 0;
}