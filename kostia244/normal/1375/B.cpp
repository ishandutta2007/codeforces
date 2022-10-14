#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<18;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(auto &i : a)
		for(auto &j : i)
			cin >> j;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) {
			int cnt = 4 - (j == 0 || j+1 == m) - (i == 0 || i+1 == n);
			if(a[i][j] > cnt) {cout << "NO\n";return;}
			a[i][j] = cnt;
		}
	cout << "YES\n";
	for(auto &i : a) {
		for(auto j : i) cout << j << " "; cout << '\n';
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}