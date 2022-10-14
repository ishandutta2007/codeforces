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
//#define N 200010
#define Q(i) (i - '0')

ll ct[10], mn[10], mx[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k) GS(s)
        fill_n(ct, 10, 0);
        for(char c : s) ct[Q(c)]++;
        fill_n(mn, 10, M); fill_n(mx, 10, -1);
        F(i, 0, s.size()) mn[Q(s[i])] = min(mn[Q(s[i])], i), mx[Q(s[i])] = max(mn[Q(s[i])], i);
        ll ans = 0;
        for(char c : s) ans += 11 * Q(c);
        ll bst = ans;
        F(a, 0, 10) F(b, 0, 10) {
            if(a == b && ct[a] < 2) continue;
            if(!ct[a] || !ct[b]) continue;
            ll v = mn[a] + n - 1 - mx[b];
            if(v <= k || (v == k + 1 && mn[a] > mx[b])) bst = min(bst, ans - a - 10 * b);
        }
        cout << bst << '\n';
    }
}