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

typedef int ll;
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
#define N 300010
#define Z 1010

ll a[N];
ll ct[1000010];
ll prime[Z];
vector<ll> p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F(i, 2, Z) if(!prime[i]) {
        prime[i] = i;
        p.push_back(i);
        for (ll j = i * i; j < Z; j += i) if(!prime[j]) prime[j] = i;
    }
    G(tc) while(tc--) {
        G(n) vector<ll> v;
        F(i, 0, n) {
            cin >> a[i];
            for(ll z : p) {
                if(z * z > a[i]) break;
                while(!(a[i] % (z * z))) a[i] /= z * z;
            }
            ct[a[i]]++;
            v.push_back(a[i]);
        }
        //cout << ct << '\n';
        ll best0 = 0, bestO = 0, sumE = 0;
        for(ll x : v) {
            best0 = max(best0, ct[x]);
            if(ct[x] & 1 && x - 1) bestO = max(bestO, ct[x]);
            else sumE += ct[x];
            ct[x] = 0;
        }
        G(q) while(q--) {
            long long int w; cin >> w;
            if(!w) cout << best0 << '\n';
            else cout << max(bestO, sumE) << '\n';
        }
    }    
}