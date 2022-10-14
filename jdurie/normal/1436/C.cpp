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
#define NCR(n, r) (f[n] * inv(f[r], M) % M * inv(f[(n) - (r)], M) % M)
#define M 1000000007 //998244353
#define N 1010

ll inv(ll a, ll b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }

ll f[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M;
    G(n) G(x) G(pos)
    ll l = 0, r = n;
    set<ll> ls, rs;
    while(l < r) {
        ll m = (l + r) / 2;
        if(m < pos) ls.insert(m), l = m + 1;
        else if(m == pos) l = m + 1;
        else rs.insert(m), r = m; 
    }
    ll lct = ls.size(), rct = rs.size();
    if(lct >= x || rct > n - x) EX(0)
    cout << (NCR(x - 1, lct) * f[lct] % M * NCR(n - x, rct) % M * f[rct] % M * f[n - 1 - lct - rct] % M) << '\n';
}