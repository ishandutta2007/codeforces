#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

char s[25];
int q;
ll dp[25][25][1<<16];
int bit[25], bn;

ll cal(char *s) {
	int len = strlen(s);
	ll ans = 0;
	for (int i = 0; i < len; i++)
		ans = ans * 16 + (s[i] >= '0' && s[i] <= '9' ?  s[i] - '0' : s[i] - 'a' + 10);
	return ans;
}

ll dfs(int u, int m, int s, int f) {
	if (dp[u][m][s] != -1 && f) return dp[u][m][s];
	ll tmp = 0;
	if (u == bn) tmp = (s>>m)&1;
	else {
		int up = f ? 15 : bit[u];
		for (int i = 0; i <= up; i++)
			tmp += dfs(u + 1, max(m, i), (s * 16 + i) % (1<<16), f|(i<up));
	}
	if (f) dp[u][m][s] = tmp;
	return tmp;
}

ll get(ll x) {
	if (x < 0) return 0;
	bn = 0;
	while (x) {
		bit[bn++] = x % 16;
		x /= 16;
	}
	while (bn < 19) bit[bn++] = 0;
	reverse(bit, bit + bn);
	//for (int i = 0; i < bn; i++) printf("%d ", bit[i]); printf("\n");
	//printf("%lld\n", dfs(0, 0, 0, 0));
	return dfs(0, 0, 0, 0);
}

int main() {
	scanf("%d", &q);
	memset(dp, -1, sizeof(dp));
	while (q--) {
		ll ans = 0;
		for (int i = -1; i <= 1; i++) {
			if (i == 0) continue;
			scanf("%s", s);
			ll x = cal(s);
			if (i == -1) x--;
			ans += i * get(x);
		}
		printf("%lld\n", ans);
	}
	return 0;
}