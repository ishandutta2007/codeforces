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
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

vector<ll> a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(k)
    F(i, 0, n) {
        G(t) G(A) G(B)
        if(A && B) c.push_back(t);
        else if(A) a.push_back(t);
        else if(B) b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll z = min(a.size(), b.size());
    F(i, 0, z) c.push_back(a[i] + b[i]);
    sort(c.begin(), c.end());
    if(c.size() < k) EX(-1)
    ll ans = 0;
    F(i, 0, k) ans += c[i];
    EX(ans)
}