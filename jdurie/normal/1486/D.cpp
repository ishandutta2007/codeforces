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

ll n, k, a[N], d[N], mx[N];

bool works(ll m) {
    F(i, 1, n + 1) d[i] = a[i] >= m ? 1 : -1;
    F(i, 2, n + 1) d[i] += d[i - 1];
    mx[n] = d[n];
    FD(i, n - 1, -1) mx[i] = max(d[i], mx[i + 1]);
    F(i, 1, n + 1) if(i + k - 1 <= n && mx[i + k - 1] > d[i - 1]) return true;
    return false;
}

ll bSearch(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return works(m) ? bSearch(m, r) : bSearch(l, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    F(i, 1, n + 1) cin >> a[i];
    cout << bSearch(1, n) << '\n';
}