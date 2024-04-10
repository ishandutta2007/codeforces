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

ll idx[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) { G(x) idx[x] = i; }
        ll ans = 1, lb = M, rb = -1;
        F(i, 0, n - 1) {
            ll mn = -1, mx = n;
            lb = min(lb, idx[i]), rb = max(rb, idx[i]);
            if(idx[i + 1] >= lb && idx[i + 1] <= rb) continue;
            else if(idx[i + 1] < lb) mn = idx[i + 1];
            else mx = idx[i + 1];
            ll k = 2 * (i + 1) - (rb - lb + 1);
            ll l = min(k, lb - mn - 1), r = min(k, mx - rb - 1);
            if(k < 0) continue;
            ans += (k + 1) * (k + 2) / 2 - (k - l) * (k - l + 1) / 2 - (k - r) * (k - r + 1) / 2;
            if(k > l + r) ans += (k - l - r - 1) * (k - l - r) / 2;
        }
        cout << ans << '\n';
    }
}