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
#define N 100010

vector<ll> tree[N];
ll n, par[N], dep[N];
map<ll, vector<ll>> mp;

ll dfs(ll i, ll p, ll d) {
    par[i] = p;
    dep[i] = d;
    set<ll> s;
    ll sz = 1;
    for(ll j : tree[i]) if(j - p) {
        ll k = dfs(j, i, d + 1);
        s.insert(k), sz += k;
    }
    s.insert(n - sz);
    mp[*s.rbegin()].push_back(i);
    return sz;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n;
        F(i, 0, n - 1) {
            G(u) G(v)
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        ll root = 1;
        while(tree[root].size() - 1) root++;
        dfs(root, 0, 0);
        vector<ll> v = mp.begin()->V;
        if(v.size() == 1)
            cout << 1 << ' ' << tree[1][0] << '\n' << 1 << ' ' << tree[1][0] << '\n';
        else {
            if(dep[v[0]] < dep[v[1]]) swap(v[0], v[1]);
            cout << root << ' ' << tree[root][0] << '\n' << root << ' ' << v[0] << '\n';
        }
        F(i, 1, n + 1) tree[i].clear();
        mp.clear();
    }
}