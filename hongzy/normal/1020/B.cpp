#include <cstdio>

int cnt[1010], n, nxt[1010];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &nxt[i]);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) cnt[j] = 0;
		int j; for(j = i; !cnt[j]; j = nxt[j]) cnt[j] ++;
		printf("%d%c", j, " \n"[i == n]);
	}
	return 0;
}