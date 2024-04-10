#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    i64 ans = 0;
    
    for (int x = 0; x < 3; x++) {
        Fenwick<int> fen(2 * n + 1);
        int balance = n;
        int b = 0;
        if (x == 0) {
            fen.add(n, 1);
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') {
                b++;
                balance++;
            } else {
                b += 2;
                balance--;
            }
            if (b % 3 == x) {
                ans += fen.sum(balance + 1);
                fen.add(balance, 1);
            }
        }
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}