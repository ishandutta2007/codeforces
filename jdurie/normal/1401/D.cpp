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
#define N 100010

vector<ll> v, tree[N];
ll n, m, ps[N], prod[N];

ll dfs(ll i, ll p) {
    ll sz = 1;
    for(ll j : tree[i]) if(j - p) sz += dfs(j, i);
    if(i - 1) v.push_back(sz * (n - sz));
    return sz;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n;
        fill_n(prod, n, 1);
        F(i, 1, n + 1) tree[i].clear();
        v.clear();
        F(i, 0, n - 1) {
            G(u) G(w)
            tree[u].push_back(w);
            tree[w].push_back(u);
        }
        cin >> m;
        F(i, 0, m) cin >> ps[i];
        dfs(1, 1);
        sort(A(v)), reverse(A(v));
        sort(ps, ps + m), reverse(ps, ps + m);
        ll pi = 0;
        F(i, 0, m - n + 1) prod[0] = (prod[0] * ps[pi++]) % M;
        F(i, 0, n - 1) if(pi - m) prod[i] = (prod[i] * ps[pi++]) % M;
        ll ans = 0;
        F(i, 0, n - 1) ans = (ans + prod[i] * (v[i] % M) % M) % M;
        cout << ans << '\n';
    }
}