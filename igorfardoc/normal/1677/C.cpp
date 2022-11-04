#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
vvi g;
vector<bool> used;

int dfs(int v) {
	int res = 1;
	used[v] = true;
	for(int u : g[v]) {
		if(used[u]) continue;
		res += dfs(u);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n), b(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			--a[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
			--b[i];
		}
		g.assign(n, {});
		used.assign(n, false);
		for(int i = 0; i < n; i++) {
			g[a[i]].push_back(b[i]);
			g[b[i]].push_back(a[i]);
		}
		vi sz2;
		vi sz1;
		vi sz;
		for(int i = 0; i < n; i++) {
			if(used[i]) continue;
			int res = dfs(i);
			sz.push_back(res);
			if(res % 2 == 0) {
				sz2.push_back(res);
			} else {
				sz1.push_back(res);
			}
		}
		int l = 1;
		int r = n;
		ll ans = 0;
		for(const auto& el : sz) {
			for(int i = 0; i < el / 2; i++) {
				ans += 2 * r;
				ans -= 2 * l;
				--r;
				++l;
			}
		}
		cout << ans << '\n';
	}

}