#if 0
2020.03.04

 S  d / 2  AC 
 AC  DP 
 f[i][j][p][q]  i 
 AC  j 
p  i 
q 
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

const int maxn = 1005, maxd = 55, mod = 1000000007;
char s[maxn], t[maxd];
int ch[maxn * maxd][10], fail[maxn * maxd], cp = 1;
bool word[maxn * maxd];
ll f[maxd][maxn * maxd][2][2];

void trans(int i, int j, int p, int q) {
	int X = t[i + 1] - '0';
	for(int x = 0; x < 10; x ++) {
		int k = j;
		while(k and !ch[k][x])
			k = fail[k];
		k = k ? ch[k][x] : 1;
		if(p & (x > X)) break;
		f[i + 1][k][p & (x == X)][q | word[k]] += f[i][j][p][q];
	}
}

void dp(int m) {
	memset(f, 0, sizeof f);
	f[0][1][1][0] = 1;
	for(int i = 0; i < m; i ++)
		for(int j = 1; j <= cp; j ++)
			for(int p = 0; p < 2; p ++)
				for(int q = 0; q < 2; q ++) {
					f[i][j][p][q] %= mod;
					trans(i, j, p, q);
				}
}

int main() {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));

	scanf("%s", t + 1);
	int m = int(strlen(t + 1));

	for(int p = 1; p + (m >> 1) - 1 <= n; p ++) {
		int now = 1;
		for(int i = p; i < p + (m >> 1); i ++) {
			int &to = ch[now][s[i] - '0'];
			if(!to) to = ++ cp;
			now = to;
		}
		word[now] = 1;
	}

	std::queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int x = 0; x < 10; x ++)
			if(ch[u][x]) {
				int p = fail[u];
				while(p and !ch[p][x])
					p = fail[p];
				fail[ch[u][x]] = p ? ch[p][x] : 1;
				q.push(ch[u][x]);
			}
	}

	dp(m);
	ll ans = 0;
	for(int j = 1; j <= cp; j ++)
		ans -= f[m][j][0][1];

	scanf("%s", t + 1);
	dp(m);
	for(int j = 1; j <= cp; j ++)
		ans += f[m][j][0][1] + f[m][j][1][1];

	ans %= mod;
	if(ans < 0) ans += mod;
	printf("%lld\n", ans);
}