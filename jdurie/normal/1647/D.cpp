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
#define N 5010

ll isPow(ll x) {
    for(ll i = 2; i * i <= x; ++i)
        if(!(x % i)) {
            while(!(x % i)) x /= i;
            return x == 1 ? i : 0;
        }
    return x;
}

bool isPrime(ll x) {
    for(ll i = 2; i * i <= x; ++i)
        if(!(x % i)) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(x) G(d)
        if(x % (d * d)) cout << "NO\n";
        else {
            bool b = isPrime(d); ll p = isPow(d);
            if(b) {
                while(!(x % d)) x /= d;
                cout << (isPrime(x) ? "NO\n" : "YES\n");
            } else if(p) {
                ll ct = 0, z = 0;
                while(!(d % p)) d /= p, z++;
                while(!(x % p)) x /= p, ct++;
                if(!isPrime(x) || (ct % z && x > 1) || (ct % z > 1)) cout << "YES\n";
                else {
                    ll num = ct / z - 1;
                    if((ct + num - 1) / num < 2 * z) cout << "YES\n";
                    else cout << "NO\n";
                }
            } else {
                x /= (d * d);
                cout << (isPrime(x) ? "NO\n" : "YES\n");
            }
        }
    }
}