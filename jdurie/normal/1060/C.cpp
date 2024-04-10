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
#define N 2010

ll a[N], b[N];
ll bst1[N][N], bst2[N][N];
ll c1[N], c2[N];

ll bsch(ll l, ll r, ll mx) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return c2[m] <= mx ? bsch(m, r, mx) : bsch(l, m - 1, mx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(c1, N, LLONG_MAX);
    fill_n(c2, N, LLONG_MAX);
    G(n) G(m)
    F(i, 0, n) cin >> a[i], bst1[i][1] = a[i];
    F(i, 0, m) cin >> b[i], bst2[i][1] = b[i];
    c1[1] = *min_element(a, a + n);
    c2[1] = *min_element(b, b + m);
    G(x)
    F(l, 2, N) {
        F(i, 0, n - l + 1) bst1[i][l] = bst1[i][l - 1] + a[i + l - 1], c1[l] = min(c1[l], bst1[i][l]);
        F(i, 0, m - l + 1) bst2[i][l] = bst2[i][l - 1] + b[i + l - 1], c2[l] = min(c2[l], bst2[i][l]);
    }
    FD(l, m - 2, -1) c2[l] = min(c2[l], c2[l + 1]);
    ll ans = 0;
    F(l, 1, n + 1) {
        ll z = bsch(0, m, x / c1[l]);
        ans = max(ans, z * l);
    }
    cout << ans << '\n';
}