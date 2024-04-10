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

ll ct[20], p[20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[0] = 1;
    F(i, 1, 20) p[i] = 10 * p[i - 1];
    G(tc) while(tc--) {
        memset(ct, 0, sizeof ct);
        G(x) G(n) 
        string s = to_string(x);
        reverse(A(s));
        F(i, 0, s.size()) ct[i] = s[i] - '0';
        while(accumulate(ct, ct + 20, 0ll) < n) {
            ll i = 1; while(!ct[i]) i++;
            ct[i]--; ct[i - 1] += 10;
        }
        vector<ll> ans;
        ll i = 0;
        while(ans.size() < n - 1) {
            while(!ct[i]) i++;
            ct[i]--; x -= p[i];
            ans.push_back(p[i]);
        }
        for(ll z : ans) cout << z << ' ';
        cout << x << '\n';
    }
}