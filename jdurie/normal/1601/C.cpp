#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}
template<template<class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
operator << (ostream &o, T<A...> V) {
	o << '[';
	for(auto a : V) o << a << ", ";
	return o << ']';
}

typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef tree<pl, null_type, less<pl>,
rb_tree_tag, tree_order_statistics_node_update> set_t;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 1000010

#define L 20

namespace lztree {
    typedef ll T;
    typedef ll D;

    T idT = M, t[2 * N];
    D idD = 0, d[N];
    ll x = (fill_n(d, N, idD), 0);

    T f(T a, T b) { return min(a, b); }
    T g(T a, D b) { return a + b; }
    D h(D a, D b) { return a + b; }

    void apply(ll p, D v) {
        t[p] = g(t[p], v);
        if(p < N) d[p] = h(d[p], v);
    }

    void push(ll p) {
        FD(s, L, 0) {
            ll i = p >> s;
            apply(2 * i, d[i]);
            apply(2 * i + 1, d[i]);
            d[i] = idD;
        }
    }

    void modifyP(ll p, T v = idT) {
        if(p < N) { push(p += N); t[p] = v; }
        while(p /= 2) t[p] = g(f(t[2 * p], t[2 * p + 1]), d[p]);
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


ll n, a[N], b[N];
pl c[N];
set_t oset;

long long int inv() {
    oset.clear();
    long long int in = 0;
    F(i, 0, n) {
        in += oset.order_of_key({-a[i], -M});
        oset.insert({-a[i], i});
    }
    return in;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n; G(m)
        F(i, 0, n) cin >> a[i], c[i] = {a[i], i};
        F(i, 0, n) lztree::modifyP(i, i + 1);
        F(i, 0, m) cin >> b[i];
        sort(b, b + m);
        sort(c, c + n);
        long long int ans = 0;
        ll l = 0, leq = 0, z = 0;
        F(i, 0, m) {
            while(l < n && c[l].K < b[i]) lztree::modifyR(c[l].V, n, -1), z++, l++;
            while(leq < n && c[leq].K <= b[i]) lztree::modifyR(c[leq].V, n, -1), leq++;
            ans += z + min(0, lztree::query(0, n));
        }
        cout << inv() + ans << '\n';
    }
}