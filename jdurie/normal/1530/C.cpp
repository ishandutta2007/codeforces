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

ll n, a[N], b[N];

bool works(ll m) {
    ll drp = (m + n) / 4;
    ll sca = 0, scb = 0;
    sca += (m - max(0ll, drp - n)) * 100ll;
    F(i, drp, n) sca += a[i];
    ll x = max(0ll, drp - m);
    F(i, x, n) scb += b[i];
    return sca >= scb;
}

ll bsch(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return works(m) ? bsch(l, m) : bsch(m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n;
        F(i, 0, n) cin >> a[i];
        F(i, 0, n) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        cout << bsch(0, M) << '\n';
    }
}