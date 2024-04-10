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
#define N 500010

ll a[N], pSum[N];

#define LS(i) (idx ? pSum[idx - 1] : 0)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n)
    F(i, 0, (n + 1) / 2) cin >> a[i];
    G(x) F(i, (n + 1) / 2, n) a[i] = x;
    pSum[0] = a[0];
    F(i, 1, n) pSum[i] = pSum[i - 1] + a[i];
    if(x >= 0) EX((pSum[n - 1] > 0 ? n : -1))
    else {
        ll idx = (n - 1) / 2;
        lp: while(1) {
            ll k = n - idx, sm = pSum[n - 1];
            while(k <= n && sm - LS(idx) <= 0) { idx--; k++; }
            if(k > n) EX(-1)
            for(; idx >= 0; idx--) {
                if(sm - LS(idx) <= 0) goto lp;
                sm -= x;
            }
            EX(k)
        }
    }
}