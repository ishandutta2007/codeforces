#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INF = 1E18;
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int inv_n, inv_m;
    int g = exgcd(n, m, inv_n, inv_m);
    n /= g;
    m /= g;
    inv_n = (inv_n % m + m) % m;
    inv_m = (inv_m % n + n) % n;
    if (g > 200000) {
        cout << -1 << "\n";
        return 0;
    }
    LL ans = 0;
    int a;
    cin >> a;
    vector<int> x(a);
    for (int i = 0; i < a; ++i)
        cin >> x[i];
    int b;
    cin >> b;
    vector<int> y(b);
    for (int i = 0; i < b; ++i)
        cin >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    auto work = [&](vector<int> x, vector<int> y, int n, int m, int inv_m) {
        vector<map<int, int>> f(g);
        for (int v : x)
            f[v % g][v / g] = v;
        for (int v : y) {
            if (!f[v % g].count(v / g % n)) {
                f[v % g][v / g % n] = v;
                ans = max(ans, (LL)v);
            }
        }
        for (int i = 0; i < g; ++i) {
            if (f[i].empty()) {
                cout << -1 << "\n";
                exit(0);
            }
            vector<pair<int, int>> h(f[i].begin(), f[i].end());
            for (auto &p : h)
                p.first = 1LL * p.first * inv_m % n;
            sort(h.begin(), h.end());
            for (int j = 0; j < h.size(); ++j) {
                int nxt = (j + 1 == h.size() ? h[0] : h[j + 1]).first;
                if ((h[j].first + 1) % n == nxt)
                    continue;
                ans = max(ans, h[j].second + 1LL * (nxt - 1 - h[j].first + n) % n * m * g);
            }
        }
    };
    work(x, y, n, m, inv_m);
    work(y, x, m, n, inv_n);
    cout << ans << endl;
    return 0;
}