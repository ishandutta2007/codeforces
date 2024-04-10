#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = (int)1e9 + 7;

const int N = (int)1e3 + 7;
vector<int> edge[ N ];
int num[ N ];
char s[ N ];
int dp[ N ][ N ];
inline int add(int v1, int v2) {
	v1 += v2; if (v1 >= mod) v1 -= mod;
	return v1;
}
int main() {
	int m, n; scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				edge[j].push_back(i);
			} else {
				edge[j].push_back(i + n);
			}
		}
	}
	int deg = 0;
	map<vector<int>, int> mp;
	for (int i = 0; i < m; i++) {
		sort(edge[i].begin(), edge[i].end());
		if (mp.find(edge[i]) == mp.end()) {
			mp[ edge[i] ] = ++deg;
			num[deg] = 1;
		} else {
			num[ mp[edge[i]] ]++;
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i+1][j] = add(dp[i+1][j], dp[i][j]*1ll*j%mod);
			dp[i+1][j+1] = add(dp[i+1][j+1], dp[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = add(dp[i][j], dp[i][j-1]);
		}
	}
	int ans = 1;
	for (int i = 1; i <= deg; i++) {
		ans = ans*1ll*dp[ num[i] ][ num[i] ]%mod;
	}
	printf("%d\n", ans);
	return 0;
}