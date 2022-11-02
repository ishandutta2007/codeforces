#include <bits/stdc++.h>

int n, m;

std::string a, b, s;

std::vector<int> x, y;

void solve(const std::string &s, const std::string &t, std::vector<int> &ex) {
    std::vector<int> z(s.length());
    z[0] = s.length();
    for (int i = 1, l = -1, r = -1; i < int(s.length()); ++i) {
        if (i <= r) z[i] = std::min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    for (int i = 0, l = -1, r = -1; i < int(t.length()); ++i) {
        if (i <= r) ex[i] = std::min(z[i - l], r - i + 1);
        while (i + ex[i] < n && t[i + ex[i]] == s[ex[i]]) ++ex[i];
        if (i + ex[i] - 1 > r) {
            l = i;
            r = i + ex[i] - 1;
        }
    }
}

struct Fenwick {
    std::vector<long long> a;
    Fenwick(int n) : a(n){};
    void add(int x, int v) {
        for (int i = x + 1; i <= int(a.size()); i += i & -i) a[i - 1] += v;
    }
    long long sum(int x) {
        long long ans = 0;
        for (int i = x; i > 0; i -= i & -i) ans += a[i - 1];
        return ans;
    }
    long long rangeSum(int l, int r) { return sum(r) - sum(l); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> a >> b >> s;
    x.resize(n);
    y.resize(n);
    solve(s, a, x);
    std::reverse(s.begin(), s.end());
    std::reverse(b.begin(), b.end());
    solve(s, b, y);
    std::reverse(y.begin(), y.end());
    for (int &i : x) i = std::min(i, m - 1);
    for (int &i : y) i = std::min(i, m - 1);
    Fenwick s(m), c(m);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        s.add(x[i], x[i]);
        c.add(x[i], 1);
        if (i >= m - 1) {
            s.add(x[i - m + 1], -x[i - m + 1]);
            c.add(x[i - m + 1], -1);
        }
        long long sum = s.rangeSum(m - y[i], m), cnt = c.rangeSum(m - y[i], m);
        ans += sum + cnt * (y[i] - m + 1);
    }
    std::cout << ans << "\n";
    return 0;
}