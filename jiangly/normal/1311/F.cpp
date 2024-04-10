// lg
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
struct Fenwick {
    std::vector<int> a;
    Fenwick(int n) : a(n) {};
    void add(int x, int v) {
        for (int i = x + 1; i <= int(a.size()); i += i & -i)
            a[i - 1] += v;
    }
    int sum(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i)
            ans += a[i - 1];
        return ans;
    }
    int rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    void clear() {
        std::fill(a.begin(), a.end(), 0);
    }
};
int n;
std::vector<int> x, v, vs, p;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    x.resize(n);
    v.resize(n);
    p.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> x[i];
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    vs = v;
    std::sort(vs.begin(), vs.end());
    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
    for (int i = 0; i < n; ++i)
        v[i] = std::lower_bound(vs.begin(), vs.end(), v[i]) - vs.begin();
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return x[i] < x[j];
    });
    Fenwick t(vs.size());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = p[i];
        ans += 1ll * t.rangeSum(0, v[j] + 1) * x[j];
        t.add(v[j], 1);
    }
    t.clear();
    for (int i = n - 1; i >= 0; --i) {
        int j = p[i];
        ans -= 1ll * t.rangeSum(v[j], vs.size()) * x[j];
        t.add(v[j], 1);
    }
    std::cout << ans << "\n";
    return 0;
}