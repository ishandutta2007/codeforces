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

set<ll> s;
map<ll, ll> mp;

void del(ll x) { mp[x]--; if(!mp[x]) mp.erase(x); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n) { G(x) s.insert(x); }
    ll last = -1;
    for(ll x : s) {
        if(~last) mp[x - last]++;
        last = x;
    }
    cout << (n == 1 ? 0 : *s.rbegin() - *s.begin() - mp.rbegin()->K) << '\n';
    while(m--) {
        G(c) G(x)
        if(c) {
            if(s.size()) {
                auto a = *s.upper_bound(x), b = *--s.upper_bound(x);
                if(x > *s.begin() && x < *s.rbegin()) {
                del(a - b), mp[a - x]++, mp[x - b]++;
                } else if(x > *s.begin()) mp[x - b]++;
                else if(x < *s.rbegin()) mp[a - x]++;
            }
            s.insert(x);
        } else {
            s.erase(x);
            if(s.size()) {
                auto a = *s.upper_bound(x), b = *--s.upper_bound(x);
                if(x > *s.begin() && x < *s.rbegin()) {
                mp[a - b]++, del(a - x), del(x - b);
                } else if(x > *s.begin()) del(x - b);
                else if(x < *s.rbegin()) del(a - x);
            }
        }
        if(s.size() < 2) cout << "0\n";
        else cout << *s.rbegin() - *s.begin() - mp.rbegin()->K << '\n';
    }
}