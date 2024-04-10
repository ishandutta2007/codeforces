#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int p;
struct Matrix {
    int val[2][2];
    Matrix() {memset(val, 0, sizeof(val));}
};
Matrix I;
Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    Matrix result;
    result.val[0][0] = (1LL * lhs.val[0][0] * rhs.val[0][0] + 1LL * lhs.val[0][1] * rhs.val[1][0]) % p;
    result.val[0][1] = (1LL * lhs.val[0][0] * rhs.val[0][1] + 1LL * lhs.val[0][1] * rhs.val[1][1]) % p;
    result.val[1][0] = (1LL  * lhs.val[1][0] * rhs.val[0][0] + 1LL * lhs.val[1][1] * rhs.val[1][0]) % p;
    result.val[1][1] = (1LL * lhs.val[1][0] * rhs.val[0][1] + 1LL * lhs.val[1][1] * rhs.val[1][1]) % p;
    return result;
}
Matrix &operator*=(Matrix &lhs, const Matrix &rhs) {return lhs = lhs * rhs;}
Matrix power(Matrix base, LL exp) {
    Matrix result = I;
    while (exp > 0) {
        if (exp & 1)
            result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

constexpr int M = 1 << 17;
Matrix t[M];
void build(int p, int l, int r, const vector<int> &s) {
    if (r - l == 1) {
        t[p].val[1][0] = 1;
        t[p].val[0][1] = s[l];
        t[p].val[1][1] = r == s.size() ? s[0] : s[r];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid, s);
    build(2 * p + 1, mid, r, s);
    t[p] = t[2 * p] * t[2 * p + 1];
}
Matrix rangeProd(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x)
        return I;
    if (l >= x && r <= y)
        return t[p];
    int mid = (l + r) / 2;
    return rangeProd(2 * p, l, mid, x, y) * rangeProd(2 * p + 1, mid, r, x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    I.val[0][0] = I.val[1][1] = 1;
    
    int n, m;
    LL k;
    cin >> k >> p;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    cin >> m;
    vector<pair<LL, int>> b(m);
    for (int i = 0; i < m; ++i) {
        LL j;
        int v;
        cin >> j >> v;
        b[i] = {j, v};
    }
    sort(b.begin(), b.end());
    
    LL last = 0;
    int lastv = s[0];
    Matrix f;
    f.val[0][1] = 1;
    auto work = [&](LL l, LL r) {
        if (l / n == r / n)
            return rangeProd(1, 0, n, l % n, r % n);
        return rangeProd(1, 0, n, l % n, n) * power(t[1], r / n - l / n - 1) * rangeProd(1, 0, n, 0, r % n);
    };
    build(1, 0, n, s);
    while (!b.empty() && b.back().first >= k)
        b.pop_back();
    if (k != 0)
        b.emplace_back(k, 0);
    for (auto p : b) {
        LL j;
        int v;
        tie(j, v) = p;
        Matrix g;
        g.val[1][0] = 1;
        g.val[0][1] = lastv;
        if (last == j - 1) {
            g.val[1][1] = v;
            f *= g;
        } else {
            g.val[1][1] = s[(last + 1) % n];
            f *= g * work(last + 1, j - 1);
            g.val[0][1] = s[(j - 1) % n];
            g.val[1][1] = v;
            f *= g;
        }
        last = j;
        lastv = v;
    }
    cout << f.val[0][0] << endl;
    return 0;
}