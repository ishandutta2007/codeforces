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

vector<ll> tree[N], sts, ord;
ll a[N], f[N];

ll ff(ll i) {
    f[i] = a[i];
    for(ll j : tree[i]) f[i] += max(0ll, ff(j));
    return f[i];
}

void inorder(ll i);

void h(ll i, bool g) {
    for(ll j : tree[i]) if(g == (f[j] >= 0)) inorder(j);
}

void inorder(ll i) {
    h(i, true); ord.push_back(i); h(i, false);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 1, n + 1) cin >> a[i];
    F(i, 1, n + 1) {
        G(b) if(~b) tree[b].push_back(i); else sts.push_back(i);
    }
    ll ans = 0;
    for(ll s : sts) ff(s);
    F(i, 1, n + 1) ans += f[i];
    for(ll s : sts) inorder(s);
    cout << ans << '\n';
    for(ll o : ord) cout << o << ' ';
    cout << '\n';
}