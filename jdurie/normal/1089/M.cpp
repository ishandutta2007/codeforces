#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 10

bool adj[N][N], used[N];
set<ll> crev[N];
ll ctoo[N], otoc[N], comp[N];
string grid[2 * N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, n) F(j, 0, n) { cin >> adj[i][j]; if(i == j) adj[i][j] = true; }
    F(k, 0, n) F(i, 0, n) F(j, 0, n) if(adj[i][k] && adj[k][j]) adj[i][j] = true;
    ll c = 0;
    F(i, 0, n) {
        F(j, 0, i) if(adj[i][j] && adj[j][i]) comp[i] = comp[j];
        if(!comp[i]) comp[i] = ++c;
    }
    F(i, 0, n) F(j, 0, n) if(adj[i][j] && comp[i] - comp[j]) crev[comp[j]].insert(comp[i]);
    F(i, 0, c) {
        ll x = 1;
        while(1) {
            bool ok = !ctoo[x];
            for(ll y : crev[x]) if(!ctoo[y]) ok = false;
            if(ok) break;
            x++;
        }
        ctoo[x] = i + 1;
        otoc[i + 1] = x;
    }
    cout << 2 * c + n + 1 << ' ' << 3 * c << ' ' << 2 * c + 1 << '\n';
    F(i, 1, c + 1) {
        vector<ll> v;
        F(j, 0, n) if(comp[j] == otoc[i]) v.push_back(j);
        F(j, 0, 3 * c) {
            if(!j) {
                ll ct = 0;
                F(k, 0, n) if(comp[k] == otoc[i]) cout << k + 1, ct++;
                F(k, 0, n - ct) cout << '.';
            } else F(k, 0, n) cout << '.';
            ll jp = j / 3 + 1;
            if(jp == i || crev[otoc[i]].count(otoc[jp])) cout << '.'; else cout << '#';
            F(k, 1, 2 * c + 1) if(crev[otoc[i]].count(otoc[jp]) && k == 2 * i && j % 3 == 2) cout << '#'; else cout << '.';
            cout << '\n';
        }
        cout << '\n';
        F(j, 1, c + 1) {
            F(k, 0, n + 1) cout << '#';
            F(k, 0, 2 * c) cout << '.';
            cout << '\n';
            F(k, 0, n + 1) cout << '#';
            F(k, 1, i) cout << "..";
            if(crev[otoc[i]].count(otoc[j])) cout << "#."; else cout << "..";
            F(k, i + 1, c + 1) cout << "..";
            cout << '\n';
            F(k, 0, 2 * c + n + 1) cout << '#';
            cout << '\n';
        }
        cout << '\n';
    }
    F(i, 0, 3 * c) F(j, 0, 2 * c + n + 2) cout << ".\n"[j == 2 * c + n + 1];
}