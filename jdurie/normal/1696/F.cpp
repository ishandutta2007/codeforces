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
#define N 110

vector<ll> eq[N][N], graph[N];
ll d[N][N];

ll n, seen;
bool ok, used[N];
ll par[N];
string str[N][N];

void dfs(ll i, ll p) {
    par[i] = p;
    seen++;
    used[i] = true;
    for(ll k : eq[p][i]) 
        if(used[k]) { ok = false; return; }
        else dfs(k, i);
}

void dfs2(ll i, ll p, ll r) {
    d[i][r] = d[r][i] = d[p][r] + 1;
    for(ll j : graph[i]) if(j - p) dfs2(j, i, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n;
        F(i, 1, n + 1) F(j, i + 1, n + 1) {
            GS(s) str[i][j] = s;
            F(k, 1, n + 1) if(s[k - 1] == '1') eq[i][k].push_back(j), eq[j][k].push_back(i);
        }
        bool done = false;
        F(i, 2, n + 1) {
            ok = true;
            fill_n(used, n + 1, false);
            seen = 0;
            dfs(1, i);
            dfs(i, 1);
            if(ok && seen == n) {
                vector<pl> edges;
                F(j, 1, n + 1) graph[j].clear();
                F(j, 2, n + 1) {
                    edges.emplace_back(j, par[j]);
                    graph[j].push_back(par[j]);
                    graph[par[j]].push_back(j);
                }
                F(j, 1, n + 1) {
                    d[j][j] = -1; dfs2(j, j, j);
                }
                bool good = true;
                F(ii, 1, n + 1) F(j, ii + 1, n + 1) F(k, 1, n + 1)
                    if((str[ii][j][k - 1] == '1') != (d[ii][k] == d[j][k])) good = false;
                if(good) {
                    cout << "Yes\n";
                    for(pl p : edges) cout << p.K << ' ' << p.V << '\n';
                    done = true;
                    break;
                }
            }
        }
        if(!done) cout << "No\n";
        F(i, 1, n + 1) F(j, 1, n + 1) eq[i][j].clear();
    }
}