#pragma GCC optimize(2)
#if 0
date


#endif
#include <algorithm>
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

const int maxn = 1000005;
int ti[maxn];
ll val[maxn];
int nxt[maxn], pre[maxn];
int stack[maxn], sp;

int main() {
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i ++) {
		ti[i] = 1;
		scanf("%lld", val + i);
		pre[i] = i - 1;
		nxt[i] = i + 1;
		if(i > 1 and val[i - 1] > val[i])
			stack[++ sp] = i - 1;
	}
	nxt[n] = 0;

	while(sp) {
		int p = stack[sp --], q = nxt[p];
		if(!q or val[p] * ti[q] < val[q] * ti[p])
			continue;

		// debug("%d - (%d) - %d\n", pre[p], p, nxt[p]);

		val[p] += val[q];
		ti[p] += ti[q];

		nxt[p] = nxt[q];
		if(nxt[p]) pre[nxt[p]] = p;

		nxt[q] = pre[q] = 0;

		if(pre[p]) stack[++ sp] = pre[p];
		if(nxt[nxt[p]]) stack[++ sp] = nxt[p];
		if(nxt[p]) stack[++ sp] = p;
	}

	// std::cerr << clock() / CLOCKS_PER_SEC << std::endl;

	for(int i = 1; i; i = nxt[i]) {
		// ll x = val[i] / ti[i];
		// ll y = val[i] % ti[i] * 10000000000 / ti[i];
		for(int j = 1; j <= ti[i]; j ++)
			// printf("%lld.%010lld\n", x, y);
			printf("%.10lf\n", double(val[i]) / ti[i]);
	}

	// std::cerr << clock() / CLOCKS_PER_SEC << std::endl;
}