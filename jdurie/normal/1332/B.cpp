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

ll primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
map<ll, ll> thisisstupid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(n)
        vector<ll> ans;
        ll mx = 1;
        thisisstupid.clear();
        F(i, 0, n) {
            G(a)
            F(j, 0, 11) if(!(a % primes[j])) {
                if(!thisisstupid.count(primes[j])) thisisstupid[primes[j]] = mx++;
                ans.push_back(thisisstupid[primes[j]]);
                break;
            }
        }
        cout << mx - 1 << '\n';
        for(ll x : ans) cout << x << ' ';
        cout << '\n';
    }
}