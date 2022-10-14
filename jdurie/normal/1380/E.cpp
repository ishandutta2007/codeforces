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
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

set<ll> discs[N];
ll par[N], ans;

ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + N, 0);
    G(n) G(m)
    ans = n - 1;
    F(i, 1, n + 1) {
        G(x) discs[x].insert(i);
        if(discs[x].count(i - 1)) ans--;
    }
    F(i, 0, m - 1) {
        cout << ans << '\n';
        G(x) G(y)
        x = dsu(x), y = dsu(y);
        if(discs[x].size() > discs[y].size()) swap(x, y);
        par[x] = y;
        for(ll j : discs[x]) {
            if(discs[y].count(j + 1)) ans--;
            if(discs[y].count(j - 1)) ans--;
        }
        for(ll j : discs[x]) discs[y].insert(j);
    }
    cout << "0\n";
}