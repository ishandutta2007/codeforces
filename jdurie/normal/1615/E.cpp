#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
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

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

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
#define N 300010
#define L 18

namespace lztree {
    typedef pl T;
    typedef ll D;

    T idT = {0, 0}, t[2 * N];
    D idD = 0, d[N];
    ll x = (fill_n(d, N, idD), 0);

    T f(T a, T b) { return a.K >= b.K ? a : b; }
    T g(T a, D b) { return {a.K + b, a.V}; }
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

vector<ll> tree[N];
ll tIn[N], tOut[N], par[N];
bool used[N];

ll dfs(ll i, ll p, ll t, ll d) {
    tIn[i] = tOut[i] = t;
    par[i] = p;
    lztree::modifyP(t, {d, i});
    for(ll j : tree[i]) if(j - p) 
        tOut[i] = dfs(j, i, tOut[i] + 1, d + 1);
    return tOut[i];
}

ll f(ll w, ll r, ll b, ll q) { return (w + b - q) * (r - q); }

ll bsch(ll l, ll r, ll w, ll rr, ll b) {
    if(l == r) return f(w, rr, b, l);
    ll m = (l + r) / 2;
    return f(w, rr, b, m) < f(w, rr, b, m + 1) ? bsch(l, m, w, rr, b) : bsch(m + 1, r, w, rr, b); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(k)
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 1, 0, 1);
    ll ans = LLONG_MIN, w = 0, r = 0, b = n;
    while(k--) {
        pl p = lztree::query(0, n);
        r++; b -= p.K; w += p.K - 1;
        ll v = p.V;
        while(!used[v]) {
            lztree::modifyR(tIn[v], tOut[v] + 1, -1);
            used[v] = true;
            v = par[v];
        }
        ans = max(ans, bsch(0, b, w, r, b));
    }
    cout << ans << '\n';
}