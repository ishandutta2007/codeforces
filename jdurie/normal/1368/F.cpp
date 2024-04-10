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
#define N 1010

ll n, on[N];

ll fuck(ll i) { return (n + i - 1) / i + i - 1; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll sq = 1; 
    F(i, 1, n) if(fuck(i) < fuck(sq)) sq = i;
    while(1) {
        vector<ll> ord;
        F(i, 1, sq) F(bl, 0, n) if(bl * sq + i < n && !on[bl * sq + i]) ord.push_back(bl * sq + i);
        ll off = 0;
        F(i, 1, n + 1) if(!on[i]) off++;
        if(off <= fuck(sq)) EX(0)
        cout << sq << ' ';
        F(i, 0, sq) {
            cout << ord[i] << ' ';
            on[ord[i]] = 1;
        }
        cout << endl;
        G(res)
        if(res == -1) exit(0);
        F(i, 0, sq) {
            on[res] = 0;
            res++; if(res > n) res = 1;
        }
    }       
}