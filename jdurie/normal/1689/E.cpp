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
#define N 2050
#define L 30

vector<ll> graph[N];
bool used[N], printed;
ll n, zeroes, a[N];

void dfs(ll i) {
    used[i] = true;
    for(ll j : graph[i]) if(!used[j]) dfs(j);
}

bool works() {
    F(i, 0, n) F(j, 0, L) if((a[i] >> j) & 1) graph[j].push_back(i + L), graph[i + L].push_back(j);
    dfs(L); bool ans = true;
    F(i, 0, n) if(!used[i + L]) ans = false;
    F(i, 0, n + L) graph[i].clear(), used[i] = false;
    return ans;
}

void finish(ll x) {
    if(!printed) {
        cout << x + zeroes << '\n';
        F(i, 0, n) cout << a[i] << ' ';
        cout << '\n';
        printed = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n; zeroes = 0; F(i, 0, n) {
            cin >> a[i];
            if(!a[i]) a[i]++, zeroes++;
        }
        printed = false;
        if(works()) finish(0);
        else {
            F(i, 0, n) {
                a[i]--;
                if(works()) finish(1);
                a[i] += 2;
                if(works()) finish(1);
                a[i]--;
            }
            vector<pl> v;
            F(i, 0, n) v.emplace_back(i, a[i]);
            sort(A(v), [](pl aa, pl b) { return __builtin_ctzll(aa.V) > __builtin_ctzll(b.V); });
            a[v[0].K]--; a[v[1].K]++;
            finish(2);
        }
    }
}