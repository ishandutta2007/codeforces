#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int n;
ll k;
ll pri[N], pn;
int cnt[N], ts[N];
ll a[N];
pair<int, ll> dp[N][1<<13];
int path[N][1<<13][2];
int s[N];
int ans[N], an;
void print(int n, int s) {
	if (n == 0) return;
	print(n - 1, path[n][s][0]);
	if (path[n][s][1]) ans[an++] = path[n][s][1];
}

int tmp[20], tn;
int get(int a, int b) {
	tn = 0;
	for (int i = 0; i < pn; i++) {
		tmp[tn++] = min(cnt[i], a % (cnt[i] + 1) + b % (cnt[i] + 1));
		a /= (cnt[i] + 1); b /= (cnt[i] + 1);
	}
	int ans = 0;
	for (int i = tn - 1; i >= 0; i--) ans = ans * (cnt[i] + 1) + tmp[i];
	return ans;
}

int main() {
	while (~scanf("%d%lld", &n, &k)) {
		if (k == 1) {
			ll Min = 1;
			for (int i = 1; i <= n; i++) {
				scanf("%lld", &a[i]);
				if (a[i] < a[Min]) Min = i;
			}
			printf("1\n%lld\n", Min);
			continue;
		}
		for (ll i = 2; i * i <= k; i++) {
			if (k % i == 0) {
				pri[pn++] = i;
				while (k % i == 0) {
					k /= i;
					cnt[pn - 1]++;
				}
			}
		}
		if (k != 1) {cnt[pn] = 1; pri[pn++] = k;}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			s[i] = 0;
			ll aa = a[i];
			for (int j = pn - 1; j >= 0; j--) {
				s[i] *= (cnt[j] + 1);
				while (aa % pri[j] == 0) {
					aa /= pri[j];
					s[i]++;
				}
			}
		}
		ts[0] = cnt[0] + 1;
		for (int i = 1; i < pn; i++) ts[i] = (cnt[i] + 1) * ts[i - 1];
		for (int j = 0; j < ts[pn - 1]; j++) dp[0][j] = make_pair(INF, 0LL);
		dp[0][0] = make_pair(0, 0LL);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < ts[pn - 1]; j++) dp[i][j] = make_pair(INF, 0LL);
			for (int j = 0; j < ts[pn - 1]; j++) {
				pair<int, ll> sb = make_pair(dp[i - 1][j].first + 1, dp[i - 1][j].second + a[i]);
				int jj = get(j, s[i]);
				if (dp[i][jj] > sb) {
					dp[i][jj] = sb;
					path[i][jj][0] = j;
					path[i][jj][1] = i;
				}
				if (dp[i][j] > dp[i - 1][j]) {
					dp[i][j] = dp[i - 1][j];
					path[i][j][0] = j;
					path[i][j][1] = 0;
				}
			}
			//	for (int j = 0; j < ts[pn - 1]; j++) printf("%d %d %d %lld\n", i, j, dp[i][j].first, dp[i][j].second);
		}
		if (dp[n][ts[pn - 1] - 1].first == INF) printf("-1\n");
		else {
			an = 0;
			print(n, ts[pn - 1] - 1);
			printf("%d\n", an);
			for (int i = 0; i < an; i++) printf("%d ", ans[i]); printf("\n");
		}
	}
	return 0;
}