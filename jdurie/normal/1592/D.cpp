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
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 1010

vector<ll> tree[N];
vector<pl> e;
ll ans;

ll ask(vector<ll> qv) {
    set<ll> s;
    for(ll i : qv) s.insert(e[i].K), s.insert(e[i].V);
    cout << "? " << s.size();
    for(ll x : s) cout << ' ' << x;
    cout << endl;
    G(res) return res;
}

void dfs(ll i, ll p) {
    if(i - p) e.emplace_back(i, p);
    for(ll j : tree[i]) if(j - p) dfs(j, i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 1);
    vector<ll> qv;
    F(i, 0, n - 1) qv.push_back(i);
    ans = ask(qv);
    while(qv.size() > 1) {
        vector<ll> t1, t2;
        F(i, 0, qv.size())
            if(i < qv.size() / 2) t1.push_back(qv[i]);
            else t2.push_back(qv[i]);
        if(ask(t1) == ans) qv = t1;
        else qv = t2;
    }
    cout << "! " << e[qv[0]].K << ' ' << e[qv[0]].V << endl;
}