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
#define N 100010

ll x[26][26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) GS(a) GS(b)
        F(i, 0, 26) F(j, 0, 26) x[i][j] = 0;
        bool ok = true;
        F(i, 0, n) {
            if(a[i] > b[i]) ok = false;
            x[a[i] - 'a'][b[i] - 'a']++;
        }
        if(!ok) cout << "-1\n";
        else {
            ll ans = 0;
            F(c1, 0, 26) {
                ll nxt = -1;
                F(c2, c1 + 1, 26) if(x[c1][c2]) { nxt = c2; ans++; break; }
                if(~nxt) F(c2, nxt + 1, 26) x[nxt][c2] += x[c1][c2];
            }
            cout << ans << '\n';
        }
    }
}