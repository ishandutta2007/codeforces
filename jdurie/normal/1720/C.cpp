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
#define N 200010

string s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n) cin >> s[i];
        ll z = 0; bool z2 = false;
        F(i, 0, n) z += count(A(s[i]), '0');
        F(i, 0, n - 1) F(j, 0, m) if(s[i][j] == '0' && s[i + 1][j] == '0') z2 = true;
        F(i, 0, n) F(j, 0, m - 1) if(s[i][j] == '0' && s[i][j + 1] == '0') z2 = true;
        F(i, 0, n - 1) F(j, 0, m - 1)
            if(s[i][j] == '0' && s[i + 1][j + 1] == '0') z2 = true;
            else if(s[i + 1][j] == '0' && s[i][j + 1] == '0') z2 = true;
        if(!z) cout << n * m - 2 << '\n';
        else if(!z2) cout << n * m - z - 1 << '\n';
        else cout << n * m - z << '\n';
    }
}