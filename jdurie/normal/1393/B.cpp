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
#define ADD(x) { m[ct[x]].erase(x); if(m[ct[x]].empty()) m.erase(ct[x]); m[++ct[x]].insert(x); }
#define REM(x) { m[ct[x]].erase(x); if(m[ct[x]].empty()) m.erase(ct[x]); m[--ct[x]].insert(x); }

ll ct[N];
map<ll, set<ll>> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) { G(x) ADD(x) }
    G(q) while(q--) {
        GS(c) G(x)
        if(c[0] == '+') ADD(x)
        else REM(x)
        string ans = "NO\n";
        ll ct4 = 0, ct2 = 0;
        auto it = m.rbegin();
        while(it != m.rend()) {
            if(it->K >= 8) { ans = "YES\n"; break; }
            else if(it->K >= 6) ct4 += it->V.size(), ct2 += it->V.size();
            else if(it->K >= 4) ct4 += it->V.size();
            else if(it->K >= 2) ct2 += it->V.size();
            else break;
            if(ct4 >= 2 || (ct4 && ct2 >= 2)) { ans = "YES\n"; break; }
            it++;
        }
        cout << ans;
    }
}