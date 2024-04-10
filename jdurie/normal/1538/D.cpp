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
#define N 100010

ll prime[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> primes;
    prime[0] = prime[1] = 1;
    F(i, 2, N) if(!prime[i]) {
        prime[i] = i;
        primes.push_back(i);
        for (ll j = i * i; j < N; j += i) if(!prime[j]) prime[j] = i;
    }
    G(tc) while(tc--) {
        G(a) G(b) G(k)
        if(k == 1) cout << ((a % b && b % a) || (a == b) ? "NO\n" : "YES\n");
        else if(k > 60) cout << "NO\n";
        else {
            ll divs = 0;
            for(ll x : primes) {
                while(!(a % x)) a /= x, divs++;
                if(x * x > a) break;
            }
            if(a > 1) divs++;
            for(ll x : primes) {
                while(!(b % x)) b /= x, divs++;
                if(x * x > b) break;
            }
            if(b > 1) divs++;
            cout << (divs >= k ? "YES\n" : "NO\n");
        }
    }
}