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
#define N 200010

vector<pl> graph[N];
set<ll> s[9][9];
bool bad[9][9][9][9], bad2[9][9];
ll ct[9], cur[9];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m) G(k)
    while(m--) {
        G(u) G(v) G(w)
        graph[u].emplace_back(w, v);
    }
    F(i, 1, n + 1) {
        sort(A(graph[i]));
        F(j, 0, graph[i].size()) {
            if(s[graph[i].size() - 1][j].count(graph[i][j].V)) bad2[graph[i].size() - 1][j] = true;
            s[graph[i].size() - 1][j].insert(graph[i][j].V);
        }
    }
    F(i1, 0, k) F(j1, 0, i1 + 1) 
        F(i2, 0, i1) F(j2, 0, i2 + 1) {
            for(ll x : s[i1][j1]) if(s[i2][j2].count(x)) {
                bad[i1][j1][i2][j2] = true;
                break;
            }
        }
    ll ans = 0;
    iota(ct, ct + k, 0);
    fill(ct + k, ct + 9, 0);
    #define Q(i) for(cur[i] = 0; cur[i] <= ct[i]; cur[i]++)
    Q(0) Q(1) Q(2) Q(3) Q(4) Q(5) Q(6) Q(7) Q(8) {
        bool ok = true;
        F(i, 0, k) if(bad2[i][cur[i]]) {
            ok = false;
            break;
        }
        if(ok) F(i, 0, k) F(j, 0, i) if(bad[i][cur[i]][j][cur[j]]) {
            ok = false;
            break;
        }
        if(ok) ans++;
    }
    cout << ans << '\n';
}