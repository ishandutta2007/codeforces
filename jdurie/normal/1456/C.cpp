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
#define N 500010

ll a[N];
map<ll, ll> vals;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(k) F(i, 0, n) cin >> a[i];
    sort(a, a + n); reverse(a, a + n);
    ll x = 0, ans = 0, id = -1;
    F(i, 0, n) {
        if(x < 0) break;
        ans += x;
        id = i;
        x += a[i];
    }
    vals[x] = 1;
    if(k) vals[0] = k;
    F(i, id + 1, n) {
        ll mx = vals.rbegin()->K;
        vals[mx]--; if(!vals[mx]) vals.erase(mx);
        ans += mx;
        vals[mx + a[i]]++;
    }
    cout << ans << '\n';
}