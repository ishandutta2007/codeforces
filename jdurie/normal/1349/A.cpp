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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

ll a[N];
vector<ll> fuck[2 * N];

ll poww(ll a, ll p) {
    return p == 0 ? 1 : a * poww(a, p - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n)
    F(i, 0, n) {
        G(x)
        for(int j = 2; j * j <= x; j++) {
            if(x % j == 0) {
                ll ct = 0;
                while(x % j == 0) {
                    x /= j;
                    ct++;
                }
                fuck[j].push_back(ct);
            }
        }
        if(x > 1) fuck[x].push_back(1);
    }
    ll ans = 1;
    F(i, 0, 2 * N)
        if(fuck[i].size() == n - 1) {
            sort(fuck[i].begin(), fuck[i].end());
            ans *= poww(i, fuck[i][0]);
        } else if(fuck[i].size() == n) {
            sort(fuck[i].begin(), fuck[i].end());
            ans *= poww(i, fuck[i][1]);
        }
    EX(ans)
}