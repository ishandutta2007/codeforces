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
#define N 300010

ll n, m, k[N], c[N], a[N], b[N];

bool works(ll mm) {
    F(i, n - mm, n) if(k[i] < i - n + mm + 1) return false;
    return true;
}

ll bSearch(ll l, ll r) {
    if(l == r) return l;
    ll mm = (l + r + 1) / 2;
    return works(mm) ? bSearch(mm, r) : bSearch(l, mm - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        F(i, 0, n) cin >> k[i];
        sort(k, k + n);
        F(i, 1, m + 1) cin >> c[i];
        a[0] = c[k[0]];
        F(i, 1, n) a[i] = c[k[i]] + a[i - 1];
        b[0] = c[1];
        F(i, 1, m) b[i] = c[i + 1] + b[i - 1];
        ll q = bSearch(1, n);
        ll ans = a[n - 1];
        F(i, 1, q + 1) ans = min(ans, b[i - 1] + a[n - i - 1]);
        cout << ans << '\n';
    }
}