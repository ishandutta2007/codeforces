#include<bits/stdc++.h>
#define inf 1000000001
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



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
		int n, m;
		cin >> n >> m;
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<array<int, 3>>> b(n);
		vector<array<int, 3>> c(m);
		for(int i = 0; i < m; i++) {
			int e, t, p;
			cin >> e >> t >> p;
			--e;
			b[e].push_back({p, t, i});
			c[i] = {e, t, p};
		}
		vi need(n);
		vvi id(n);
		bool ok = true;
		for(int i = 0; i < n; i++) {
			vvi dp(b[i].size() + 1, vi(101, inf));
			vector<vector<bool>> use(b[i].size() + 1, vector<bool>(101, false));
			dp[0][0] = 0;
			for(int j = 1; j <= b[i].size(); j++) {
				dp[j][0] = 0;
				for(int k = 1; k <= 100; k++) {
					dp[j][k] = dp[j - 1][k];
					if(b[i][j - 1][1] + dp[j - 1][max(0, k - b[i][j - 1][0])] < dp[j][k]) {
						dp[j][k] = b[i][j - 1][1] + dp[j - 1][max(0, k - b[i][j - 1][0])];
						use[j][k] = true;
					}
				}
			}
			if(dp[b[i].size()][100] == inf) {
				ok = false;
				break;
			}
			need[i] = dp[b[i].size()][100];
			int now1 = b[i].size();
			int now2 = 100;
			while(now2 > 0) {
				if(use[now1][now2]) {
					id[i].push_back(b[i][now1 - 1][2]);
					now2 -= b[i][now1 - 1][0];
					--now1;
				} else {
					--now1;
				}
			}
		}
		if(!ok) {
			cout << -1 << '\n';
			continue;
		}
		int now = 0;
		vi ans;
		for(int i = 0; i < n; i++) {
			for(const auto& el : id[i]) {
				ans.push_back(el);
			}
			now += need[i];
			if(now > a[i]) {
				ok = false;
				break;
			}
		}
		if(!ok) {
			cout << -1 << '\n';
			continue;
		}
		cout << ans.size() << '\n';
		for(const auto& el : ans) {
			cout << el + 1 << ' ';
		}
		cout << '\n';
	}
}