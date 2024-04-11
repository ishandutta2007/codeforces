#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 220, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for(auto &i : a) for(auto &j : i) cin >> j;
		ll ans = 0;
		for(int i = 0; i <= n-1-i; i++)
			for(int j = 0; j <= m-1-j; j++) {
				vector<int> f{a[i][j]};
				if(i != n-1-i) f.push_back(a[n-1-i][j]);
				if(j != m-1-j) f.push_back(a[i][m-1-j]);
				if(i != n-1-i && j != m-1-j) f.push_back(a[n-1-i][m-1-j]);
				sort(all(f));
				int x = f[f.size()/2];
				for(auto i : f) ans += abs(i-x);
				//cout << i << " " << j << " " << n-1-i << " " << m-1-j << " " << ans << " " << f.size() << endl;
			}
		cout << ans << '\n';
	}
}