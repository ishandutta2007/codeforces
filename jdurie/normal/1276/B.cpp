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
#define N 200010

ll par[N], mask[N], sz[N];
ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m) G(a) G(b)
        F(i, 1, n + 1) { par[i] = i; mask[i] = 0; sz[i] = 1;}
        while(m--) {
            G(u) G(v)
            ll umask = u == a ? 1 : (u == b ? 2 : 0);
            ll vmask = v == a ? 1 : (v == b ? 2 : 0);
            if(umask && vmask) continue;
            if(umask) mask[dsu(v)] |= umask;
            else if(vmask) mask[dsu(u)] |= vmask;
            else if(dsu(u) != dsu(v)) {
                sz[dsu(v)] += sz[dsu(u)];
                mask[dsu(v)] |= mask[dsu(u)];
                par[dsu(u)] = dsu(v);
            }
        }
        ll aCt = 0, bCt = 0;
        F(i, 1, n + 1) if(dsu(i) == i) {
            if(mask[i] == 1) aCt += sz[i];
            else if(mask[i] == 2) bCt += sz[i];
        }
        cout << aCt * bCt << '\n';
    }
}