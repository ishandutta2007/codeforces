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
#define S 320

ll a[N];
int ct1[2 * S * N + N], ct2[2 * N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) cin >> a[i];
    int mx = 0;
    F(k, -S, S) {
        F(i, 0, n) mx = max(mx, ++ct1[a[i] - k * i + S * N]);
        F(i, 0, n) ct1[a[i] - k * i + S * N]--;
    }
    F(i, 0, n) {
        F(j, i + 1, min(n, i + S)) if(!(abs(a[j] - a[i]) % (j - i)))
            mx = max(mx, ++ct2[(a[j] - a[i]) / (j - i) + N] + 1);
        F(j, i + 1, min(n, i + S)) if(!(abs(a[j] - a[i]) % (j - i)))
            ct2[(a[j] - a[i]) / (j - i) + N]--;
    }
    cout << n - mx << '\n';
}