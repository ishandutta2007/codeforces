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

bool ispalind(ll mn) {
    ll h = mn / 60, m = mn % 60;
    string sh = to_string(h), sm = to_string(m);
    while(sh.size() < 2) sh = "0" + sh;
    while(sm.size() < 2) sm = "0" + sm;
    string a = sh + ":" + sm, b = a;
    reverse(A(b));
    return a == b;
}

ll convert(string s) {
    ll h = stoll(s.substr(0, 2)), m = stoll(s.substr(3));
    return h * 60 + m;
}

ll Q = 24 * 60;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        GS(s) G(x)
        ll m = convert(s), g = __gcd(x, Q), ans = 0;
        F(i, 0, Q) if(!((i - m + Q) % g) && ispalind(i)) ans++;
        cout << ans << '\n';
    }
}