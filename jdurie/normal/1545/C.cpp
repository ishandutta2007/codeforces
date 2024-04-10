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
#define N 510

ll a[2 * N][N];
ll ct[N][N], uct;
bool used[N][N], uR[2 * N];
vector<ll> graph[2 * N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, 2 * n) F(j, 0, n) cin >> a[i][j], ct[j][a[i][j]]++;
        F(i, 0, 2 * n) F(j, 0, i) F(k, 0, n)
            if(a[i][k] == a[j][k]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
                break;
            }
        ll ans = 1;
        vector<ll> v;
        uct = 0;
        while(uct < n) {
            bool b = false;
            F(i, 0, n) F(j, 1, n + 1) if(!used[i][j] && ct[i][j] == 1) {
                F(k, 0, 2 * n) if(!uR[k] && a[k][i] == j) {
                    uR[k] = true;
                    v.push_back(k + 1);
                    b = true;
                    uct++;
                    F(l, 0, n) used[l][a[k][l]] = true;
                    for(ll x : graph[k]) if(!uR[x]) {
                        uR[x] = true;
                        F(l, 0, n) ct[l][a[x][l]]--;
                    }
                }
            }
            if(!b) {
                    F(i, 0, 2 * n) if(!uR[i]) {
                        uR[i] = true;
                        v.push_back(i + 1);
                        uct++;
                        F(l, 0, n) used[l][a[i][l]] = true;
                        for(ll x : graph[i]) if(!uR[x]) {
                            uR[x] = true;
                            F(l, 0, n) ct[l][a[x][l]]--;
                        }
                        ans = ans * 2 % M;
                        break;
                    }
            }
        }
        cout << ans << '\n';
        for(ll x : v) cout << x << ' ';
        cout << '\n';
        F(i, 0, n) F(j, 1, n + 1) ct[i][j] = 0;
        F(i, 0, n) F(j, 1, n + 1) used[i][j] = false;
        fill_n(uR, 2 * n, false);
        F(i, 0, 2 * n) graph[i].clear();
    }
}