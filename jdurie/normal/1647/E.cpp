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
#define N 200010
#define L 40

ll p[N][L], f[N], x[N];
bool occ[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    iota(x, x + N, 0ll);
    G(n) set<ll> st, avail;
    F(i, 1, n + 1) cin >> p[i][0], st.insert(p[i][0]), avail.insert(i);
    F(j, 1, L) F(i, 1, n + 1) p[i][j] = p[p[i][j - 1]][j - 1];
    F(i, 1, n + 1) cin >> f[i], avail.erase(f[i]);
    ll rds = (*max_element(f + 1, f + n + 1) - n) / (n - st.size());
    FD(j, L - 1, -1) if((rds >> j) & 1) F(i, 1, n + 1) x[i] = p[x[i]][j];
    F(i, 1, n + 1) if(!occ[x[i]]) cout << f[x[i]] << ' ', occ[x[i]] = true;
    else {
        ll q = *avail.upper_bound(f[x[i]]);
        avail.erase(q); cout << q << ' ';
    }
    cout << '\n';
}