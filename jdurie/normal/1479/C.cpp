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
#define N 23

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(l) G(r)
    vector<pair<pl, ll>> edges;
    F(i, 1, N) {
        ll w = i == 1 ? 1 : (1 << (i - 2));
        F(j, i + 1, N) edges.emplace_back(pl{i, j}, w);
    }
    if(l == 1) edges.emplace_back(pl{1, N}, 1), l++;
    F(i, 1, N) if((r - l + 1) & (1 << (i - 2))) edges.emplace_back(pl{i, N}, l - 1), l += (1 << (i - 2));
    cout << "YES\n" << N << ' ' << edges.size() << '\n';
    for(auto a : edges) cout << a.K.K << ' ' << a.K.V << ' ' << a.V << '\n';
}