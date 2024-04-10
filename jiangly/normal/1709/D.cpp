#include <bits/stdc++.h>

using i64 = long long;

template<class T,
    class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const Cmp cmp;
    std::vector<std::vector<T>> a;
    RMQ(const std::vector<T> &init) : n(init.size()), cmp(Cmp()) {
        int lg = std::__lg(n);
        a.assign(n, std::vector<T>(lg + 1));
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                a[i][j] = (j == 0 ? init[i] : std::min(a[i][j - 1], a[i + (1 << (j - 1))][j - 1], cmp));
            }
        }
    }
    T rangeMin(int l, int r) {
        int k = std::__lg(r - l);
        return std::min(a[l][k], a[r - (1 << k)][k], cmp);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
    
    int q;
    std::cin >> q;
    
    RMQ<int, std::greater<>> rmq(a);
    
    while (q--) {
        int xs, ys, xf, yf, k;
        std::cin >> xs >> ys >> xf >> yf >> k;
        ys--;
        yf--;
        if (ys > yf) {
            std::swap(xs, xf);
            std::swap(ys, yf);
        }
        if ((xs - xf) % k != 0 || (ys - yf) % k != 0) {
            std::cout << "NO\n";
            continue;
        }
        int lim = xs + (n - xs) / k * k;
        if (rmq.rangeMin(ys, yf + 1) < lim) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}