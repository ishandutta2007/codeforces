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
#define N 100010
#define X 200

ll a[N];
vector<pair<pl, ll>> tasks[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 1, n + 1) cin >> a[i];
        F(i, 0, m) {
            G(e) G(t) G(p)
            tasks[e].emplace_back(pl{t, p}, i + 1);
        }
        vector<ll> ans; bool ok = true; ll tot = 0;
        F(i, 1, n + 1) {
            vector<vector<ll>> dp(tasks[i].size() + 1, vector<ll>(X));
            vector<vector<int>> tak(tasks[i].size() + 1, vector<int>(X));
            F(iff, 0, tasks[i].size() + 1) fill(A(dp[iff]), LLONG_MAX / 100);
            dp[0][0] = 0;
            F(ii, 1, tasks[i].size() + 1) {
                auto aa = tasks[i][ii - 1];
                F(j, 0, X) dp[ii][j] = dp[ii - 1][j], tak[ii][j] = tak[ii - 1][j];
                F(j, aa.K.V, X) {
                    ll v = dp[ii - 1][j - aa.K.V] + aa.K.K;
                    if(v < dp[ii][j]) dp[ii][j] = v, tak[ii][j] = ii - 1;
                }
            }
            ll bst = 100;
            F(j, 100, X) if(dp[tasks[i].size()][j] < dp[tasks[i].size()][bst]) bst = j;
            tot += dp[tasks[i].size()][bst];
            ll curind = tasks[i].size();
            //cout << i << ' ' << dp[tasks[i].size()][bst] << '\n';
            if(tot > a[i]) { ok = false; break; }
            else while(bst) {
                auto aa = tasks[i][tak[curind][bst]];
                ans.push_back(aa.V);
                curind = tak[curind][bst];
                bst -= aa.K.V;
            }
        }
        if(!ok) cout << "-1\n";
        else {
            cout << ans.size() << '\n';
            for(ll x : ans) cout << x << ' ';
            cout << '\n';
        }
        F(i, 1, n + 1) tasks[i].clear();
    }
}