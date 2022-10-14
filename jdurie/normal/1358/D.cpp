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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 400010

ll d[N], h[N], pd[N], ph[N], n, x;

#define TRAIL(d, k) (d * (d + 1) / 2 - (d - k) * (d - k + 1) / 2)

ll bSearch(ll l, ll r, ll i) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return pd[i] - pd[m] <= x ? bSearch(l, m, i) : bSearch(m + 1, r, i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    F(i, 0, n) { 
        cin >> d[i]; d[i + n] = d[i];
        h[i] = h[i + n] = d[i] * (d[i] + 1) / 2;
    }
    pd[0] = d[0];
    ph[0] = h[0];
    F(i, 1, 2 * n) {
        pd[i] = pd[i - 1] + d[i];
        ph[i] = ph[i - 1] + h[i];
    }  
    ll ans = 0;
    F(i, 0, 2 * n) if(pd[i] >= x) {
        if(pd[i] == x) ans = max(ans, ph[i]);
        else {
            ll j = bSearch(0, i, i);
            ans = max(ans, ph[i] - ph[j] + TRAIL(d[j], (x - pd[i] + pd[j])));
        }
    }
    EX(ans)
}