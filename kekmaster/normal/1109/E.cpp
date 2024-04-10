#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif
#include <bits/stdc++.h>
#ifdef LOCAL
#include "template.h"
#endif

using namespace std;
#ifndef LOCAL
#define dbg(...) (void)0
#define ARR(arr, ...) (void)0
#define eprintf(...) (void)0
#endif

#define mp make_pair
#define rand govno_ebanoe
#define dbg_time() eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC)

using ll = long long;
using pii = pair<int, int>;
using dbl = double;

const int MAXP = 11;
const int M = 2e6 + 10;
int mod, phi;
int mul(int a, int b) {
    return (ll) a * b % mod;
}
int sum(int a, int b) {
    a += b;
    return a >= mod ? a - mod : a;
}
int bpow(int x, int pw) {
    int res = 1;
    for(; pw > 0; pw /= 2, x = mul(x, x))
        if (pw % 2 == 1)
            res = mul(res, x);
    return res;
}
int inv(int x) {
    return bpow(x, phi - 1);
}
int sz;
int ps[MAXP];
int ppows[MAXP][M];
struct Num {
    int rem;
    vector<int> divs;
    Num() {}
    Num(int x) {
        divs.resize(sz);
        for(int i = 0; i < sz; ++i) {
            while (x % ps[i] == 0) {
                x /= ps[i];
                ++divs[i];
            }
        }
        rem = x;
    }
    Num(int r, vector<int> d) : rem(r), divs(d) {}
    Num operator+ (const Num& n) const {
        int r1 = rem;
        int r2 = n.rem;
        vector<int> d(sz);
        for(int i = 0; i < sz; ++i) {
            d[i] = min(divs[i], n.divs[i]);
            r1 = mul(r1, ppows[i][divs[i] - d[i]]);
            r2 = mul(r2, ppows[i][n.divs[i] - d[i]]);
        }
        return {sum(r1, r2), d};
    }
    Num operator*= (const Num& n) {
        rem = mul(rem, n.rem);
        for(int i = 0; i < sz; ++i)
            divs[i] += n.divs[i];
        return *this;
    }
    Num operator/= (const Num& n) {
        rem = mul(rem, inv(n.rem));
        for(int i = 0; i < sz; ++i)
            divs[i] -= n.divs[i];
        return *this;
    }
    bool operator== (const Num& n) const {
        if (rem != n.rem)
            return false;
        for(int i = 0; i < sz; ++i)
            if (divs[i] != n.divs[i])
                return false;
        return true;
    }
    int to_int() const {
        int res = rem;
        for(int i = 0; i < sz; ++i)
            res = mul(res, ppows[i][divs[i]]);
        return res;
    }
};

Num one, zero;

const int N = (1 << 18);
int n;
struct Segt {
    Num muls[N];
    int vals[N];
    void apply(int ind, const Num& x) {
        vals[ind] = ::mul(vals[ind], x.to_int());
        muls[ind] *= x;
    }
    void push(int ind) {
        if (muls[ind] == one)
            return;
        apply(ind * 2, muls[ind]);
        apply(ind * 2 + 1, muls[ind]);
        muls[ind] = one;
    }
    int get(int ind, int l, int r, int L, int R) {
        if (L <= l && r <= R)
            return vals[ind];
        if (R < l || r < L)
            return 0;
        push(ind);
        int m = (l + r) / 2;
        return sum(get(ind * 2, l, m, L, R),
                get(ind * 2 + 1, m + 1, r, L, R));
    }
    int get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
    void mul(int ind, int l, int r, int L, int R, const Num& x) {
        if (L <= l && r <= R) {
            apply(ind, x);
            return;
        }
        if (r < L || R < l)
            return;
        push(ind);
        int m = (l + r) / 2;
        mul(ind * 2, l, m, L, R, x);
        mul(ind * 2 + 1, m + 1, r, L, R, x);
        vals[ind] = sum(vals[ind * 2], vals[ind * 2 + 1]);
    }
    void mul(int l, int r, Num x) {
        mul(1, 0, n - 1, l, r, x);
    }
    void div(int ind, int l, int r, int p, const Num& x) {
        if (l == r) {
            muls[ind] /= x;
            vals[ind] = muls[ind].to_int();
            return;
        }
        push(ind);
        int m = (l + r) / 2;
        if (p <= m)
            div(ind * 2, l, m, p, x);
        else
            div(ind * 2 + 1, m + 1, r, p, x);
        vals[ind] = sum(vals[ind * 2], vals[ind * 2 + 1]);
    }
    void div(int p, Num x) {
        div(1, 0, n - 1, p, x);
    }
    void build(int ind, int l, int r, int _n) {
        if (l == r) {
            if (l < _n) {
                int x;
                scanf("%d", &x);
                muls[ind] = Num(x);
                vals[ind] = x % mod;
            } else {
                vals[ind] = 0;
                muls[ind] = zero;
            }
            return;
        }
        muls[ind] = one;
        int m = (l + r) / 2;
        build(ind * 2, l, m, _n);
        build(ind * 2 + 1, m + 1, r, _n);
        vals[ind] = sum(vals[ind * 2], vals[ind * 2 + 1]);
    }
} segt;

void init() {
    scanf("%d%d", &n, &mod);
    int imod = mod;
    phi = 1;
    for(int d = 2; d * d <= mod; ++d) {
        if (mod % d == 0) {
            ps[sz++] = d;
            mod /= d;
            phi *= d - 1;
            while(mod % d == 0) {
                mod /= d;
                phi *= d;
            }
        }
    }
    if (mod != 1) {
        ps[sz++] = mod;
        phi *= mod - 1;
    }
    mod = imod;
    for(int i = 0; i < sz; ++i) {
        ppows[i][0] = 1;
        for(int j = 1; j < M; ++j)
            ppows[i][j] = mul(ppows[i][j - 1], ps[i]);
    }
    dbg_time();
    one = Num(1);
    zero = Num(0, vector<int>(sz));
}

void solve() {
    init();

    int n2 = n;
    while(n & (n - 1))
        ++n;
    segt.build(1, 0, n - 1, n2);

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            segt.mul(l - 1, r - 1, Num(x));
        } else if(t == 2) {
            int p, x;
            scanf("%d%d", &p, &x);
            segt.div(p - 1, Num(x));
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", segt.get(l - 1, r - 1));
        }
    }
}

int main() {
#ifndef LOCAL
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

		int test_count = 1;
#ifdef MULTITEST
		scanf("%d", &test_count);
		char endl1[5];
		fgets(endl1, 5, stdin);
#endif
		for (int i = 0; i < test_count; ++i) {
#ifdef CASES
			printf("Case #%d: ", i + 1);
			solve();
			eprintf("Passed case #%d:\n", i + 1);
#else
			solve();
#endif
		}
	dbg_time();
}