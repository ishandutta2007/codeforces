#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 60, mod = 1e9 + 7, i2 = (mod+1)/2;
int n, m, a, b;
void solve() {
	cin >> n >> m >> a >> b;
	if(n*a != m*b) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<int> ro(m);
	for(int i = 0; i < n; i++) {
		vector<pair<int, int>> t;
		for(int j = 0; j < m; j++) t.pb({ro[j], j});
		sort(all(t));
		string cur(m, '0');
		for(int i = 0; i < a; i++) {
			int p = t[i].second;
			cur[p] = '1';
			ro[p]++;
		}
		cout << cur << '\n';
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}