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
#define N 1000010

vector<ll> a[N], b[N];

bool prime[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(prime, N, true);
    prime[1] = false;
    F(i, 2, N) if(prime[i]) for(ll j = i * i; j < N; j += i) prime[j] = false;
    G(tc) while(tc--) {
        G(n) G(e)
        F(i, 0, n) { G(x) a[i % e].push_back(x); }
        ll ans = 0;
        F(q, 0, e) {
            ll ones = 0;
            for(ll x : a[q]) {
                b[q].push_back(prime[x] ? ones + 1 : 1);
                if(x > 1) ones = 0; else ones++;
            }
            reverse(A(a[q])); reverse(A(b[q]));
            ones = 0;
            F(i, 0, a[q].size()) {
                ll x = a[q][i];
                if(prime[x]) ans += b[q][i] * (ones + 1) - 1;
                if(x > 1) ones = 0; else ones++;
            }
        }
        cout << ans << '\n';
        F(i, 0, e) a[i].clear(), b[i].clear();
    }
}