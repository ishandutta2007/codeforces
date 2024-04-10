#include <bits/stdc++.h>

const int N = 1505;

char s[N];

int T, n, x, y, a, b;
int dep[N];

std::vector<int> v[N], d[N];

void dfs(int i, int fa) {
    d[dep[i] = dep[fa] + 1].push_back(i);
    for (int j = 0; j < v[i].size(); ++j) {
        int to = v[i][j];
        if (to ^ fa) dfs(to, i);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) v[i].clear(), d[i].clear();
        for (int i = 1; i < n; ++i) {
            std::cin >> x >> y;
            v[x].push_back(y), v[y].push_back(x);
        }
        dfs(1, 0);
        std::cout << "? " << n;
        for (int i = 1; i <= n; ++i) std::cout << ' ' << i;
        std::cout << std::endl;
        std::cin >> a >> b;
        int l = 1, r = n, mid;
        while (l < r) {
            mid = (l + r >> 1) + 1;
            int sum = 0;
            for (int i = n; i >= mid; --i) sum += d[i].size();
            if (!sum && (r = mid - 1)) continue;
            std::cout << "? " << sum;
            for (int i = n; i >= mid; --i) {
                for (int j = 0; j < d[i].size(); ++j) {
                    std::cout << ' ' << d[i][j];
                }
            }
            std::cout << std::endl;
            std::cin >> x >> y;
            y == b ? (l = mid) : (r = mid - 1);
            if (y == b && dep[x] > dep[a]) a = x;
        }
        for (int i = 1; i <= n; ++i) d[i].clear();
        dfs(a, 0);
        std::cout << "? " << d[b + 1].size();
        for (int i = 0; i < d[b + 1].size(); ++i){
            std::cout << ' ' << d[b + 1][i];}
        std::cout << std::endl;
        std::cin >> x >> y;
        std::cout << "! " << a << ' ' << x << std::endl;
        std::cin >> s;
        if (s[0] == 'I') return 0;
    }
}