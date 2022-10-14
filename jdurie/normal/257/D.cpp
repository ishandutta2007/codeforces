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
#define N 100010

ll a[N];
bool flip[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) cin >> a[i];  
    ll k = a[n - 1];
    FD(i, n - 2, -1) {
        if(abs(a[i] - k) < abs(a[i] + k)) flip[i + 1] = true, k = a[i] - k;
        else k = a[i] + k;
    }
    //P(flip, n)
    //cout << k << '\n';
    bool f = false;
    ll cur = 0;
    F(i, 0, n) {
        if(flip[i]) f = !f;
        flip[i] = f;
        //cout << i << ' ' << flip[i] << ' ' << f << '\n';;
        if(flip[i]) cur -= a[i]; else cur += a[i];
    }
    //P(flip, n)
    if(cur < 0) F(i, 0, n) flip[i] = !flip[i];
    F(i, 0, n) if(flip[i]) cout << '-'; else cout << '+';
    cout << '\n';
}