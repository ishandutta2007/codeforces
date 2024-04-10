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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010
#define ASK(v) cout << "? " << v.size() << ' '; for(ll k : v) cout << k << ' '; cout << endl; cin >> x; if(x == -1) exit(0);

set<ll> sets[N];
ll x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k)
        F(i, 0, k) {
            sets[i].clear();
            G(c) while(c--) { G(h) sets[i].insert(h); }
        }
        vector<ll> v;
        F(i, 1, n + 1) v.push_back(i);
        ASK(v)
        ll mx = x, idx = 1;
        FD(p2, 9, -1) {
            v.clear();
            for(ll i = idx; i < min(n + 1, idx + (1 << p2)); i++)
                v.push_back(i);
            ASK(v)
            if(x != mx) idx += (1 << p2);
        }
        ll sIdx = -1, qqq = 0;
        F(i, 0, k) if(sets[i].count(idx)) sIdx = i;
        if(sIdx != -1) {
            v.clear();
            F(i, 1, n + 1) if(!sets[sIdx].count(i)) v.push_back(i);
            ASK(v)
            qqq = x;
        }
        cout << "! ";
        F(i, 0, k) cout << (i == sIdx ? qqq : mx) << ' ';
        cout << endl;
        GS(res)
        if(res == "Incorrect") exit(0);
    }
}