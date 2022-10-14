#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
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
#define N 300010
#define L 30

struct rhash {
    const ll seed = (int)__builtin_ia32_rdtsc();
    ll operator()(ll x) const {
        return x ^ seed;
    }
};
typedef gp_hash_table<ll, ll, rhash> table_t;

table_t mp[L][2][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) ll len = 1; F(i, 0, n) {
            G(x) ll ans = 1;
            F(j, 0, L) {
                ll ba = (x >> j) & 1, bb = (i >> j) & 1, xr = ((x ^ i) >> (j + 1));
                if(mp[j][bb][!ba].find(xr) != mp[j][bb][!ba].end()) ans = max(ans, mp[j][bb][!ba][xr] + 1);
            }
            F(j, 0, L) {
                ll ba = (x >> j) & 1, bb = (i >> j) & 1, xr = ((x ^ i) >> (j + 1));
                mp[j][ba][bb][xr] = max(ans, mp[j][ba][bb][xr]);
            }
            len = max(len, ans);
        }
        cout << len << '\n';
        F(i, 0, L) F(j, 0, 2) F(k, 0, 2) mp[i][j][k].clear();
    }
}