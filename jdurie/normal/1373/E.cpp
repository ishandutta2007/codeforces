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
#define N 1000010

ll sD[N];

void bruteforce(ll n) {
    if(n > 9) bruteforce(n - 9);
    cout << min(n, 9ll);
}

ll sumDig(ll n) {
    if(!n) return 0;
    return n % 10 + sumDig(n / 10);
}

bool works(ll i, ll n, ll k) {
    ll sm = 0;
    F(j, 0, k + 1) {
        sm += sD[i + j];
        if(sm > n) return false;
    }
    return sm == n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F(i, 0, N) sD[i] = sumDig(i);
    G(tc) while(tc--) {
        G(n) G(k)
        if(!k) { bruteforce(n); cout << '\n'; }
        else if(n < 50 || k > 1) {
            bool ok = false;
            F(i, 0, N - 20) if(works(i, n, k)) { ok = true; cout << i << '\n'; break; }
            if(!ok) cout << "-1\n";
        } else if(n & 1) { bruteforce((n - 35) / 2); cout << "98\n"; }
        else { bruteforce((n - 26) / 2); cout << "89\n"; }
    }
}