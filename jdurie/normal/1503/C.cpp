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
#define ALL(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

pl p[N];

#define A(i) p[i].K
#define C(i) p[i].V
#define D(i) (A(i) + C(i))

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, n) cin >> A(i) >> C(i);
    sort(p, p + n);
    ll mn = 0;
    set<pl> s = {{0ll, D(0)}};
    set<pl> sr = {{D(0), 0ll}};
    ll ans = LLONG_MAX;
    F(i, 1, n) {
        while(sr.size() && sr.begin()->K <= A(i)) {
            pl q = *sr.begin();
            s.erase({q.V, q.K});
            sr.erase(q);
            mn = min(mn, q.V - q.K);
        }
        ll dpi = mn + A(i);
        if(s.size()) dpi = min(dpi, s.begin()->K);
        s.insert({dpi, D(i)});
        sr.insert({D(i), dpi});
        if(A(i) == A(n - 1)) ans = min(ans, dpi);
    }
    F(i, 0, n) ans += C(i);
    cout << ans << '\n';
}