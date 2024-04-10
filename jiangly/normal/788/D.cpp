#include <bits/stdc++.h>

constexpr int Lim = 1e8;

int query(int x, int y) {
    std::cout << 0 << " " << x << " " << y << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

std::vector<int> cand;

void solve(int l, int r) {
    if (l > r) {
        return;
    }
    int m = (l + r) >> 1;
    int d = query(m, m);
    if (d == 0) {
        cand.push_back(m);
        d = 1;
    }
    solve(l, m - d);
    solve(m + d, r);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    
    int g = 0;
    while (query(g, g) == 0) {
        g = gen() % Lim;
    }
    
    solve(-Lim, Lim);
    
    std::sort(cand.begin(), cand.end());
    std::vector<int> x, y;
    for (auto a : cand) {
        if (query(a, g) == 0) {
            x.push_back(a);
        }
    }
    
    for (auto a : cand) {
        if (query(g, a) == 0) {
            y.push_back(a);
        }
    }
    
    std::cout << 1 << " " << x.size() << " " << y.size() << "\n";
    for (auto a : x) {
        std::cout << a << " \n"[a == x.back()];
    }
    for (auto a : y) {
        std::cout << a << " \n"[a == y.back()];
    }
    
    return 0;
}