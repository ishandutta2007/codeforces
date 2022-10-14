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
#define M 998244353
#define N 100010

vector<ll> tree[N];
ll n, ans[N], ct[N];

ll dfs(ll i, ll p, ll k) {
    ll z = 0;
    for(ll j : tree[i]) if(j - p) z += dfs(j, i, k);
    if(i - 1) { if(z % k) ct[i]++; else ct[p]++; }
    return z + 1; 
}

bool works(ll k) {
    fill_n(ct, n + 1, 0);
    dfs(1, 1, k);
    F(i, 1, n + 1) if(ct[i] % k) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n; F(i, 1, n) {
            G(u) G(v)
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        ans[1] = 1; F(i, 1, n) ans[1] = ans[1] * 2 % M;
        F(i, 2, n) if(!((n - 1) % i) && works(i)) ans[i] = 1;
        FD(i, n, 0) for(ll j = 2 * i; j <= n; j += i) ans[i] -= ans[j];
        F(i, 1, n + 1) cout << ans[i] << ' ';
        cout << '\n'; 
        fill_n(ans, n + 1, 0);
        F(i, 1, n + 1) tree[i].clear();
    }
}