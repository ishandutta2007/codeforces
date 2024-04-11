#include<bits/stdc++.h>
#define comp loli
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20;
void solve() {
	int n;
	cin >> n;
	vector<vector<int>> f(n+1);
	for(int i = 1; i <= n; i++) f[i].push_back(-1);
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		f[t].push_back(i);
	}
	for(int i = 1; i <= n; i++) f[i].push_back(n);
	vector<int> ans(n+2, 1<<30);
	for(int i = 1; i <= n; i++) {
		int k = 0;
		for(int j = 1; j < f[i].size(); j++) {
			k = max(k, f[i][j]-f[i][j-1]-1);
		}
		k++;
		ans[k] = min(ans[k], i);
	}
	for(int i = 1; i <= n; i++) {
		ans[i] = min(ans[i], ans[i-1]);
		if(ans[i] == 1<<30) cout << "-1 ";
		else cout << ans[i] << " ";
	}cout << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}