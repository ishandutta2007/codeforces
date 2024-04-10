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
#define N 200010

ll ch[N], p[N];
bool used[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 1, n + 1) {
            cin >> p[i];
            if(p[i] - i) ch[p[i]]++;
        }
        vector<vector<ll>> paths;
        F(i, 1, n + 1) if(!ch[i]) {
            vector<ll> pt; ll t = i;
            while(!used[t]) {
                pt.push_back(t);
                used[t] = true;
                t = p[t];
            }
            reverse(A(pt));
            paths.push_back(pt);
        }
        cout << paths.size() << '\n';
        for(auto a : paths) {
            cout << a.size() << '\n';
            for(ll x : a) cout << x << ' ';
            cout << '\n';
        }
        fill_n(used, n + 1, false);
        fill_n(ch, n + 1, 0);
    }
}