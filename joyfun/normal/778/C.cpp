#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 300005;
const int inf = 0x3f3f3f3f;

int n;
vector<pii> g[N];
int ch[N * 4][26], cn, val[N], dp[N * 20];

int new_node() {
	++cn;
	memset(ch[cn], 0, sizeof(ch[cn]));
	dp[cn] = 1;
	return cn;
}

void meg(int &u, int v) {
	int x = new_node();
	for (int i = 0; i < 26; i++) ch[x][i] = ch[u][i];
	u = x;
	for (int i = 0; i < 26; i++) {
		if (ch[u][i] && ch[v][i]) meg(ch[u][i], ch[v][i]);
		else if (!ch[u][i] && ch[v][i]) ch[u][i] = ch[v][i];
		dp[u] += dp[ch[u][i]];
	}
}

void dfs(int u, int d) {
	dp[u] = 1;
	int rt = new_node();
	for (int i = 0; i < 26; i++) {
		int v = ch[u][i];
		if (!v) continue;
		dfs(v,  d + 1);
		dp[u] += dp[v];
		meg(rt, v);
	}
	val[d] += dp[u] - dp[rt];
}

int main() {
	scanf("%d", &n);
	int u, v;
	char c;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %c", &u, &v, &c);
		ch[u][c - 'a'] = v;
	}
	cn = n;
	dfs(1, 1);
	int ans = inf, ansv;
	for (int i = 1; i <= n; i++) {
		if (ans > n - val[i]) {
			ans = n - val[i];
			ansv = i;
		}
	}
	printf("%d\n%d\n", ans, ansv);
	return 0;
}