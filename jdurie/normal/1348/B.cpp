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
#define EX(x) { cout << x << endl; goto eotc; }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 110

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(n) G(k)
        set<ll> dist;
        F(i, 0, n) { cin >> a[i]; dist.insert(a[i]); }
        if(dist.size() > k) cout << "-1\n";
        else {
            vector<ll> dV;
            for(ll a : dist) dV.push_back(a);
            while(dV.size() < k) dV.push_back(1);
            cout << n * k << '\n';
            F(i, 0, n * k) cout << dV[i % k] << " ";
            cout << '\n';
        }
    }
}