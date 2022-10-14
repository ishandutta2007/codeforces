#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 1000010

bool toobig(ll m, ll n, ll s) { return m * n > s; }

bool toosmall(ll m, ll n, ll s) { return m * n + n * (n - 1) / 2 < s; }

bool ok(ll m, ll n, ll s) { return !toobig(m, n, s) && !toosmall(m, n, s); }

ll bSearch(ll l, ll r, ll n, ll s) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    if(ok(m, n, s)) return bSearch(l, m, n, s);
    return toobig(m, n, s) ? bSearch(l, m - 1, n, s) : bSearch(m + 1, r, n, s);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) ll s = 0;
    F(i, 0, n) { G(x) s += x; }
    ll lst = bSearch(0, 1000000000000, n, s);
    cout << lst << ' ';
    s -= lst;
    while(--n) {
        if(!ok(lst, n, s)) lst++;
        s -= lst;
        cout << lst << ' ';
    }
    cout << '\n';
}