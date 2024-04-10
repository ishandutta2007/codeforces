#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP  make_pair
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = 998244353;
const LL INF = 1e18;
const int N = (int)1e4 + 7;
const long double PI = acos(-1);
int a[ N ];
bitset<1001> dp[N];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + m + 1);
	int mm = 1;
	for (int i = 2; i <= m; i++) {
		if (a[i] == a[mm]) continue ;
		a[++mm] = a[i];
	}
	m = mm;
	int v1, v2; scanf("%d %d", &v1, &v2);
	long long ans = INF;
	queue<PII> Q;
	Q.push({1, v1});
	dp[1][v1] = true;
	int x = 0;
	while (true) {
		queue<PII> tmp;
		while (!Q.empty()) {
			int v, t; tie(v, t) = Q.front(); Q.pop();
			if (v == m) {
				ans = min(ans, x*1ll*(v1 + v2) + v1 - t);
				continue ;
			}
			if (t == 0) { 
				tmp.push({v, v1});
				continue ;
			} 
			if (v != 1 && a[v] - a[v-1] <= t) {
				int nt = t - (a[v] - a[v-1]);
				if (!dp[v-1][nt]) {
					dp[v-1][nt] = true;
					Q.push({v-1, nt});
				}
			}
			if (v != m && a[v+1] - a[v] <= t) {
				int nt = t - (a[v+1] - a[v]);
				if (!dp[v+1][nt]) {
					dp[v+1][nt] = true;
					Q.push({v+1, nt});
				}
			}
		}
		x++;
		if (tmp.empty()) break ;
		Q = tmp;
	}
	if (ans == INF) ans = -1;
	printf("%lld\n", ans);
	return 0;
}