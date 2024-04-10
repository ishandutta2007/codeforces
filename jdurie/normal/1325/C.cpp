#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
typedef complex<ld> pt;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << #a << ": { "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define MC(a, x) a.lower_bound(x)
#define MU(a, x) a.upper_bound(x)
#define MF(a, x) (x < (*a.begin()).K ? a.end() : --MU(a, x))
#define ML(a, x) (x <= (*a.begin()).K ? a.end() : --MC(a, x))
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 100010

vector<ll> tree[N];
map<pl, ll> edges;
ll ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n)
    F(i, 1, n + 1) ans[i] = -1;
    F(i, 1, n) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
        edges[{u, v}] = i;
        edges[{v, u}] = i;
    }
    ll maxV = -1;
    F(i, 1, n + 1) if(tree[i].size() >= 3) {
        maxV = i;
        break;
    }
    if(maxV == -1) {
        F(i, 0, n - 1) cout << i << endl;
        exit(0);
    }
    F(i, 0, 3) ans[edges[{maxV, tree[maxV][i]}]] = i;
    ll k = 3;
    F(i, 1, n) if(ans[i] == -1) ans[i] = k++;
    F(i, 1, n) cout << ans[i] << endl;
}