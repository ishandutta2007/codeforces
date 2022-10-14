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

ll ct[256];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        memset(ct, 0, sizeof ct);
        GS(t)
        for(char c : t) ct[c]++;
        string rem;
        set<char> st;
        FD(i, t.size() - 1, -1) if(!st.count(t[i])) st.insert(t[i]), rem = rem + t.substr(i, 1);
        reverse(A(rem));
        bool ok = true;
        F(i, 0, rem.size()) {
            if(ct[rem[i]] % (i + 1)) ok = false;
            else ct[rem[i]] /= (i + 1);
        }
        ll id = -1;
        F(i, 0, t.size()) {
            ct[t[i]]--;
            if(ct[t[i]] < 0) { ok = false; break; }
            if(!*max_element(ct + 'a', ct + 'z' + 1)) { id = i; break; }
        }
        if(id == -1) ok = false;
        if(ok) {
            string s = t.substr(0, id + 1);
            string u = "";
            for(char c : rem) {
                u += s;
                string news = "";
                F(i, 0, s.size()) if(s[i] - c) news += s.substr(i, 1);
                s = news;
            }
            if(u == t) cout << t.substr(0, id + 1) << ' ' << rem << '\n';
            else cout << "-1\n";
        } else cout << "-1\n";
    }
}