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
typedef complex<ll> pt;

#define X real()
#define Y imag()
#define DOT(a, b) (conj(a) * (b)).X
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
#define BAD(i) (DOT(p[i - 1] - p[i], p[i + 1] - p[i]) <= 0)
#define N 5010

pt p[N];
ll id[N];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) { G(x) G(y) p[i] = {x, y}; }
    iota(id, id + n, 1);
    F(i, 1, n - 1) if(BAD(i)) {
        swap(p[i], p[i + 1]);
        swap(id[i], id[i + 1]);
        FD(j, i - 1, 1) 
            if(BAD(j)) {
                swap(p[j], p[j + 1]);
                swap(id[j], id[j + 1]);
            } else break;
    }
    F(i, 0, n) cout << id[i] << ' ';
    cout << '\n';
}