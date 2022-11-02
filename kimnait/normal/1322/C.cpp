#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = (int)1e9 + 7;

const int N = (int)5e5 + 7;
long long a[ N ];
long long val[ N ];
vector<int> edge[ N ];
long long gcd(long long v1, long long v2) {
	while (v1) {
		long long tmp = v2 % v1;
		v2 = v1;
		v1 = tmp;
	}
	return v2;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", a + i);
			edge[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			int u, v; scanf("%d %d", &u, &v);
			edge[v].push_back(u);
		}
		map<vector<int>, int> mp;
		int cntp = 0;
		for (int i = 1; i <= n; i++) {
			if (edge[i].empty()) continue ;
			sort(edge[i].begin(), edge[i].end());
			if (mp.find(edge[i]) == mp.end()) {
				mp[ edge[i] ] = ++cntp;
				val[cntp] = a[i];
			} else {
				val[ mp[ edge[i] ] ] += a[i];
			}
		}
		long long ans = val[1];
		for (int i = 2; i <= cntp; i++)
			ans = gcd(ans, val[i]);
		printf("%lld\n", ans);
	}
	return 0;
}