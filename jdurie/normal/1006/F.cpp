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
//#define N 100010

ll a[20][20];
map<ll, ll> vals[20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m) G(k)
    F(i, 0, n) F(j, 0, m) cin >> a[i][j];
    ll q = (n + m - 1) / 2, p = n + m - 2 - q;
    F(i, 0, (1 << q)) {
        ll cur = a[0][0], r = 0, c = 0;
        F(j, 0, q) {
            if((i >> j) & 1) r++; else c++;
            if(r >= n || c >= m) break;
            cur ^= a[r][c];
        }
        if(r >= n || c >= m) continue;
        vals[r][cur]++;
    }
    ll ans = 0;
    F(i, 0, (1 << p)) {
        ll cur = a[n - 1][m - 1], r = n - 1, c = m - 1;
        F(j, 0, p) {
            if((i >> j) & 1) r--; else c--;
            if(r < 0 || c < 0) break;
            cur ^= a[r][c];
        }
        if(r < 0 || c < 0) continue;
        cur ^= a[r][c];
        if(vals[r].count(cur ^ k)) ans += vals[r][cur ^ k];
    }
    cout << ans << '\n';
}