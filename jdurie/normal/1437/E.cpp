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
#define M 1000000000000000ll
#define N 500010

ll n, k, a[N], b[N];

ll solve(ll l, ll r, ll vl, ll vr) {
    if(vl + r - l + 2 > vr) EX(-1)
    if(r < l) return 0;
    vector<ll> v, lis;
    ll dr = vr - (vl + (r - l + 2));
    F(i, l, r + 1) {
        ll d = a[i] - (vl + (i - l + 1));
        if(d >= 0 && d <= dr) v.push_back(d);
    }
    for(ll x : v) {
        if(lis.empty() || x >= lis.back()) lis.push_back(x);
        else *upper_bound(A(lis), x) = x;
    }
    return (r - l + 1) - lis.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    F(i, 0, n) cin >> a[i];
    F(i, 0, k) cin >> b[i], b[i]--;
    if(!k) EX(solve(0, n - 1, -M, M))
    ll ans = solve(0, b[0] - 1, -M, a[b[0]]) + solve(b[k - 1] + 1, n - 1, a[b[k - 1]], M);
    F(i, 0, k - 1) ans += solve(b[i] + 1, b[i + 1] - 1, a[b[i]], a[b[i + 1]]);
    cout << ans << '\n';

}