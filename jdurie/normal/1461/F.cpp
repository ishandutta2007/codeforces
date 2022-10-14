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
#define N 100010
#define EEEE 200010

ll a[N];
char op[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) cin >> a[i]; GS(s)
    if(s.size() == 1) fill_n(op, n, s[0]);
    else if(s == "+-" || s == "-+") fill_n(op, n, '+');
    else if(s == "-*" || s == "*-") F(i, 0, n) op[i] = a[i] ? '*' : '-';
    else {
        fill_n(op, n, '+');
        vector<ll> bstk, ostk;
        vector<ll> ids;
        ll curo = 0;
        F(i, 0, n + 1) {
            if(a[i] == 1 && bstk.size()) curo++; 
            if(a[i] > 1) {
                if(bstk.size()) ostk.push_back(curo);
                bstk.push_back(a[i]);
                ids.push_back(i);
                curo = 0;
            }
            if(!a[i]) {
                ll prod = 1, osm = 0;
                for(ll b : bstk) prod = min(prod * b, EEEE);
                for(ll o : ostk) osm += o;
                if(prod == EEEE || prod >= 2 * osm + 10) for(ll j = ids[0] + 1; j <= ids.back(); ++j) op[j] = '*'; 
                else if(bstk.size()) {
                    ll bmask = 0, maxv = -1, osz = ostk.size();
                    F(mask, 0, (1 << osz)) {
                        ll curP = bstk[0], val = 0;
                        F(j, 0, osz)
                            if((mask >> j) & 1) curP *= bstk[j + 1];
                            else { val += curP + ostk[j]; curP = bstk[j + 1]; }
                        val += curP;
                        if(val > maxv) bmask = mask, maxv = val;
                    }
                    F(j, 0, osz) if((bmask >> j) & 1) F(k, ids[j] + 1, ids[j + 1] + 1) op[k] = '*';
                }
                ostk.clear();
                bstk.clear();
                ids.clear();
                curo = 0;
            }
            
        }
    }
    cout << a[0];
    F(i, 1, n) cout << op[i] << a[i];
    cout << '\n';
}