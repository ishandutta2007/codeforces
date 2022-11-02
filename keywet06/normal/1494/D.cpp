#include <bits/stdc++.h>

const int N = 2005;
const int K = 505 * 505;

int n, sz;
int c[K];
int a[N][N];

std::vector<std::pair<int, int> > edges;

int go(std::vector<int>& f) {
    if (f.size() == 1) {
        c[f[0]] = a[f[0]][f[0]];
        return f[0];
    }
    int mx = 0;
    for (int x : f) {
        for (int y : f) mx = std::max(mx, a[x][y]);
    }
    std::vector<std::vector<int>> cur;
    for (int u : f) {
        bool pl = false;
        for (auto& it : cur) {
            if (a[u][it[0]] < mx) {
                pl = true, it.emplace_back(u);
                break;
            }
        }
        if (!pl) cur.emplace_back(), cur.back().emplace_back(u);
    }
    int he = sz++;
    c[he] = mx;
    for (auto& it : cur) {
        int c = go(it);
        edges.emplace_back(c, he);
    }
    return he;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) std::cin >> a[i][j];
    }
    sz = n + 1;
    std::vector<int> f(n);
    iota(f.begin(), f.end(), 1);
    int root = go(f);
    std::cout << --sz << '\n';
    for (int i = 1; i <= sz; ++i) std::cout << c[i] << " ";
    std::cout << '\n';
    std::cout << root << '\n';
    for (auto& it : edges) 
        std::cout << it.first << " " << it.second << '\n';
    return 0;
}