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

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
struct rhash {
    const ll seed = __builtin_ia32_rdtsc();
    ll operator()(ll x) const {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31) ^ seed;
    }
};
typedef gp_hash_table<ll, ll, rhash> table_t;

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

vector<ll> vals[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        map<ll, ll> mp; vector<pl> v;
        F(i, 0, n) { G(x) mp[x]++; }
        for(pl p : mp) {
            v.push_back(p);
            vals[p.V].push_back(p.K);
        }
        vector<ll> sz;
        F(i, 1, n + 1) if(vals[i].size()) sz.push_back(i);
        table_t table;
        for(pl p : v) table[p.K * M + p.K] = 1;
        while(m--) { G(x) G(y) table[x * M + y] = table[y * M + x] = 1; }
        ll ans = 0;
        for(pl p : v) for(ll s : sz) {
            ll idx = vals[s].size() - 1;
            while(idx >= 0 && table.find(p.K * M + vals[s][idx]) != table.end()) idx--;
            if(idx >= 0) ans = max(ans, (p.K + vals[s][idx]) * (p.V + s));
        }
        cout << ans << '\n';
        for(ll s : sz) vals[s].clear();
    }
}