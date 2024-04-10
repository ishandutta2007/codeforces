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
#define N 200010

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } //inv a mod b
ll pw(ll a, ll p) { return p ? pw(a * a % M, p / 2) * (p & 1 ? a : 1) % M : 1; }

vector<pair<ll, pl>> tree[N];
map<ll, ll> cur, denom;
ll prime[N];
vector<ll> pf[N];

void dfs(ll i, ll p) {
    for(auto a : tree[i]) if(a.K - p) {
        for(ll pp : pf[a.V.K]) cur[pp]--;
        for(ll pp : pf[a.V.V]) { cur[pp]++; denom[pp] = max(denom[pp], cur[pp]); }
        dfs(a.K, i);
        for(ll pp : pf[a.V.K]) cur[pp]++;
        for(ll pp : pf[a.V.V]) cur[pp]--;
    }
}

ll dfs2(ll i, ll p, ll v) {
    ll ans = v;
    for(auto a : tree[i]) if(a.K - p) ans = (ans + dfs2(a.K, i, v * a.V.K % M * inv(a.V.V) % M)) % M;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prime[0] = prime[1] = 1;
    F(i, 2, N) if(!prime[i]) {
        prime[i] = i;
        for (ll j = i * i; j < N; j += i) if(!prime[j]) prime[j] = i;
    }
    F(i, 2, N) {
        ll tmp = i;
        while(tmp > 1) pf[i].push_back(prime[tmp]), tmp /= prime[tmp];
    }
    G(tc) while(tc--) {
        G(n) F(i, 1, n) {
            G(u) G(v) G(x) G(y)
            ll g = __gcd(x, y); x /= g; y /= g;
            tree[u].emplace_back(v, pl{y, x});
            tree[v].emplace_back(u, pl{x, y});
        }
        dfs(1, 1);
        ll st = 1;
        for(pl p : denom) st = (st * pw(p.K, p.V)) % M;
        cout << dfs2(1, 1, st) << '\n';
        F(i, 1, n + 1) tree[i].clear();
        denom.clear(); cur.clear();
    }
}