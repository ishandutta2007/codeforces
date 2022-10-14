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

pl dfs(ll i, ll p = -1) {
    pl ans = {1, i};
    for(ll j : tree[i]) if(j - p) {
        pl q = dfs(j, i);
        if(1 + q.K > ans.K) ans = {1 + q.K, q.V};
    }
    return ans;
}

ll dfs2(ll a, ll b, ll p = -1) {
    if(a == b) return 0;
    for(ll j : tree[a]) if(j - p) {
        ll k = dfs2(j, b, a);
        if(~k) return k + 1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(a) G(b) G(da) G(db)
        F(i, 0, n - 1) {
            G(u) G(v)
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        if(db < 2 * da + 1) cout << "Alice\n";
        else {
            ll diam = dfs(dfs(1).V).K;
            ll dist = dfs2(a, b);
            if(dist > da && diam >= 2 * da + 2) cout << "Bob\n";
            else cout << "Alice\n";
        }
        F(i, 1, n + 1) tree[i].clear();
    }
}