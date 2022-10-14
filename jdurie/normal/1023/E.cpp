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
#define N 510
#define ASK(r1, c1, r2, c2) cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl; cin >> res;

char dir[2 * N];
string res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n)
    ll cR = 1, cC = 1;
    F(i, 0, n - 1) {
        ASK(cR + 1, cC, n, n)
        if(res == "YES") {
            dir[i] = 'D';
            cR++;
        } else {
            dir[i] = 'R';
            cC++;
        }
    }
    ll tR = cR;
    ll cR2 = n, cC2 = n;
    F(i, 0, n - 2) {
        if(dir[n - 2 - i] == 'D') cR--; else cC--;
        ASK(cR, cC, cR2, cC2 - 1);
        if(res == "YES") {
            dir[2 * n - i - 3] = 'R';
            cC2--;
        } else {
            dir[2 * n - i - 3] = 'D';
            cR2--;
        }
    }
    dir[n - 1] = tR == cR2 ? 'R' : 'D';
    cout << "! ";
    F(i, 0, 2 * n - 2) cout << dir[i];
    cout << endl;
}