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
#define N 300010

bool banned[N], done[N];
ll nxt[N], sz[N], prv[N], maxI[N], tot = 0, ct[N], dp[N], num[N];
vector<ll> a[N], graph[N];
vector<pl> v;

void dfs(ll i) {
    banned[i] = true;
    for(ll j : graph[i]) if(!banned[j]) dfs(j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m) G(k)
    F(i, 0, n) {
        G(x) set<ll> s;
        while(x--) {
            G(z) num[z]++;
            if(s.count(z)) banned[z] = true;
            if(a[i].size()) {
                if(nxt[a[i].back()] && nxt[a[i].back()] - z) banned[a[i].back()] = true;
                else nxt[a[i].back()] = z;
                if(prv[z] && prv[z] - a[i].back()) banned[z] = true;
                else prv[z] = a[i].back();
            }
            maxI[z] = max(maxI[z], (ll)a[i].size());
            a[i].push_back(z);
        }
        F(j, 1, a[i].size()) {
            graph[a[i][j]].push_back(a[i][j - 1]);
            graph[a[i][j - 1]].push_back(a[i][j]);
        }
    }
    F(i, 1, k + 1) if(banned[i]) dfs(i);
    F(i, 1, k + 1) if(!banned[i] && !maxI[i]) {
        ll c = 0, cur = i;
        set<ll> seen;
        bool flag = false;
        while(cur) {
            if(seen.count(cur)) { flag = true; break; }
            seen.insert(cur);
            cur = nxt[cur], c++;
        }
        if(flag) { dfs(i); continue; }
        tot += c;
        ct[c]++;
    }
    F(i, 1, N) if(ct[i]) v.push_back({i, ct[i]});
    dp[0] = 1;
    F(i, 1, m + 1) {
        for(pl p : v)
            if(p.K <= i) dp[i] = (dp[i] + p.V * dp[i - p.K]) % M;
            else break;
    }
    cout << dp[m] << '\n';
}