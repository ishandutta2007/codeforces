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
#define N 100010

ll n, xr[N], pxr[N], val[N], idxOf[N];

ll query(string s, ll i, ll j) { cout << s << ' ' << i << ' ' << j << endl; G(res) return res; }

void print() {
    cout << '!';
    F(i, 1, n + 1) cout << ' ' << val[i];
    cout << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(idxOf, -1, sizeof idxOf);
    cin >> n;
    ll i1 = -1, i2 = -1;
    idxOf[0] = 0;
    F(i, 1, n) {
        pxr[i] = xr[i] = query("XOR", i, i + 1);
        pxr[i] ^= pxr[i - 1];
        if(~idxOf[pxr[i]]) {
            i1 = idxOf[pxr[i]] + 1;
            i2 = i + 1;
        } else idxOf[pxr[i]] = i;
    }
    if(~i1) {
        val[i1] = val[i2] = query("OR", i1, i2);
        val[1] = pxr[i1 - 1] ^ val[i1];
        F(i, 2, n + 1) val[i] = val[1] ^ pxr[i - 1];
        print();
    }
    ll j = 1, k = 1;
    while(pxr[j] & 1) j++;
    while(pxr[k] - 1) k++;
    j++; k++;
    ll ad = query("AND", 1, k);
    ll od = query("OR", 1, j) & 1;
    for(ll i = 0; i < n; i += 2)
        if((i & (i + 1)) == ad)
            val[1] = i + od;
    F(i, 2, n + 1) val[i] = val[1] ^ pxr[i - 1];
    print();
}