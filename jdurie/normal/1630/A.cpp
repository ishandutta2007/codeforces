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

void dotc() {
    G(n) G(k) ll rem = 0;
        if(k == n - 1 && n == 4) { cout << "-1\n"; return; }
        else if(k == n - 1) rem = 2, k--;
        set<ll> used;
        if(k) cout << k << ' ' << n - 1 << "\n0 " << ((n - 1) ^ k) << '\n';
        else cout << "0 " << n - 1 << '\n';
        used.insert(k);
        used.insert(n - 1);
        used.insert(0);
        used.insert((n - 1) ^ k);
        if(rem) {
            for(ll i = 1; i < n; i += 2) {
                if(!used.count(i) && !used.count(i - 1)) {
                    cout << i << ' ' << (i ^ (n - 1)) + 1 << '\n';
                    cout << (i ^ (n - 1)) << ' ' << ((i - 1)) << '\n';
                    used.insert(i); used.insert(i - 1);
                    used.insert((n -1) ^ i); used.insert(( i^ (n-1)) + 1);
                    break;
                }
            }
        }
        F(i, 0, n) if(!used.count(i)) {
            cout << i << ' ' << ((n - 1) ^ i)<< '\n';
            used.insert((n - 1) ^ i);
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) dotc();
}