#include <bits/stdc++.h>
using namespace std;
constexpr double PI = atan2(0, -1);
vector<int> rev;
struct Complex {
    double x, y;
    Complex(double x = 0, double y = 0) : x(x), y(y) {}
};
Complex operator*(const Complex &lhs, const Complex &rhs) {return {lhs.x * rhs.x - lhs.y * rhs.y, lhs.x * rhs.y + lhs.y * rhs.x};}
Complex operator+(const Complex &lhs, const Complex &rhs) {return {lhs.x + rhs.x, lhs.y + rhs.y};}
Complex operator-(const Complex &lhs, const Complex &rhs) {return {lhs.x - rhs.x, lhs.y - rhs.y};}
Complex operator/(const Complex &lhs, const double &rhs) {return {lhs.x / rhs, lhs.y / rhs};}
Complex &operator*=(Complex &lhs, const Complex &rhs) {return lhs = lhs * rhs;}
Complex &operator/=(Complex &lhs, const double &rhs) {
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}
vector<Complex> roots {0, 1};
void dft(vector<Complex> &a) {
    int n = a.size();
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
    for (int i = 0; i < n; ++i)
        if (rev[i] < i)
            swap(a[i], a[rev[i]]);
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            Complex e = {cos(PI / (1 << k)), sin(PI / (1 << k))};
            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }
            ++k;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                auto u = a[i + j], v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}
void idft(vector<Complex> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    dft(a);
    for (int i = 0; i < n; ++i)
        a[i] /= n;
}
vector<double> operator*(vector<double> a, vector<double> b) {
    int sz = 1, tot = a.size() + b.size() - 1;
    while (sz < tot)
        sz *= 2;
    vector<Complex> ca(sz), cb(sz);
    copy(a.begin(), a.end(), ca.begin());
    copy(b.begin(), b.end(), cb.begin());
    dft(ca);
    dft(cb);
    for (int i = 0; i < sz; ++i)
        ca[i] *= cb[i];
    idft(ca);
    a.resize(tot);
    for (int i = 0; i < tot; ++i)
        a[i] = ca[i].x;
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t, x;
    cin >> n >> m >> t >> x;
    vector<vector<double>> p(m, vector<double>(t + 1)), sum(m, vector<double>(t + 1));
    vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        --u[i];
        --v[i];
        for (int j = 1; j <= t; ++j) {
            int x;
            cin >> x;
            p[i][j] = x / 100000.0;
            sum[i][j] = sum[i][j - 1] + p[i][j];
        }
    }
    vector<vector<double>> dp(n, vector<double>(t + 1)), f(m, vector<double>(t + 1));
    for (int i = 0; i < n - 1; ++i)
        fill(dp[i].begin(), dp[i].end(), 1E9);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dp[u[j]][0] = min(dp[u[j]][0], dp[v[j]][0] + w[j]);
    for (int i = 0; i < n - 1; ++i)
        dp[i][0] += x;
    function<void(int, int)> solve = [&](int l, int r) {
        if (r - l == 1) {
            if (l == 0)
                return;
            for (int i = 0; i < m; ++i)
                dp[u[i]][l] = min(dp[u[i]][l], w[i] + f[i][l] + (1 - sum[i][l]) * (dp[v[i]][0] + (v[i] == n - 1 ? x : 0)));
            return;
        }
        int mid = (l + r) / 2;
        solve(l, mid);
        for (int i = 0; i < m; ++i) {
            auto g = vector<double>(dp[v[i]].begin() + l, dp[v[i]].begin() + mid) * vector<double>(p[i].begin(), p[i].begin() + r - l);
            for (int j = mid; j < r; ++j)
                f[i][j] += g[j - l];
        }
        solve(mid, r);
    };
    solve(0, t + 1);
    cout << setprecision(10) << fixed << dp[0][t] << endl;
    return 0;
}