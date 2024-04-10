#include <stdio.h>
#include <string.h>

const int N = 10000001;

int vis[N], sum[N], v[N];

void init() {
	int num, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		vis[num]++;
	}
}

void cal() {
	for (int i = 2; i < N; i++) {
		if (v[i]) continue;
		for (int j = i; j < N; j += i) {
			if (vis[j]) sum[i] += vis[j];
			v[j] = 1;
		}
	}
}

void solve() {
	for (int i = 2; i < N; i++)
		sum[i] += sum[i - 1];
	int m, l, r;
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &l, &r);
		if (r >= N) r = N - 1;
		if (l >= N) l = N;
		printf("%d\n", sum[r] - sum[l - 1]);
	}
}

int main() {
	init();
	cal();
	solve();
	return 0;
}