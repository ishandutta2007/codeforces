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
typedef vector<vector<ll>> mat;

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
#define MAT(a, n, m) mat a(n, vector<ll>(m, 0));  
#define N 100010
#define X 512

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }

void elim(mat& a) {
    ll n = a.size(), m = a[0].size();
    F(i, 0, n) {
        ll bI = i;
        F(j, i, n) if(abs(a[j][i]) > abs(a[bI][i])) bI = j;
        swap(a[i], a[bI]);
        FD(k, m - 1, i - 1) a[i][k] = (a[i][k] * inv(a[i][i])) % M;
        F(j, 0, n) if(j - i) FD(k, m - 1, i - 1) a[j][k] = (a[j][k] + M - (a[j][i] * a[i][k]) % M) % M;
    }
}

mat inv(mat& a) { //inverts a, returns empty matrix if non-invertible
    ll n = a.size();
    MAT(b, n, 2 * n)
    F(i, 0, n) copy(A(a[i]), b[i].begin()), b[i][n + i] = 1;
    elim(b);
    F(i, 0, n) FD(j, n - 1, -1) b[i][j] = b[i].back(), b[i].pop_back();
    return b;
}

vector<ll> graph[N];
ll grn[N], ct[X];

ll grundy(ll i) {
    set<ll> seen;
    for(ll j : graph[i]) 
        seen.insert(~grn[j] ? grn[j] : grundy(j));
    ll mx = 0;
    while(seen.count(mx)) mx++;
    ct[mx]++;
    return grn[i] = mx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    while(m--) { G(u) G(v) graph[u].push_back(v); }
    fill_n(grn, n + 1, -1);
    F(i, 1, n + 1) if(!~grn[i]) grundy(i);
    MAT(a, X + 2, X + 2)
    F(i, 0, X) F(j, 0, X)
        a[i][j] = (M + (i == j) - ct[i ^ j] * inv(n + 1) % M) % M;
    a[0][X] = (M - inv(n + 1)) % M;
    F(i, 1, X) a[i][X + 1] = a[0][X];
    cout << (M + 1 - inv(a)[0][X]) % M << '\n';
}