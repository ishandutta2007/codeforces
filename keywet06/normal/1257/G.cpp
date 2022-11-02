#include <bits/stdc++.h>

const int N = 3E6;
const int P = 998244353, G = 3;

int cnt[N + 1];

int sum(int a, int b) { return (a += b) >= P ? a -= P : a; }

int dif(int a, int b) { return (a -= b) < 0 ? a += P : a; }

void inc(int &a, int b) { (a += b) >= P ? a -= P : 0; }

std::vector<int> rev, roots{0, 1};

int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = 1LL * ans * a % P;
        a = 1LL * a * a % P;
        b >>= 1;
    }
    return ans;
}

void dft(std::vector<int> &a) {
    int n = a.size();
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
    for (int i = 0; i < n; ++i)
        if (rev[i] < i) std::swap(a[i], a[rev[i]]);
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            int e = power(G, (P - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = 1LL * roots[i] * e % P;
            }
            ++k;
        }
    }
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            for (int j = 0; j < k; ++j) {
                int u = a[i + j];
                int v = 1LL * a[i + j + k] * roots[k + j] % P;
                a[i + j] = sum(u, v);
                a[i + j + k] = dif(u, v);
            }
}

void idft(std::vector<int> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    dft(a);
    int inv = power(n, P - 2);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * inv % P;
}

std::vector<int> operator*(std::vector<int> a, std::vector<int> b) {
    int sz = 1, tot = a.size() + b.size() - 1;
    while (sz < tot) sz <<= 1;
    a.resize(sz);
    b.resize(sz);
    dft(a);
    dft(b);
    for (int i = 0; i < sz; ++i) a[i] = 1LL * a[i] * b[i] % P;
    idft(a);
    a.resize(tot);
    return a;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ++cnt[x];
    }
    std::vector<int> a;
    for (int i = 2; i <= N; ++i)
        if (cnt[i] > 0) a.push_back(cnt[i]);
    std::function<std::vector<int>(int, int)> solve = [&](int l, int r) {
        if (r - l == 1) return std::vector<int>(a[l] + 1, 1);
        int mid = (l + r) / 2;
        return solve(l, mid) * solve(mid, r);
    };
    std::cout << solve(0, (int)a.size())[n / 2] << std::endl;
    return 0;
}