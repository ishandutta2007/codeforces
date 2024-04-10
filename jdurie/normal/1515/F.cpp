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

namespace sgtree {
    typedef pl T;
    T id = {0, 0}, t[2 * N];

    T f(T a, T b) { return max(a, b); }

    void modify(ll p, T v) { //set value v at position p
        for(t[p += N] = v; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
    }

    T query(ll l, ll r) { //query on interval [l, r)
        T resl = id, resr = id;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) resl = f(resl, t[l++]);
            if(r & 1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
}

vector<pl> graph[N];
map<pl, ll> eid;
ll par[N], a[N], idx[N];
ll dsu(ll i) { return i == par[i] ? i : par[i] = dsu(par[i]); }

#define CT(i) (graph[i].size() - idx[i])

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + N, 0);
    G(n) G(m) G(x)
    F(i, 1, n + 1) cin >> a[i], sgtree::modify(i, pl{a[i], i});
    F(i, 1, m + 1) {
        G(u) G(v)
        graph[u].emplace_back(u, v);
        graph[v].emplace_back(u, v);
        eid[{u, v}] = eid[{v, u}] = i;
    }
    if(accumulate(a + 1, a + n + 1, 0ll) < (n - 1) * x) cout << "NO\n";
    else {
        cout << "YES\n";
        F(iter, 0, n - 1) {
            ll u = sgtree::query(1, n + 1).V;
            while(dsu(graph[u][idx[u]].K) == dsu(graph[u][idx[u]].V)) idx[u]++;
            ll v = dsu(graph[u][idx[u]].K) + dsu(graph[u][idx[u]].V) - u;
            cout << eid[graph[u][idx[u]]] << '\n';
            if(CT(v) > CT(u)) swap(u, v);
            sgtree::modify(v, pl{-1, -1});
            a[u] += a[v] - x;
            sgtree::modify(u, pl{a[u], u});
            F(j, idx[v], graph[v].size()) graph[u].push_back(graph[v][j]);
            par[v] = u;
        }
    }
}