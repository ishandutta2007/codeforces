#include <bits/stdc++.h>
double integr(double k, double b, double l, double r) {
    return 0.5 * k * (r * r - l * l) + b * (r - l);
}
struct Function {
    double a, b, c;
    Function(double c = 0, double b = 0, double a = 0) : a(a), b(b), c(c) {}
    friend Function operator+(const Function &lhs, const Function &rhs) {
        return Function(lhs.c + rhs.c, lhs.b + rhs.b, lhs.a + rhs.a);
    }
    friend Function operator-(const Function &lhs, const Function &rhs) {
        return Function(lhs.c - rhs.c, lhs.b - rhs.b, lhs.a - rhs.a);
    }
    double get(double x) {
        return a * x * x + b * x + c;
    }
};
Function integrf(double k, double b, double k1, double b1) {
    Function res;
    res.a += 0.5 * k * k1 * k1;
    res.b += k * k1 * b1;
    res.c += 0.5 * k * b1 * b1;
    res.b += b * k1;
    res.c += b * b1;
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        std::cin >> y[i] >> x[i];
    int xMin = std::min_element(x.begin(), x.end()) - x.begin();
    int xMax = std::max_element(x.begin(), x.end()) - x.begin();
    Function area = 0;
    std::vector<int> l, u;
    l.push_back(xMin);
    u.push_back(xMin);
    for (int i = (xMin + 1) % n; i != xMax; i = (i + 1) % n)
        l.push_back(i);
    for (int i = (xMin - 1 + n) % n; i != xMax; i = (i - 1 + n) % n)
        u.push_back(i);
    l.push_back(xMax);
    u.push_back(xMax);
    int lst = x[xMin];
    std::vector<std::pair<double, Function>> op;
    auto work = [&](double k, double b, double l, double r, double coef, double k1, double b1) {
        double fl = k * l + b;
        double fr = k * r + b;
        if (fl < fr - 1e-9) {
            Function f = integrf(k1, b1, 1.0 / k, -fl / k + l) - integrf(k1, b1, 0, l);
            f.a += coef * 1 / k;
            f.b += coef * -fl / k;
            Function g = integrf(k1, b1, 0, r) - integrf(k1, b1, 0, l);
            g.b += coef * (r - l);
            op.emplace_back(fl, f);
            op.emplace_back(fr, g - f);
        } else if (fl > fr + 1e-9) {
            Function f = integrf(k1, b1, 0, r) - integrf(k1, b1, 1 / k, r - fr / k);
            f.a += coef * -1 / k;
            f.b += coef * fr / k;
            Function g = integrf(k1, b1, 0, r) - integrf(k1, b1, 0, l);
            g.b += coef * (r - l);
            op.emplace_back(fr, f);
            op.emplace_back(fl, g - f);
        } else {
            Function g = integrf(k1, b1, 0, r) - integrf(k1, b1, 0, l);
            g.b += coef * (r - l);
            op.emplace_back(fl, g);
        }
    };
    for (int i = 0, j = 0; i + 1 < int(l.size()) && j + 1 < int(u.size()); ) {
        int r = std::min(x[l[i + 1]], x[u[j + 1]]);
        double kl = 1.0 * (y[l[i + 1]] - y[l[i]]) / (x[l[i + 1]] - x[l[i]]);
        double bl = y[l[i]] - kl * x[l[i]];
        double ku = 1.0 * (y[u[j + 1]] - y[u[j]]) / (x[u[j + 1]] - x[u[j]]);
        double bu = y[u[j]] - ku * x[u[j]];
        double ar = integr(ku - kl, bu - bl, lst, r);
        if (ar < 0) {
            ar = -ar;
            std::swap(kl, ku);
            std::swap(bl, bu);
        }
        area = area + Function(ar);
        work(kl, bl, lst, r, -1, kl, bl);
        work((kl + ku) / 2, (bl + bu) / 2, lst, r, 2, -kl - ku, -bl - bu);
        work(ku, bu, lst, r, -1, ku, bu);
        lst = r;
        if (x[l[i + 1]] == r)
            ++i;
        if (x[u[j + 1]] == r)
            ++j;
    }
    std::vector<int> f(q);
    for (int i = 0; i < q; ++i)
        std::cin >> f[i];
    std::vector<int> perm(q);
    std::vector<double> ans(q);
    std::iota(perm.begin(), perm.end(), 0);
    std::sort(perm.begin(), perm.end(), [&](int i, int j) {
        return f[i] < f[j];
    });
    std::sort(op.begin(), op.end(), [&](auto x, auto y) {
        return x.first < y.first;
    });
    int now = 0;
    for (auto [y, g] : op) {
        while (now < q && f[perm[now]] < y) {
            ans[perm[now]] = area.get(f[perm[now]]);
            ++now;
        }
        area = area + g;
    }
    for (int i = 0; i < q; ++i)
        std::cout << ans[i] << "\n";
    return 0;
}