#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int MOD = 998244353;

void print(vector<int> v) {
    for (int x : v) {
        printf("%d\n", x);
    }
}

struct segtree {
    int n, N;
    vector<int> t, pA, pM;

    segtree(int _n) {
        n = _n;
        N = 1;
        while (N < n) N <<= 1;
        t.assign(2 * N, 0);
        pA.assign(2 * N, 0);
        pM.assign(2 * N, 1);
    }

    void push(int v, int tl, int tr) {
        if (pM[v] != 1) {
            t[v] = 1LL * t[v] * pM[v] % MOD;
            if (tl != tr) {
                pM[v * 2] = 1LL * pM[v * 2] * pM[v] % MOD;
                pA[v * 2] = 1LL * pA[v * 2] * pM[v] % MOD;
                pM[v * 2 + 1] = 1LL * pM[v * 2 + 1] * pM[v] % MOD;
                pA[v * 2 + 1] = 1LL * pA[v * 2 + 1] * pM[v] % MOD;
            }
            pM[v] = 1;
        }
        if (pA[v] != 0) {
            t[v] = (t[v] + 1LL * pA[v] * (tr - tl + 1)) % MOD;
            if (tl != tr) {
                pA[v * 2] = (pA[v * 2] + pA[v]) % MOD;
                pA[v * 2 + 1] = (pA[v * 2 + 1] + pA[v]) % MOD;
            }
            pA[v] = 0;
        }
    }

    void add(int v, int tl, int tr, int l, int r, int x) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            pA[v] = x;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) >> 1;
        add(v * 2, tl, tm, l, min(r, tm), x);
        add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
        t[v] = (t[v * 2] + t[v * 2 + 1]) % MOD;
    }


    void add(int l, int r, int x) {
        add(1, 0, n - 1, l, r, x);
    }

    void mul(int v, int tl, int tr, int l, int r, int x) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            pM[v] = x;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) >> 1;
        mul(v * 2, tl, tm, l, min(r, tm), x);
        mul(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
        t[v] = (t[v * 2] + t[v * 2 + 1]) % MOD;
    }

    void mul(int l, int r, int x) {
        mul(1, 0, n - 1, l, r, x);
    }

    int get(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r) return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) >> 1;
        int ans = 0;
        ans += get(v * 2, tl, tm, l, min(r, tm));
        ans += get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return ans % MOD;
    }

    int get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

vector<int> fast(int n, int q, vector<int> t, vector<int> l, vector<int> r, vector<int> x) {
    vector<int> ans;

    struct Seg {
        int l, r, type;
        bool operator< (const Seg &s) const {
            if (r != s.r) return r < s.r;
            return l < s.l;
        }
    };

    set<Seg> _st0;
    _st0.insert({0, n - 1, 0});
    vector<set<Seg>> st(n, _st0);

    segtree tr(n);

    for (int i = 0; i < q; i++) {
        if (t[i] == 1) {
            set<Seg> &cst = st[x[i]];
            while (1) {
                auto it = cst.lower_bound({-1, l[i], -1});
                if (it == cst.end()) break;
                if (it->l > r[i]) break;

                auto o = *it;
                //db2(l[i], r[i]);
                //db2(o.l, o.r);
                cst.erase(it);

                if (o.l < l[i]) {
                    cst.insert({o.l, l[i] - 1, o.type});
                }
                if (o.r > r[i]) {
                    cst.insert({r[i] + 1, o.r, o.type});
                }
                int cL = max(l[i], o.l);
                int cR = min(r[i], o.r);
                if (o.type == 0) {
                    tr.add(cL, cR, 1);
                } else {
                    tr.mul(cL, cR, 2);
                }
            }
            cst.insert({l[i], r[i], 1});
        } else {
            ans.push_back(tr.get(l[i], r[i]));
        }
    }

    return ans;
}

void test() {
    const int C = 2e5;
    int n = C, q = C;
    vector<int> t(q), l(q), r(q), x(q);
    for (int i = 0; i < q; i++) {
        t[i] = rand() % 2 + 1;
        l[i] = rand() % n;
        r[i] = rand() % n;
        if (l[i] > r[i]) swap(l[i], r[i]);
        x[i] = rand() % n;
    }
    fast(n, q, t, l, r, x);
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    //test();

    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        vector<int> t(q), l(q), r(q), x(q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d%d", &t[i], &l[i], &r[i]);
            l[i]--; r[i]--;
            if (t[i] == 1) {
                scanf("%d", &x[i]);
                x[i]--;
            }
        }

        print(fast(n, q, t, l, r, x));
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}