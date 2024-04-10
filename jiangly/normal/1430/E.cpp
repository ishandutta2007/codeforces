#include <bits/stdc++.h>
template<typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i)
            a[i - 1] += v;
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i)
            ans += a[i - 1];
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> a[26];
    for (int i = 0; i < n; ++i) a[s[i] - 'a'].push_back(i);
    Fenwick<int> fen(n);
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[s[i] - 'a'].back();
        a[s[i] - 'a'].pop_back();
        ans += fen.sum(x);
        fen.add(x, 1);
    }
    std::cout << ans << "\n";
    
    return 0;
}