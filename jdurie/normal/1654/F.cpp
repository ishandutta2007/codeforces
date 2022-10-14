//String Hashing
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
typedef pair<ll, ll> pl;

#define K first
#define V second
#define M 1000000321
#define OP(x, y) pl operator x (pl a, pl b) { return { a.K x b.K, (a.V y b.V) % M }; }
OP(+, +) OP(*, *) OP(-, + M -)
mt19937 gen(__builtin_ia32_rdtsc());
uniform_int_distribution<ll> dist(256, M - 1);

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define N 300010
#define L 20

string s;
pl p[N], h[N][L];
ll n, m;

bool better(ll i, ll j) {
    if(s[i] != s[j]) return s[i] < s[j];
    F(l, 1, m + 1) if(h[i][l] != h[j][l]) return better(i ^ (1 << (l - 1)), j ^ (1 << (l - 1)));
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[0] = { 1, 1 }, p[1] = { dist(gen) | 1, dist(gen) };
    F(i, 1, N) p[i] = p[i - 1] * p[1];
    cin >> m >> s; n = (1 << m);
    F(i, 0, n) h[i][0] = {s[i], s[i]};
    F(j, 1, m + 1) F(i, 0, n) h[i][j] = p[1 << (j - 1)] * h[i][j - 1] + h[i ^ (1 << (j - 1))][j - 1];
    ll ai = 0;
    F(i, 1, n) if(better(i, ai)) ai = i;
    F(i, 0, n) cout << s[ai ^ i];
    cout << '\n';
}