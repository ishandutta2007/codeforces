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

string grid[N];
ll n, m;

pl works(ll k) {
    ll mn1 = LLONG_MIN, mn2 = LLONG_MIN;
    ll mx1 = LLONG_MAX, mx2 = LLONG_MAX;
    F(i, 0, n) F(j, 0, m) if(grid[i][j] == 'B') {
        mn1 = max(mn1, i + j - k); mx1 = min(mx1, i + j + k);
        mn2 = max(mn2, i - j - k); mx2 = min(mx2, i - j + k);
    }
    F(i, 0, n) F(j, 0, m)
        if(i + j >= mn1 && i + j <= mx1 && i - j >= mn2 && i - j <= mx2)
            return {i, j};
    return {-1, -1};
}

pl bsch(ll l, ll r) {
    if(l == r) return works(l);
    ll md = (l + r) / 2;
    return works(md).K == -1 ? bsch(md + 1, r) : bsch(l, md);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        F(i, 0, n) cin >> grid[i];
        pl ans = bsch(0, M);
        cout << ans.K + 1 << ' ' << ans.V + 1 << '\n';
    }
}