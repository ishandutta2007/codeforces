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
#define N 510

ll a[N], b[N], s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(x)
        F(i, 0, n) cin >> a[i];
        copy_n(a, n, s); s[n] = x; sort(s, s + n + 1);
        ll best = N;
        F(i, 0, n + 1) {
            F(j, 0, i) b[j] = s[j];
            F(j, i + 1, n + 1) b[j - 1] = s[j]; 
            vector<ll> bad; set<ll> bads;
            F(j, 0, n) if(b[j] - a[j]) bad.push_back(a[j]), bads.insert(a[j]);
            if(!(bad.size() && (!is_sorted(A(bad)) || bad.size() != bads.size() || bad[0] <= x || bad.back() != s[i]))) best = min(best, (ll)bad.size());
        }
        cout << (best == N ? -1 : best) << '\n';
    }
}