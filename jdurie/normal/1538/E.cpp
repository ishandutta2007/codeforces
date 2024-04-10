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
//#define N 100010

map<string, ll> haha;
map<string, string> st, en;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) ll ans = 0;
        while(n--) {
            GS(s) GS(op)
            if(op == ":=") {
                GS(lit)
                if(lit == "haha" || (lit.size() == 5 && (lit.substr(0, 4) == "haha" || lit.substr(1, 4) == "haha"))) haha[s] = 1;
                else haha[s] = 0;
                st[s] = lit.substr(0, min(3ll, (ll)lit.size()));
                en[s] = lit.substr(max(0ll, lit.size() - 3ll), min(3ll, (ll)lit.size()));
            } else {
                GS(v1) GS(plus) GS(v2)
                ll tmp = haha[v1] + haha[v2];
                if(en[v1].size() && st[v2].size() >= 3 && en[v1].back() == 'h' && st[v2].substr(0, 3) == "aha") tmp++;
                if(en[v1].size() >= 2 && st[v2].size() >= 2 && en[v1].substr(en[v1].size() - 2, 2) == "ha" && st[v2].substr(0, 2) == "ha") tmp++;
                if(en[v1].size() >= 3 && st[v2].size() && en[v1].substr(en[v1].size() - 3, 3) == "hah" && st[v2][0] == 'a') tmp++;
                haha[s] = tmp;
                string t1 = st[v1] + st[v2];
                string t2 = en[v1] + en[v2];
                st[s] = t1.substr(0, min(3ll, (ll)t1.size()));
                en[s] = t2.substr(max(0ll, t2.size() - 3ll), min(3ll, (ll)t2.size()));
            }
            ans = haha[s];
        }
        cout << ans << '\n';
    }    
}