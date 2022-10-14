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
#define M 998244353
#define N 200010

ll a[N], sMin[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n) cin >> a[i];
    F(i, 0, m) cin >> b[i];
    b[m] = sMin[n] = LLONG_MAX;
    FD(i, n - 1, -1) sMin[i] = min(sMin[i + 1], a[i]);
    ll lst = -1, cur = -1, idx = 0, ans = 1;
    if(sMin[0] < b[0]) EX(0)
    F(i, 0, m) {
        cur = -1;
        while(sMin[idx + 1] < b[i + 1]) {
            if(a[idx] == b[i]) cur = idx;
            if(idx == n) EX(0)
            idx++;
        }
        if(a[idx] == b[i]) cur = idx;
        if(cur == -1) EX(0)
        if(lst != -1) ans = ans * (cur - lst) % M;
        lst = idx++;
        if(idx > n) EX(0)
    }
    cout << ans << '\n';
}