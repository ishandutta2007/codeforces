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
//#define N 200010

struct rhash {
    const ll seed = __builtin_ia32_rdtsc();
    ll operator()(ll x) const {
        return x ^ seed; /*
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31) ^ seed;*/
    }
};
typedef gp_hash_table<ll, ll, rhash> table_t;

ll k;
table_t prefs[40];
vector<ll> ans;
table_t ind;

void solve(vector<ll>& v, ll b) {
    if(v.empty()) return;
    if(k >> b) {
        F(j, 0, 30) prefs[j].clear();
        for(ll x : v) {
            ll cr = 0;
            FD(j, 29, -1) {
                cr = cr * 2 + ((x >> j) & 1);
                prefs[j][cr] = 1;
            }
        }
        pl mx = {0, 0};
        for(ll x : v) {
            ll q = 0;
            FD(j, 29, -1) {
                q = 2 * q + !((x >> j) & 1);
                if(prefs[j].find(q) == prefs[j].end()) q ^= 1;
            }
            mx = max(mx, {x ^ q, x});
        }
        ans.push_back(ind[mx.V]);
        if(mx.K >= k) ans.push_back(ind[mx.K ^ mx.V]);
        return;
    }
    vector<ll> z, o;
    for(ll x : v) if((x >> b) & 1) o.push_back(x); else z.push_back(x);
    solve(z, b - 1); solve(o, b - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) cin >> k;
    if(!k) {
        cout << n << '\n';
        F(i, 1, n + 1) cout << i << ' ';
        exit(0);
    }
    vector<ll> v;
    F(i, 1, n + 1) { G(x) v.push_back(x); ind[x] = i; }
    solve(v, 30);
    if(ans.size() < 2) EX(-1)
    cout << ans.size() << '\n';
    for(ll x : ans) cout << x << ' ';
}