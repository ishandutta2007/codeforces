#include <stdio.h>
#include <string.h>

const int N = 100005;

__int64 num[N];
int sn = 0, ansn = 0, save[N], ans[N], m, n;
struct CZ {
	int v, x;
	__int64 l, c;
} cz[N];

void init() {
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%I64d", &cz[i].v);
		if (cz[i].v == 1)
			scanf("%I64d", &cz[i].x);
		else scanf("%I64d%I64d", &cz[i].l, &cz[i].c);
	}
	scanf("%d", &n);
	for (int j = 0; j < n; j++)
		scanf("%I64d", &num[j]);
}

void table() {
	for (int i = 0; i < m; i++) {
		if (cz[i].v == 1) {
			save[sn++] = cz[i].x;
			if (sn == 100000) return;
		}
		else {
			for (int k = 0; k < cz[i].c; k++) {
				for (int j = 0; j < cz[i].l; j++) {
					save[sn++] = save[j];
					if (sn == 100000) return;
				}
			}
		}
	}
}

void solve() {
	table(); 
	int j = 0, i = 0;
	__int64 now = 0;
	while(i < n) {
		while(j < m) {
			if (cz[j].v == 1) {
				now ++; 
				if (now == num[i]) {
					ans[ansn++] = cz[j].x;i++;
					if (i >= n) return;
					j++;
					break;
				}
				j++;
			}
			else {
				__int64 nn = now;
				now += cz[j].l * cz[j].c;
				if (now >= num[i]) {
					while (i < n) {
						if (num[i] <= now) {
							ans[ansn++] = save[(num[i++] - nn - 1) % cz[j].l % 100000];
							if (i >= n) return;
						}
						else {
							j++;
							break;
						}
					}
				}
				else {
					j++;
				}
			}
		}
	}

}

int main() {
	init();
	solve();
	for (int i = 0; i < ansn - 1; i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[ansn - 1]);
	return 0;
}