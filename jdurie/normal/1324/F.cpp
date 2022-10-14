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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

ll c[N], sc[N], ans[N];
vector<ll> tree[N];

ll fillSc(ll i, ll p) {
    sc[i] = c[i] ? 1 : -1;
    for(ll j : tree[i]) if(j - p) sc[i] += max(0ll, fillSc(j, i));
    return sc[i];
}

void fillAns(ll i, ll p) {
    ans[i] = sc[i];
    if(i > 1 && ans[p] > 0) {
        if(sc[i] > 0) ans[i] = max(ans[i], ans[p]);
        else ans[i] = sc[i] + ans[p];
    }
    for(ll j : tree[i]) if(j - p) fillAns(j, i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 1, n + 1) cin >> c[i];
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    fillSc(1, 1);
    fillAns(1, 1);
    F(i, 1, n + 1) cout << ans[i] << ' ';
    cout << '\n';
}