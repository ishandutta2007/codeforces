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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) n++;
    vector<char> v1, v2;
    ll c = 1;
    F(r, 'a', 'i') {
        ll ct = min(8ll, (r == 'h' ? n : n - 2));
        n -= ct;
        F(i, 0, ct) v1.push_back(r);
        set<ll> s;
        F(i, 1, 9) s.insert(i);
        F(i, 0, ct) {
            v2.push_back(c + '0');
            s.erase(c);
            if(i + 1 - ct) c = (r == 'h' || (n == 2 && ct < 6)  ? *s.begin() : *s.rbegin());
        }
    }
    if(v2.back() - '8') v2.back() = '8';
    F(i, 0, v1.size()) cout << v1[i] << v2[i] << ' ';
}