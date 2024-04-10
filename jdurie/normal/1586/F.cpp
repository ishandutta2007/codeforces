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
#define N 1010

ll k, ans[N][N];

void solve(ll l, ll r, ll c) {
    if(l == r) return;
    if(r - l < k) {
        F(i, l, r + 1) F(j, i + 1, r + 1) ans[i][j] = c;
        return;
    }
    ll d = (r - l + k) / k;
    F(i, l, r + 1) F(j, i + 1, r + 1) if((i - l) / d - (j - l) / d) ans[i][j] = c;
    while(1) {
        if(l + d - 1 >= r) { solve(l, r, c + 1); break; }
        solve(l, l + d - 1, c + 1);
        l += d;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) cin >> k;
    solve(0, n - 1, 1);
    ll mxc = 1; F(i, 0, n) F(j, i + 1, n) mxc = max(mxc, ans[i][j]);
    cout << mxc << '\n';
    F(i, 0, n) F(j, i + 1, n) cout << ans[i][j] << ' ';
    cout << '\n'; 
}