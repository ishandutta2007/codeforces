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
#define N 100010

ll l[N], r[N], c[N];

vector<ll> graph[N];
bool used[N];

void dfs(ll i) {
    used[i] = true;
    for(ll j : graph[i]) if(!used[j]) dfs(j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        map<ll, vector<pl>> ev;
        F(i, 0, n) {
            cin >> c[i] >> l[i] >> r[i];
            ev[l[i]].push_back({1, i});
            ev[r[i] + 1].push_back({0, i});
        }
        set<ll> zero, one;
        for(auto a : ev) {
            for(pl p : a.V) if(p.K) {
                if(c[p.V]) one.insert(p.V); else zero.insert(p.V);
            } else if(c[p.V]) one.erase(p.V); else zero.erase(p.V);
            if(one.size() && zero.size()) {
                ll lst = -1, bz = *zero.begin(), bo = *one.begin();
                for(ll x : one) {
                    if(r[x] > r[bo]) bo = x;
                    if(~lst) graph[lst].push_back(x), graph[x].push_back(lst);
                    lst = x;
                }
                for(ll x : zero) {
                    if(r[x] > r[bz]) bz = x;
                    graph[lst].push_back(x); graph[x].push_back(lst);
                    lst = x;
                }
                zero = {bz}, one = {bo};
            }
        }
        ll c = 0;
        F(i, 0, n) if(!used[i]) dfs(i), c++;
        cout << c << '\n';
        F(i, 0, n) graph[i].clear(), used[i] = 0;
    }
}