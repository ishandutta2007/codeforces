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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

vector<pl> fact;

ll pw(ll a, ll p) { return p ? a * pw(a, p - 1) : 1; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        fact.clear();
        G(n)
        ll origN = n;
        for(ll i = 2; i * i <= n; i++) if(!(n % i)) {
            ll ct = 0;
            while(!(n % i)) { ct++; n /= i; }
            fact.emplace_back(i, ct);
        }
        if(n > 1) fact.emplace_back(n, 1);
        if(fact.size() >= 3) cout << "YES\n" << fact[0].K << ' ' << fact[1].K << ' ' << origN / fact[0].K / fact[1].K << '\n';
        else if(fact.size() == 2) {
            if(fact[0].V >= 3) cout << "YES\n" << fact[0].K << ' ' << pw(fact[0].K, fact[0].V - 1) << ' ' << pw(fact[1].K, fact[1].V) << '\n';
            else if(fact[1].V >= 3) cout << "YES\n" << fact[1].K << ' ' << pw(fact[1].K, fact[1].V - 1) << ' ' << pw(fact[0].K, fact[0].V) << '\n';
            else if(fact[0].V == 2 && fact[1].V == 2) cout << "YES\n" << fact[0].K << ' ' << fact[1].K << ' ' << fact[0].K * fact[1].K << '\n';
            else cout << "NO\n";
        } else if(fact[0].V >= 6) cout << "YES\n" << fact[0].K << ' ' << fact[0].K * fact[0].K << ' ' << pw(fact[0].K, fact[0].V - 3) << '\n';
        else cout << "NO\n";
    }
}