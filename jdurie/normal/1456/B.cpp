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
#define N 100010

ll a[N], p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) cin >> a[i];
    F(i, 0, n) p[i] = i ? p[i - 1] ^ a[i] : a[0];
    if(n > 100) cout << "1\n";
    else {
        ll ans = LLONG_MAX;
        F(i, 0, n) F(j, 0, i) F(k, 0, j + 1)
            if((p[i] ^ p[j]) < (p[j] ^ (k ? p[k - 1] : 0))) ans = min(ans, i - k - 1);
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }    
}