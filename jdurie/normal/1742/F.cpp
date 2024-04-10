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
//#define N 200010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        map<char, ll> s, t;
        s['a'] = t['a'] = 1;
        G(q) while(q--) {
            G(tp) G(k) GS(st)
            if(tp == 1) for(char c : st) s[c] += k;
            else for(char c : st) t[c] += k;
            if(s.begin()->K < t.rbegin()->K) cout << "YES\n";
            else {
                string ans = "YES\n"; bool b = false;
                F(c, 'a', 'z' + 1) if(t[c] < s[c]) { ans = "NO\n"; break; } else if(s[c] < t[c]) b = true;
                if(!b) ans = "NO\n";
                cout << ans;
            }
            F(c, 'a', 'z' + 1) {
                if(!s[c]) s.erase(c);
                if(!t[c]) t.erase(c);
            }
        }
    }
}