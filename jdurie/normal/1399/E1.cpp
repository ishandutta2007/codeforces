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

vector<pl> tree[N];
ll parW[N], sz[N];

ll dfs(ll i, ll p) {
    sz[i] = tree[i].size() == 1 ? 1 : 0;
    for(pl j : tree[i])
        if(j.K - p) sz[i] += dfs(j.K, i);
        else parW[i] = j.V;
    return sz[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(S)
        F(i, 0, n - 1) {
            G(u) G(v) G(w)
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
        }
        dfs(1, 1);
        set<pair<pl, pl>> q;
        ll sm = 0, ans = 0;
        F(i, 2, n + 1) sm += sz[i] * parW[i], q.insert({{ sz[i] * ((parW[i] + 1) / 2), i }, { sz[i], parW[i] }});
        while(sm > S) {
            ans++;
            auto a = *q.rbegin(); q.erase(a);
            sm -= a.K.K;
            a.V.V /= 2;
            a.K.K = a.V.K * ((a.V.V + 1) / 2);
            q.insert(a);
        }
        cout << ans << '\n';
        F(i, 1, n + 1) tree[i].clear();
    }
}