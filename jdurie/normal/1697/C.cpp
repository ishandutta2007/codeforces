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
        G(n) GS(s) GS(t)
        string ss, tt;
        for(char c : s) if(c - 'b') ss.push_back(c);
        for(char c : t) if(c - 'b') tt.push_back(c);
        string ans = "YES\n"; ll ib = 0, ic = 0;
        F(i, 0, n) if(s[i] - t[i]) {
            ib = max(ib, i); ic = max(ic, i);
            if(s[i] == 'b') {
                while(ic < n && s[ic] == 'b') ic++;
                if(ic < n && s[ic] == 'c') swap(s[ic], s[i]);
                if(s[i] - t[i]) ans = "NO\n";
            } else if(s[i] == 'a') {
                while(ib < n && s[ib] == 'a') ib++;
                if(ib < n && s[ib] == 'b') swap(s[ib], s[i]);
                if(s[i] - t[i]) ans = "NO\n";
            } else ans = "NO\n";
        }
        cout << ans;
    }
}