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
#define L 32

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<ll> s;
    G(n) while(n--) { G(x) s.insert(x); }
    vector<ll> v = {1, *s.begin()};
    for(ll x : s) F(j, 0, L) {
        if(s.count(x + (1ll << j)) && s.count(x + (1ll << (j + 1)))) v = max(v, vector<ll>{3, x, x + (1ll << j), x + (1ll << (j + 1))});
        else if(s.count(x + (1ll << j))) v = max(v, vector<ll>{2, x, x + (1ll << j)});
    }
    cout << v[0] << '\n';
    F(i, 1, v.size()) cout << v[i] << ' ';
    cout << '\n';
}