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
#define M 1000000007 //9982443531
#define N 200010
#define L 25

vector<ll> mess[N];
pl sm[L][N];

bool gtr(pl a, pl b) { return a.K * b.V > b.K * a.V; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) {
        G(m) G(k)
        mess[m].push_back(k);
    }
    F(i, 1, 21) {
        F(j, 0, N) {
            sm[i][j].V = j;
            for(ll x : mess[j]) sm[i][j].K += min(i, x);
        }
        sort(sm[i], sm[i] + N);
        reverse(sm[i], sm[i] + N);
    }
    pl bst = {0, 1}; vector<ll> ans;
    F(i, 1, 20) {
        vector<ll> m;
        pl tot = {0, i};
        F(j, 0, i) tot.K += sm[i][j].K, m.push_back(sm[i][j].V);
        if(gtr(tot, bst)) bst = tot, ans = m;
    }
    vector<ll> m;
    pl tot = {0, 1};
    F(j, 0, N) {
        tot.K += sm[20][j].K, m.push_back(sm[20][j].V);
        tot.V = j + 1;
        if(tot.V >= 20 && gtr(tot, bst)) bst = tot, ans = m;
    }
    cout << ans.size() << '\n';
    for(ll x : ans) cout << x << ' ';
    cout << '\n';
}