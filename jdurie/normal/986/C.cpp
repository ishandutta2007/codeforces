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

typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 4200000
#define L 23

ll n, m, k, a[N], done[N];
bool used[N], ina[N];

ll bit_select(ll mask, ll c) {
    for(ll j = 1;; j *= 2) {
        if(mask & j) c--;
        if(c < 0) return j;
    }
}

void dfs(ll mask, ll fix = 0) {
    if(done[mask] & (1 << fix)) return;
    done[mask] |= (1 << fix);
    if(ina[mask]) used[mask] = true, dfs(k - mask);
    if(fix == __builtin_popcount(mask)) return;
    dfs(mask ^ bit_select(mask, fix), fix);
    dfs(mask, fix + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; k = (1 << n) - 1;
    F(i, 0, m) cin >> a[i], ina[a[i]] = true;
    ll ans = 0;
    F(i, 0, m) if(!used[a[i]]) dfs(k - a[i]), used[a[i]] = true, ans++;
    cout << ans << '\n';
}