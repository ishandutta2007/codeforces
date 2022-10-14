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
#define N 1000010

ll ctL[N], ctR[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) GS(s)
        F(i, 0, n) ctL[i] = ctR[i] = 0;
        ll c = 0;
        F(i, 0, n) if(s[i] == '*') c++; else ctL[i] = c;
        c = 0;
        FD(i, n - 1, -1) if(s[i] == '*') c++; else ctR[i] = c;
        F(i, 1, n) ctL[i] += ctL[i - 1];
        FD(i, n - 2, -1) ctR[i] += ctR[i + 1];
        ll ans = min(ctL[n - 1], ctR[0]);
        F(i, 0, n - 1) ans = min(ans, ctL[i] + ctR[i + 1]);
        cout << ans << '\n';
    }
}