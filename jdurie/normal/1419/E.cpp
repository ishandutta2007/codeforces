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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        set<ll> divs = {n};
        for(ll i = 2; i * i <= n; i++) if(!(n % i))
            divs.insert(i), divs.insert(n / i);
        vector<ll> primes;
        for(ll d : divs) {
            bool pr = true;
            for(ll i = 2; i * i <= d; i++) if(!(d % i)) pr = false;
            if(pr) primes.push_back(d);
        }
        for(ll p : primes) divs.erase(p);
        if(primes.size() == 2) {
            ll pr1 = primes[0], pr2 = primes[1];
            if(divs.size() == 1)
                cout << pr1 << ' ' << pr1 * pr2 << ' ' << pr2 << "\n1\n";
            else {
                divs.erase(pr1 * pr2);
                ll k = divs.count(pr1 * pr1 * pr2) ? pr1 * pr1 * pr2 : pr1 * pr2 * pr2;
                divs.erase(k);
                cout << pr1 << ' ';
                for(ll d : divs) if(!(d % pr1)) cout << d << ' ';
                cout << pr1 * pr2 << ' ' << pr2 << ' ';
                for(ll d : divs) if(d % pr1) cout << d << ' ';
                cout << k << "\n0\n";   
            }
        } else {
            vector<ll> mults;
            F(i, 0, primes.size() - 1) mults.push_back(primes[i] * primes[i + 1]);
            mults.push_back(primes[0] * primes.back());
            for(ll m : mults) divs.erase(m);
            map<ll, vector<ll>> mp;
            for(ll d : divs) {
                for(ll p : primes)
                    if(!(d % p)) { mp[p].push_back(d); break; }
            }
            F(i, 0, primes.size()) {
                cout << primes[i] << ' ';
                for(ll x : mp[primes[i]]) cout << x << ' ';
                cout << mults[i] << ' ';
            }
            cout << "\n0\n";
        }
    }
}