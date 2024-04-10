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
#define N 100010
#define MAXA 2010

ll a[N];
vector<ll> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(p)
    F(i, 0, n) cin >> a[i];
    sort(a, a + n);
    F(x, 1, MAXA) {
        ll cur = 0, idx = 0;
        bool ok = true;
        F(i, 0, n) {
            while(idx < n && a[idx] <= x + i) { idx++; cur++; }
            if(!(cur % p)) ok = false;
            cur--;
        }
        if(ok) ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for(ll x : ans) cout << x << ' ';
    cout << '\n';
}