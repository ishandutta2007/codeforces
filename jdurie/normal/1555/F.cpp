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
typedef ll T;

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
#define N 500010

vector<ll> tree[N];
T val[N];
ll dep[N], idx[N], sz[N], top[N];
vector<pair<pl, pl>> edges;
bool ans[N];
set<pl> ones;

ll par[N], col[N];

ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

#define L 20

namespace sgtree {
    typedef ll T;
    typedef ll D;

    T idT = 0, t[2 * N];
    D idD = 0, d[N];
    ll x = (fill_n(d, N, idD), 0);

    T f(T a, T b) { return a + b; }
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
        if(p < N) { push(p = idx[p] + N); t[p] = v; }
        while(p /= 2) t[p] = g(f(t[2 * p], t[2 * p + 1]), d[p]);
    }

    void modifyR(ll i, ll a, D v) {
        ll r = idx[i] + 1, l = r - a;
        ll l0 = (l += N), r0 = (r += N);
        for(; l < r; l /= 2, r /= 2) {
            if(l & 1) apply(l++, v);
            if(r & 1) apply(--r, v);
        }
        modifyP(l0), modifyP(r0 - 1);
    }

    T query(ll i, ll a) {
        ll r = idx[i] + 1, l = r - a;
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

ll dfs1(ll i, ll p, ll c) {
    col[i] = c;
    dep[i] = dep[p] + 1;
    sz[i] = 1;
    for(ll j : tree[i]) if(j - p)
        sz[i] += dfs1(j, i, ones.count({i, j}) ? c ^ 1 : c);
    sort(A(tree[i]), [](ll j, ll k) { return sz[j] > sz[k]; });
    return sz[i];
}

ll pos = 0;
void dfs2(ll i, ll p, ll t) {
    top[i] = t;
    idx[i] = pos++;
    for(ll j : tree[i]) if(j - p)
        dfs2(j, i, t), t = i;
}

T query(ll a, ll b) { //only works for commutative operations - others very messy
    if(dep[a] - dep[b] == idx[a] - idx[b]) {
        if(dep[a] > dep[b]) swap(a, b);
        return sgtree::query(b, dep[b] - dep[a]); //remove +1 if querying vals at edges (not vertices)
    }
    if(dep[top[a]] > dep[top[b]]) swap(a, b);
    return sgtree::f(query(a, top[b]), sgtree::query(b, dep[b] - dep[top[b]]));
}

void modify(ll a, ll b) { //only works for commutative operations - others very messy
    if(dep[a] - dep[b] == idx[a] - idx[b]) {
        if(dep[a] > dep[b]) swap(a, b);
        sgtree::modifyR(b, dep[b] - dep[a], 1); //remove +1 if querying vals at edges (not vertices)
        return;
    }
    if(dep[top[a]] > dep[top[b]]) swap(a, b);
    sgtree::modifyR(b, dep[b] - dep[top[b]], 1);
    modify(a, top[b]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + N, 0ll);
    G(n) G(q)
    F(i, 0, q) {
        G(u) G(v) G(x)
        if(dsu(u) - dsu(v)) {
            tree[u].push_back(v);
            tree[v].push_back(u);
            if(x) ones.insert({u, v}), ones.insert({v, u});
            ans[i] = true;
            par[dsu(u)] = dsu(v);
        } else edges.push_back({{i, x}, {u, v}});
    }
    F(i, 1, n + 1) if(!sz[i]) {
        dfs1(i, N - 1, 1);
        dfs2(i, N - 1, N - 1);
    }
    F(i, 1, n + 1) sgtree::modifyP(i, 0);
    for(auto a : edges) if(((col[a.V.K] + col[a.V.V] + a.K.V) & 1) && !query(a.V.K, a.V.V))
        modify(a.V.K, a.V.V), ans[a.K.K] = true;
    F(i, 0, q) cout << (ans[i] ? "YES\n" : "NO\n");
}