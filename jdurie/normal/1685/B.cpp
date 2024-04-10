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
        G(a) G(b) G(ab) G(ba) GS(s)
        ll ca = count(A(s), 'A'), cb = count(A(s), 'B');
        if(ca != a + ab + ba || cb != b + ab + ba) cout << "NO\n";
        else {
            vector<ll> od, eva, evb;
            ll st = 0;
            F(i, 0, s.size()) if(i + 1 == s.size() || s[i] == s[i + 1]) {
                if((i - st) & 1) {
                    if(s[st] == 'A') eva.push_back(i - st + 1); else evb.push_back(i - st + 1);
                } else od.push_back(i - st + 1);
                st = i + 1;
            }
            sort(A(eva)); sort(A(evb));
            for(ll x : eva) {
                x /= 2;
                ll k = min(x, ab);
                x -= k, ab -= k;
                ba -= min(ba, max(0ll, x - 1));
            }
            for(ll x : evb) {
                x /= 2;
                ll k = min(x, ba);
                x -= k, ba -= k;
                ab -= min(ab, max(0ll, x - 1));
            }
            for(ll x : od) {
                x /= 2;
                ll k = min(x, ab);
                x -= k, ab -= k;
                k = min(x, ba);
                x -= k, ba -= k;
            }
            cout << (ab || ba ? "NO\n" : "YES\n");
        }
    }
}