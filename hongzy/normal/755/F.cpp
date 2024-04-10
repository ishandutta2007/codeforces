#include <cstdio>
#include <ios>

using std :: max;
using std :: min;

const int MAXN = 1000010;

int n, k, k_, max$, min$;
int to[MAXN];

bool vis[MAXN];
int cnt, cir[MAXN];

void dfs(int u) {
	if(vis[u]) return ;
	vis[u] = true;
	cnt ++;
	dfs( to[u] );
}

int ton[MAXN], a[MAXN], s[MAXN], p;
bool f[MAXN];

bool Judge(int K$) {
	f[0] = 1;
	for(int i = 1, k, m; i <= p; i ++) {
		for(k = 1; (k << 1) <= s[i]; k <<= 1) {
			for(int j = K$; j >= k * a[i] ; j --)
				f[j] |= f[j - k * a[i]];
			if(f[K$]) return true;
		}
		m = s[i] - k + 1;
		for(int j = K$; j >= m * a[i]; j --)
			f[j] |= f[j - m * a[i]];
		if(f[K$]) return true;
	}
	return f[K$];
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &to[i]);
	for(int i = 1; i <= n; i ++)
		if(!vis[i]) cnt = 0, dfs(i), cir[++ cir[0]] = cnt;

	k_ = k;
	int c1 = 0, now;
	for(int i = 1; i <= cir[0]; i ++) {
		if(k_ == 0) break ;
		if(cir[i] & 1) c1 ++;
		now = cir[i] >> 1;
		if(k_ >= now) max$ += (now << 1), k_ -= now;
		else max$ += (k_ << 1), k_ = 0;
	}
	max$ += min(k_, c1);
	
	for(int i = 1; i <= cir[0]; i ++)
		ton[ cir[i] ] ++;
	for(int i = 1; i <= n; i ++)
		if(ton[i]) ++ p, s[p] = ton[i], a[p] = i;
	
	min$ = Judge(k) ? k : k + 1;

	printf("%d %d\n", min$, max$);
	return 0;
}