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
#define N 3010
#define L 13

ll dep[N], par[N][L], d[N][N], ans[N][N], mxd[N];
vector<ll> treee[N];

void dfs(ll i, ll p) {
    dep[i] = dep[p] + 1;
    par[i][0] = p;
    F(l, 1, L) par[i][l] = par[par[i][l - 1]][l - 1];
    for(ll j : treee[i]) if(j - p) dfs(j, i);
}

ll lca(ll a, ll b) {
    if(dep[a] < dep[b]) swap(a, b);
    FD(l, L - 1, -1) if((dep[a] - dep[b]) >> l) a = par[a][l];
    if(a == b) return a;
    FD(l, L - 1, -1) if(par[a][l] - par[b][l]) a = par[a][l], b = par[b][l];
    return par[a][0];
}

ll dist(ll a, ll b) { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        F(i, 1, n) {
            G(u) G(v)
            treee[u].push_back(v);
            treee[v].push_back(u);
        }
        dfs(1, 1);
        F(i, 1, n + 1) F(j, 1, n + 1) d[i][j] = dist(i, j);
        F(v, 1, n + 1) {
            fill_n(mxd, n + 1, 0);
            F(i, 1, n + 1) mxd[d[i][v]]++;
            ll y = n;
            vector<pl> vv;
            F(i, 1, n + 1) vv.emplace_back(d[i][1] - d[i][v], i);
            sort(vv.rbegin(), vv.rend());
            ll w = 0;
            F(x, 1, n + 1) {
                while(vv.size() && vv.back().K < x) {
                    ll i = vv.back().V;
                    mxd[d[i][v]]--;
                    w = max(w, d[i][1]);
                    vv.pop_back();
                }
                while(y >= 0 && !mxd[y]) y--;
                ans[x][v] = ~y ? max(y + x, w) : w;
            }
        }
        F(x, 1, n + 1) cout << *min_element(ans[x] + 1, ans[x] + n + 1) << ' ';
        cout << '\n';
        F(i, 1, n + 1) treee[i].clear();
    }
}