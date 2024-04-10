#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 150005;
const ll inf = 1ll<<60;
int n, m, d;

int a[N], b[N], t[N], Q[N];
ll dp[2][N];
int he, re;

int main() {
	scanf("%d%d%d", &n, &m, &d);
	int pre = 0, now = 1;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i], &b[i], &t[i]);
		swap(now, pre);
		he = re = 0;
		int pr = 0;
		for (int j = 1; j <= n; j++) {
			dp[now][j] = -inf;
			ll len = 1ll * d * (t[i] - t[i - 1]);
			int l = max(1ll, j - len);
			int rr = min(1ll * n, j + len);
			for (int r = pr + 1; r <= rr; r++) {
				while (re > he && dp[pre][Q[re - 1]] <= dp[pre][r]) re--;
				Q[re++] = r;
			}
			while (re > he && Q[he] < l) he++;
			if (re > he) dp[now][j] = dp[pre][Q[he]] + b[i] - abs(j - a[i]);
			pr = rr;
		}
	}
	ll ans = -inf;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[now][i]);
	printf("%lld\n", ans);
	return 0;
}