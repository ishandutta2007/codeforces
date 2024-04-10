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
#define N 200010
#define N2 2500010

ll a[N];
vector<pl> lst[N2];
map<ll, vector<ll>> ct;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 1, n + 1) {
        cin >> a[i], ct[a[i]].push_back(i);
        if(ct[a[i]].size() == 4) {
            cout << "YES\n" << ct[a[i]][0] << ' ' << ct[a[i]][1] << ' ' << ct[a[i]][2] << ' ' << ct[a[i]][3] << '\n';
            exit(0);
        }
        if(ct[a[i]].size() > 1) a[i] = -1;
    }
    vector<ll> tw;
    F(i, 0, N2) if(ct[i].size() >= 2) tw.push_back(i);
    if(tw.size() > 1) {
        cout << "YES\n" << ct[tw[0]][0] << ' ' << ct[tw[1]][0] << ' ' << ct[tw[0]][1] << ' ' << ct[tw[1]][1] << '\n';
        exit(0);
    } else if(tw.size() == 1) {
        F(i, 1, n + 1) if(~a[i] && a[i] != tw[0] && ct[2 * tw[0] - a[i]].size()) {
            cout << "YES\n" << ct[tw[0]][0] << ' ' << ct[tw[0]][1] << ' ' << i << ' ' << ct[2 * tw[0] - a[i]][0] << '\n';
            exit(0);
        }
    }
    F(i, 1, n + 1) if(~a[i]) F(j, i + 1, n + 1) if(~a[j]) {
        for(pl p : lst[abs(a[j] - a[i])])
            if(p.K != i && p.V != i && p.K != j && p.V != j) {
                if(a[i] + a[p.V] == a[j] + a[p.K]) cout << "YES\n" << i << ' ' << p.V << ' ' << j << ' ' << p.K << '\n';
                else cout << "YES\n" << i << ' ' << p.K << ' ' << j << ' ' << p.V << '\n';
                exit(0);
            }
        lst[abs(a[j] - a[i])].push_back({i, j});
    }
    cout << "NO\n";
}