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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

vector<ll> tree[N];
ll a[N];

ll dfs(ll i, ll p) {
    bool spare = false;
    ll deg = tree[i].size();
    for(ll j : tree[i]) if(j - p) {
        ll aj = dfs(j, i);
        if(aj == 2) deg--;
        else if(aj == 3) spare = true;
    }
    if(spare) return a[i] = 3;
    return a[i] = (deg & 1 ? 1 : 2);
}

void dfs2(ll i, ll p) {
    ll deg = tree[i].size();
    for(ll j : tree[i]) if(j - p && a[j] == 2) dfs2(j, i);
    ll k = -1;
    for(ll j : tree[i]) if(j - p && a[j] == 3 && deg % 2) dfs2(j, i), k = j;
    cout << i << '\n';
    for(ll j : tree[i]) if(j - p && j - k && a[j] - 2) dfs2(j, i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) ll root = -1;
    F(i, 1, n + 1) {
        G(x)
        if(x) {
            tree[i].push_back(x);
            tree[x].push_back(i);
        } else root = i;
    }
    if(dfs(root, 0) & 2) {
        cout << "YES\n";
        dfs2(root, 0);
    } else cout << "NO\n";
}