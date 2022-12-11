#include <algorithm>
#include <cstring> 
#include <cstdio>
using namespace std;

typedef long long ll;

const int N = 25;

char s[N]; //19 bits 
int n, cnt[N], a[N], m, b[N];
ll fac[N], ans;

ll c(int n, int m) {
	return n < m ? 0 : fac[n] / fac[m] / fac[n - m];
}

void dfs(int u, int len) {
	if(u == m + 1) {
		ll res = fac[len];
		for(int i = 1; i <= m; i ++) res /= fac[b[i]];
		if(!cnt[0]) {
			ans += res; return ;
		}
		for(int i = 1; i <= cnt[0]; i ++) {
			ans += c(i + len - 1, len - 1) * res;
		}
		return ;
	}
	for(int i = 1; i <= cnt[a[u]]; i ++) {
		b[u] = i; dfs(u + 1, len + i);
	}
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	fac[0] = 1;
	for(int i = 1; i <= 20; i ++) {
		fac[i] = fac[i - 1] * i;
	}
	for(int i = 1; i <= n; i ++) cnt[s[i] - '0'] ++;
	for(int i = 1; i < 10; i ++) if(cnt[i]) a[++ m] = i;
	dfs(1, 0);
	printf("%I64d\n", ans);
	return 0;
}
/*
skcnt[k]
ans1 ~ cnt[k] 
*/