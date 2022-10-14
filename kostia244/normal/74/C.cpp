//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,sse,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 4e6 + 666, mlg = 18, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int p[maxn], r[maxn], sz;
int par(int i) {
	if (i == p[i])
		return i;
	return p[i] = par(p[i]);
}
void unite(int i, int j) {
	i = par(i), j = par(j);
	if (i == j)
		return;
	if (r[i] < r[j])
		swap(i, j);
	--sz;
	p[j] = i;
	r[i] += r[j];
}
int n, m;
inline int diag(int x, int y) {
	return x+y-2;
}
inline int adiag(int x, int y) {
	return (n+m-1) + m + x - y - 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	sz = 2 * (n + m - 1);
	for (int i = 0; i < 2 * (n + m - 1); i++)
		p[i] = i, r[i] = 1;
	for (int i = 1; i <= m; i++) {
		unite(diag(1, i), adiag(1, i));
		unite(diag(n, i), adiag(n, i));
	}
	for (int i = 1; i <= n; i++) {
		unite(diag(i, 1), adiag(i, 1));
		unite(diag(i, m), adiag(i, m));
	}
	cout << sz;
	return 0;
}