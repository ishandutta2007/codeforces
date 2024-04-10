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
#define N 4000010
#define L 20

ll ct[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    while(n--) {
        G(a) ll cur = 1;
        FD(i, L - 1, -1)
            if((a >> i) & 1) cur = cur * 2 + 1;
            else cur *= 2;
        ct[cur] = 1;
    }
    FD(i, N / 2 - 1, -1) ct[i] += ct[2 * i] + ct[2 * i + 1];
    ll xr = 0;
    while(m--) {
        G(x) xr ^= x;
        ll cur = 1, p = 0;
        FD(i, L - 1, -1) {
            if((xr >> i) & 1) {
                if(ct[2 * cur + 1] == (1 << i)) cur *= 2, p *= 2;
                else cur = cur * 2 + 1, p = 2 * p + 1;
            } else {
                if(ct[2 * cur] == (1 << i)) cur = cur * 2 + 1, p = p * 2 + 1;
                else cur *= 2, p *= 2;
            }
        }
        cout << (p ^ xr) << '\n';
    }
}