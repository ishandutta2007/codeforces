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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 1010

vector<ll> tree[N], v;
ll dep[N], vert, len, dist, n;
map<ll, ll> bullshit;

void ask() {
    cout << "? " << v.size();
    for(ll x : v) cout << ' ' << x;
    cout << endl;
    cin >> vert >> len;
    if(vert == -1) exit(0);
}

void fillDep(ll i, ll p) {
    dep[i] = dep[p] + 1;
    for(ll j : tree[i]) if(j - p) fillDep(j, i);
}

bool askD(ll d) {
    v.clear();
    F(i, 1, n + 1) if(dep[i] == d) v.push_back(i);
    if(v.empty()) return false;
    ask();
    bullshit[d] = vert;
    return len == dist;
}

ll bSearch(ll l, ll r) {
    if(l == r && bullshit.count(l)) return bullshit[l];
    else if(l == r) { askD(l); return vert; }
    ll m = (l + r + 1) / 2;
    return askD(m) ? bSearch(m, r) : bSearch(l, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n;
        bullshit.clear();
        F(i, 0, n - 1) {
            G(u) G(vv)
            tree[u].push_back(vv);
            tree[vv].push_back(u);
        }
        v.clear(); 
        F(i, 1, n + 1) v.push_back(i); 
        ask(); dist = len;
        fill(dep, dep + n + 1, 0); fillDep(1, 1);
        ll v1 = bSearch(dep[vert], *max_element(dep, dep + n + 1));
        fill(dep, dep + n + 1, 0); fillDep(v1, v1);
        askD(dist + 1);
        cout << "! " << v1 << ' ' << vert << endl;
        GS(res)
        if(res[0] != 'C') exit(0);
        F(i, 1, n + 1) tree[i].clear();
    }
}