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
//#define N 100010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) GS(a) GS(b)
    ll ans = 0;
    F(i, 0, n) if(n - 1 - i > i) {
        set<char> sa = {a[i], a[n - 1 - i]};
        set<char> sb = {b[i], b[n - 1 - i]};
        if(sa.size() == 1 && sb.size() == 2) {
            if(sb.count(*sa.begin())) ans++;
            else ans += 2;
        } else if(sa.size() == 2 && sb.size() == 1) ans++;
        else if(sa.size() == 2 && sb.size() == 2) {
            if(!sa.count(*sb.begin())) ans++;
            if(!sa.count(*sb.rbegin())) ans++;
        }
    }
    if(n & 1 && a[n / 2] - b[n / 2]) ans++;
    cout << ans << '\n';
}