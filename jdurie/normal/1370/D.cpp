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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

ll n, k, a[N];

bool worksE(ll m) {
    ll ct = 0, maxI = k % 2 ? n - 1 : n;
    F(i, 1, maxI) if(a[i] <= m) { ct++; i++; }
    return ct >= k / 2;
}

bool worksO(ll m) {
    ll ct = 0, maxI = k % 2 ? n : n - 1;
    F(i, 0, maxI) if(a[i] <= m) { ct++; i++; }
    return ct >= (k + 1) / 2;
}

ll bSearch(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return worksO(m) || worksE(m) ? bSearch(l, m) : bSearch(m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    F(i, 0, n) cin >> a[i];
    cout << bSearch(1, M) << '\n';
}