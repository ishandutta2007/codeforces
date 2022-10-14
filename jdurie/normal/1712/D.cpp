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
#define N 200010

ll n, k, a[N];
bool b[N];

bool works(ll m) {
    ll ctl = 0; fill_n(b, n, 0);
    F(i, 0, n) {
        if(a[i] * 2 < m) ctl++, b[i] = true;
        if(a[i] >= m) b[i] = true;
    }
    F(i, 1, n) if(b[i] && b[i - 1]) return ctl <= k;
    F(i, 0, n) if(b[i]) return ctl + 1 <= k;
    return k >= 2;
}

ll bsch(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return works(m) ? bsch(m, r) : bsch(l, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> k;
        F(i, 0, n) cin >> a[i];
        cout << bsch(1, M - 7) << '\n';
    }
}