#include <bits/stdc++.h>

using int64 = long long;

const int P = 1000000007;
const int N = 1005;

bool Vis[N];

int n, m, x[10], y[10];
int Size[N];

int64 Ans;

std::map<int, int> g, Id;
std::set<int> s;
std::vector<int> a[N];

void Insert(int x) {
    while (x > 0) s.insert(x), x /= 2;
}

void Dfs(int x, int64 b) {
    Vis[x] = true, Ans += b * Size[x], Ans %= P;
    for (int i : a[x]) {
        if (!Vis[i]) Dfs(i, b);
    }
    Vis[x] = false;
}

int Solve(int x) {
    int l = x;
    int r = x;
    int Left = 0;
    while (true) {
        if (l > n) return Left;
        Left += std::min(r, n) - l + 1;
        r = r * 2 + 1, l = l * 2;
    }
    return Left;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> x[i] >> y[i];
        Insert(x[i]), Insert(y[i]);
    }
    s.insert(1);
    for (int i : s) {
        if (s.find(2 * i) == s.end() && s.find(2 * i + 1) == s.end()) {
            g[i] = Solve(i);
        } else {
            g[i] = 1;
            if (2 * i <= n && s.find(2 * i) == s.end()) g[2 * i] = Solve(2 * i);
            if (2 * i + 1 <= n && s.find(2 * i + 1) == s.end()) g[2 * i + 1] = Solve(2 * i + 1);
        }
    }
    for (auto sth : g) {
        int i = sth.first, u = Id.size();
        Id[i] = u, Size[u] = g[i];
    }
    int nn = g.size();
    for (auto sth : Id) {
        int i = sth.first;
        if (i == 1) continue;
        int Chd = Id[i], Fat = Id[i / 2];
        a[Chd].push_back(Fat);
        a[Fat].push_back(Chd);
    }
    for (int i = 0; i < m; ++i) {
        int Fir = Id[x[i]], Sec = Id[y[i]];
        a[Fir].push_back(Sec);
        a[Sec].push_back(Fir);
    }
    for (int i = 0; i < nn; ++i) Dfs(i, Size[i]);
    std::cout << Ans << std::endl;
    return 0;
}