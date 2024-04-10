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
#define N 510
#define MP(a, b) make_pair(min(a, b), max(a, b))

map<pl, ll> pCt;
ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        pCt.clear();
        F(i, 0, n) cin >> a[i];
        F(i, 0, n / 2) pCt[MP(a[i], a[n - 1 - i])]++;  
        F(i, 0, n) cin >> b[i];
        F(i, 0, n / 2) pCt[MP(b[i], b[n - 1 - i])]--;
        bool ok = !(n % 2) || a[n / 2] == b[n / 2];
        for(auto a : pCt) if(a.V) ok = false;
        cout << (ok ? "Yes\n" : "No\n");
    }
}