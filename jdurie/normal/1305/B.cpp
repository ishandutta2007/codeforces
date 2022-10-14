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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 1010

ll cl[N];
vector<ll> ans, ans2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    GS(s)
    ll n = s.size();
    FD(i, n - 1, -1) {
        if(s[i] == ')') cl[i] = 1;
        if(i != n - 1) cl[i] += cl[i + 1];
    }
    F(i, 0, n) if(s[i] == '(' && cl[i] > ans.size()) ans.push_back(i);
    FD(i, n - 1, -1) if(s[i] == ')' && ans2.size() < ans.size()) ans2.push_back(i);
    reverse(ans2.begin(), ans2.end());
    if(ans.empty()) EX(0)
    cout << "1\n" << ans.size() + ans2.size() << '\n';
    for(ll i : ans) cout << i + 1 << ' ';
    for(ll i : ans2) cout << i + 1 << ' ';
    cout << '\n';
}