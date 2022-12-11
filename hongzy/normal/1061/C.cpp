#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

inline void upd(int &x, const int &y) {
	(x += y) >= MOD ? x -= MOD : 0;
}

int n, a[N], dp[N];
vector<int> st[2];
/*
dp[i][j]:i, jdp[j]
dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (a[i] == j * k)
dp[j] += dp[j - 1] * (a[i] % j == 0)
 
*/
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	dp[0] = 1;
	for(int i = 1; i <= n; i ++) {
		st[0].clear(); st[1].clear();
		for(int j = 1; j * j <= a[i]; j ++) {
			if(a[i] % j == 0) {
				st[0].push_back(j);
				if(a[i] / j <= n && j != a[i] / j) {
					st[1].push_back(a[i] / j);
				} 
			}
		}
		reverse(st[0].begin(), st[0].end());
		vector<int> :: iterator p1 = st[0].begin(), p2 = st[1].begin();
		while(p1 != st[0].end() || p2 != st[1].end()) {
			if(p2 == st[1].end() || * p1 > * p2) upd(dp[* p1], dp[(* p1) - 1]), p1 ++;
			else upd(dp[* p2], dp[(* p2) - 1]), p2 ++;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) upd(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}