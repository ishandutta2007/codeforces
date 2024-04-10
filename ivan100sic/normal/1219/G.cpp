#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
ll highest(int k, vector<ll> a) {
	if (k >= (int)a.size())
		return accumulate(a.begin(), a.end(), 0ll);
	nth_element(a.begin(), a.end()-k, a.end());
	return accumulate(a.end()-k, a.end(), 0ll);
}
 
ll solve(vector<vector<int>> a) {
	int n = a.size(), m = a[0].size();
	vector<ll> c(m);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			c[j] += a[i][j];
	ll sol = highest(4, c);
	// svaku vrstu
	for (int i=0; i<n; i++) {
		ll t = 0;
		for (int j=0; j<m; j++)
			c[j] -= a[i][j], t += a[i][j];
 
		sol = max(sol, highest(3, c) + t);
 
		for (int j=0; j<m; j++)
			c[j] += a[i][j];
	}
 
	// svake dve vrste ako moze
	if (n <= m) {
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
 
				ll t = 0, u = 0;
				for (int k=0; k<m; k++)
					u = a[i][k] + a[j][k], t += u, c[k] -= u;
 
				sol = max(sol, highest(2, c) + t);
 
				for (int k=0; k<m; k++)
					c[k] += a[i][k] + a[j][k];
			}
		}
	}
 
	return sol;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
 
	int n, m;
	vector<vector<int>> a, b;
	cin >> n >> m;
	a.resize(n, vector<int>(m));
	b.resize(m, vector<int>(n));
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j], b[j][i] = a[i][j];
	cout << max(solve(a), solve(b)) << '\n';
}