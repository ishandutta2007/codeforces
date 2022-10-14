//Lazy Propagation Segment Tree
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r - 1; i > (l); --i)
#define N 100010
#define L 20

struct aaa {
    ll ct[20];
    ll sz = (fill_n(ct, 20, 0), 0);
};

namespace lazytree {
    typedef aaa T;
    typedef ll D;

    T idT, t[2 * N];
    D idD = 0, d[N];
    ll x = (fill_n(d, N, idD), 0);

    T f(T a, T b) {
        aaa res;
        F(i, 0, 20) res.ct[i] = a.ct[i] + b.ct[i];
        res.sz = a.sz + b.sz;
        return res;
    }
    T g(T a, D b) {
        aaa res;
        F(i, 0, 20)
            if((b >> i) & 1) res.ct[i] = a.sz - a.ct[i];
            else res.ct[i] = a.ct[i];
        res.sz = a.sz;
        return res;
    }
    D h(D a, D b) { return a ^ b; }

    void apply(ll p, D v) {
        t[p] = g(t[p], v);
        if(p < N) d[p] = h(d[p], v);
    }

    void modifyP(ll p, T v = idT) {
        if(p < N) p += N, t[p] = v;
        while(p /= 2) t[p] = g(f(t[2 * p], t[2 * p + 1]), d[p]);
    }

    void push(ll p) {
        FD(s, 25, 0) {
            ll i = p >> s;
            apply(2 * i, d[i]);
            apply(2 * i + 1, d[i]);
            d[i] = idD;
        }
    }

    void modifyR(ll l, ll r, D v) {
        ll l0 = (l += N), r0 = (r += N);
        for(; l < r; l /= 2, r /= 2) {
            if(l & 1) apply(l++, v);
            if(r & 1) apply(--r, v);
        }
        modifyP(l0), modifyP(r0 - 1);
    }

    T query(ll l, ll r) {
        l += N, r += N;
        push(l), push(r - 1);
        T resL = idT, resR = idT;
        for(; l < r; l /= 2, r /= 2) {
            if(l & 1) resL = f(resL, t[l++]);
            if(r & 1) resR = f(t[--r], resR);
        }
        return f(resL, resR);
    }
}

ll getSum(aaa v) {
    ll s = 0;
    F(i, 0, 20) s += v.ct[i] << i;
    return s;
}

aaa getAaa(ll x) {
    aaa res;
    F(i, 0, 20) res.ct[i] = (x >> i) & 1;
    res.sz = 1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) {
        G(x)
        lazytree::modifyP(i, getAaa(x));
    }
    G(m) while(m--) {
        G(t) G(l) G(r)
        if(t == 1) cout << getSum(lazytree::query(l - 1, r)) << '\n';
        else { G(x) lazytree::modifyR(l - 1, r, x); }
    }
}