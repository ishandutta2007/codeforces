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
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

ll k;
vector<pair<ll, char>> v;

void process(ll x, char c) {
    if(k && x) v.emplace_back(min(k, x), c), k = max(0ll, k - x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m) cin >> k;
    ll roads = 2 * ((n - 1) * m + (m - 1) * n);
    if(k > roads) EX("NO")
    string s = "";
    F(i, 0, n - 1) process(1, 'D'), process(m - 1, 'R'), process(m - 1, 'L');
    process(n - 1, 'U');
    F(i, 0, m - 1) process(1, 'R'), process(n - 1, 'D'), process(n - 1, 'U');
    process(m - 1, 'L');
    cout << "YES\n" << v.size() << '\n';
    for(auto a : v) cout << a.K << ' ' << a.V << '\n';
}