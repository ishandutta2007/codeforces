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
#define N 100

ll deck[N], pos[N], newDeck[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 1, n + 1) cin >> deck[i];
    vector<vector<ll>> ops;
    while(1) {
        F(i, 1, n + 1) pos[deck[i]] = i;
        ll j = -1;
        F(i, 1, n) if(pos[i] > pos[i + 1]) j = i;
        if(!~j) break;
        ll k = pos[j + 1];
        while(deck[k] + 1 == deck[k + 1]) k++;
        vector<ll> v;
        if(pos[j + 1] - 1) v.push_back(pos[j + 1] - 1);
        v.push_back(k - pos[j + 1] + 1);
        v.push_back(pos[j] - k);
        if(pos[j] - n) v.push_back(n - pos[j]);
        ops.push_back({v.size()});
        for(ll x : v) ops.back().push_back(x);
        ll idx = 1;
        F(q, pos[j] + 1, n + 1) newDeck[idx++] = deck[q];
        F(q, k + 1, pos[j] + 1) newDeck[idx++] = deck[q];
        F(q, pos[j + 1], k + 1) newDeck[idx++] = deck[q];
        F(q, 1, pos[j + 1])     newDeck[idx++] = deck[q];
        F(i, 1, n + 1) deck[i] = newDeck[i];
    }
    cout << ops.size() << '\n';
    for(vector<ll> v : ops) {
        for(ll x : v) cout << x << ' ';
        cout << '\n';
    }
}