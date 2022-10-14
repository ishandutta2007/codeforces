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

ll n, a[N];



pair<ll, pl> solve(ll l, ll r) {
    if(l > r) return {-1, {0, 0}};
    bool nn = false; ll c = 0;
    F(i, l, r + 1) {
        if(a[i] < 0) nn = !nn;
        if(abs(a[i]) == 2) c++;
    }
    if(!nn) return {c, {l, n - 1 - r}};
    ll l1 = l, c1 = c; while(a[l1] >= 0) if(abs(a[l1++]) == 2) c1--;
    if(abs(a[l1]) == 2) c1--;
    ll r1 = r, c2 = c; while(a[r1] >= 0) if(abs(a[r1--]) == 2) c2--;
    if(abs(a[r1]) == 2) c2--;
    if(c1 > c2) return {c1, {l1 + 1, n - 1 - r}};
    return {c2, {l, n - r1}};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n; F(i, 0, n) cin >> a[i];
        vector<ll> z = {-1};
        F(i, 0, n) if(!a[i]) z.push_back(i);
        z.push_back(n);
        pair<ll, pl> ans = {0, {n, 0}};
        F(i, 0, (ll)z.size() - 1) ans = max(ans, solve(z[i] + 1, z[i + 1] - 1));
        cout << ans.V.K << ' ' << ans.V.V << '\n';
    }
}