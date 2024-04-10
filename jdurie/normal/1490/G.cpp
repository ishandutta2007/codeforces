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

ll a[N], mx[N];

ll bSearch(ll l, ll r, ll x) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return mx[m] >= x ? bSearch(l, m, x) : bSearch(m + 1, r, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n) cin >> a[i];
        F(i, 1, n) a[i] += a[i - 1];
        mx[0] = a[0];
        F(i, 1, n) mx[i] = max(a[i], mx[i - 1]);
        while(m--) {
            G(x)
            if(x <= mx[n - 1]) {
                ll i = bSearch(0, n - 1, x);
                cout << i << ' ';
            } else if(a[n - 1] <= 0) cout << "-1 ";
            else {
                ll cyc = (x - mx[n - 1] + a[n - 1] - 1) / a[n - 1];
                ll i = bSearch(0, n - 1, x - cyc * a[n - 1]);
                cout << cyc * n + i << ' ';
            }
        }
        cout << '\n';
    }
}