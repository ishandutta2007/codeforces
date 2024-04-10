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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

ll l, r, x, y;
set<pl> ans;

void add(ll a, ll b) {
    if(a > b) swap(a, b);
    if(__gcd(a, b) != x) return;
    if(l <= a && b <= r) ans.insert({a, b}), ans.insert({b, a});
}

vector<ll> fx, fy;

vector<ll> fact(ll a) {
    vector<ll> v;
    for(ll i = 1; i * i <= a; ++i) if(!(a % i)) {
        v.push_back(i);
        if(i - a / i) v.push_back(a / i);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r >> x >> y;
    fx = fact(x); fy = fact(y);
    for(ll q : fx) for(ll z : fy) add(q * z, (x / q) * (y / z));
    cout << ans.size() << '\n';
}