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

map<ll, vector<pl>> mx, my;

ll p[N], t[N];
ll dsu(ll i) { return ~p[i] ? p[i] = dsu(p[i]) : i; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k)
        fill_n(p, n, -1); mx.clear(); my.clear();
        F(i, 0, n) {
            G(x) G(y) cin >> t[i];
            mx[x].emplace_back(y, i);
            my[y].emplace_back(x, i);
        }
        for(auto& a : mx) {
            sort(A(a.V));
            F(i, 1, a.V.size()) if(a.V[i].K - a.V[i - 1].K <= k) {
                ll q = dsu(a.V[i].V), r = dsu(a.V[i - 1].V);
                if(q - r) {
                    t[r] = min(t[q], t[r]);
                    p[q] = r;
                }
            }
        }
        for(auto& a : my) {
            sort(A(a.V));
            F(i, 1, a.V.size()) if(a.V[i].K - a.V[i - 1].K <= k) {
                ll q = dsu(a.V[i].V), r = dsu(a.V[i - 1].V);
                if(q - r) {
                    t[r] = min(t[q], t[r]);
                    p[q] = r;
                }
            }
        }
        vector<ll> tms;
        F(i, 0, n) if(!~p[i]) tms.push_back(t[i]);
        sort(A(tms)); reverse(A(tms));
        tms.push_back(0);
        F(i, 0, tms.size() - 1) if(i >= tms[i + 1]) { cout << i << '\n'; break; }
    }
}