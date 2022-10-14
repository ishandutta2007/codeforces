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
#define N 400010

vector<ll> tree[N];
bool gone[N];
ll deg[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k)
        F(i, 0, n - 1) {
            G(u) G(v)
            tree[u].push_back(v);
            tree[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        vector<ll> leaves;
        F(i, 1, n + 1) if(deg[i] <= 1) leaves.push_back(i);
        while(k-- && leaves.size()) {
            vector<ll> newleaves;
            for(ll l : leaves) {
                if(!gone[l]) for(ll j : tree[l]) if(!gone[j]) {
                    deg[j]--;
                    if(deg[j] <= 1) newleaves.push_back(j);
                }
                gone[l] = true;
            }
            leaves = newleaves;
        }
        ll ans = 0;
        F(i, 1, n + 1) {
            if(!gone[i]) ans++; else gone[i] = false;
            tree[i].clear(); deg[i] = 0;
        }
        cout << ans << '\n';
    }
}