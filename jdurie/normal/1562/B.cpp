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

bool pr[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> comp = {1};
    F(i, 2, N) if(!pr[i]) {
        for(ll j = i * i; j < N; j += i) pr[j] = true;
    } else comp.push_back(i);
    G(tc) while(tc--) {
        G(n) GS(s)
        for(ll c : comp) {
            string t = to_string(c);
            ll i1 = 0, i2 = 0;
            bool ok = true;
            while(i2 < t.size()) {
                while(i1 < s.size() && s[i1] - t[i2]) i1++;
                if(i1 == s.size()) { ok = false; break; }
                else i1++, i2++;
            }
            if(ok) { cout << t.size() << '\n' << t << '\n'; break; }
        }
    }
}