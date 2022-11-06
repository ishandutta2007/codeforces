#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long llong;

const int mod = 1e9 + 7;

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = (llong)r * x % mod;
        x = (llong)x * x % mod;
        p >>= 1;
    }
    return r;
}

struct fenwick {
    int n, v[400001];
    void init(int N) {
        n = N;
        for (int i = 1; i <= n; ++i) v[i] = 1;
    }
    void update(int i, int x) {
        while (i <= n) {
            v[i] = (llong)v[i] * x % mod;
            i += i & -i;
        }
    }
    int query(int i) const {
        int r = 1;
        while (i) {
            r = (llong)r * v[i] % mod;
            i -= i & -i;
        }
        return r;
    }
};

int R[301];
struct rangefen {
    fenwick A, B;
    void init(int n) {
        A.init(n);
        B.init(n);
    }
    void update(int i, int x) {
        B.update(i, x);
    }
    void update(int s, int e, int x) {
        A.update(s, x);
        A.update(e + 1, R[x]);
        B.update(s, pw(R[x], s - 1));
        B.update(e + 1, pw(x, e));
    }
    int query(int i) const {
        return (llong)pw(A.query(i), i) * B.query(i) % mod;
    }
    int query(int s, int e) const {
        return (llong)query(e) * pw(query(s - 1), mod - 2) % mod;
    }
} fen;

struct sumseg {
    vector<bool> v, z;
    sumseg() : v(1 << 20, false), z(1 << 20, false) {}
    void update(int i, int s, int e, int x, int y) {
        if (z[i]) return;
        if (e < x || y < s) return;
        v[i] = true;
        if (x <= s && e <= y) {
            z[i] = true;
            return;
        }
        int m = (s + e) / 2;
        update(i << 1, s, m, x, y);
        update(i << 1 | 1, m + 1, e, x, y);
    }
    bool query(int i, int s, int e, int x, int y) {
        if (e < x || y < s) return false;
        if (z[i]) return true;
        if (x <= s && e <= y) return v[i];
        int m = (s + e) / 2;
        return query(i << 1, s, m, x, y) || query(i << 1 | 1, m + 1, e, x, y);
    }
} sum[70];

vector<int> P;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    {
        int p[301] = { 1, 1, 0 };
        for (int i = 1; i <= 300; ++i) {
            R[i] = pw(i, mod - 2);
            if (p[i]) continue;
            P.push_back(i);
            for (int j = i * i; j <= 300; j += i) p[j] = 1;
        }
    }
    int n, q;
    cin >> n >> q;
    fen.init(n);
    for (int i = 1; i <= n; ++i) {
        int A;
        cin >> A;
        fen.update(i, A);
        for (int j = 0; j < P.size(); ++j) {
            if (A % P[j] == 0) sum[j].update(1, 1, n, i, i);
        }
    }
    while (q--) {
        char in[100];
        int l, r, x;
        cin >> in >> l >> r;
        if (in[0] == 'M') {
            cin >> x;
            fen.update(l, r, x);
            for (int i = 0; i < P.size(); ++i) {
                if (x % P[i] == 0) sum[i].update(1, 1, n, l, r);
            }
        }
        else {
            int ret = fen.query(l, r);
            for (int i = 0; i < P.size(); ++i) {
                if (sum[i].query(1, 1, n, l, r)) {
                    ret = ret * (P[i] - 1ll) % mod * R[P[i]] % mod;
                }
            }
            printf("%d\n", ret);
        }
    }
    return 0;
}