#include <cstdio>
#include <cstring>

char a[222222];
char b[222222];
int d[32][222222];
int L[222222], R[222222];

int main() {
	int i, j, n, m;
	scanf("%s%s", a, b);
	n = strlen(a);
	m = strlen(b);
	for (i = j = 0; i < n; i++) if (j < m && a[i] == b[j]) {
		L[j] = i;
		j++;
	}
	if (j < m) {
		puts("No");
		return 0;
	}
	j = m - 1;
	for (i = n - 1; i >= 0; i--) if (j >= 0 && a[i] == b[j]) {
		R[j] = i;
		j--;
	}
	for (j = 0; j < m; j++) {
		d[b[j] & 31][L[j]]++;
		d[b[j] & 31][R[j] + 1]--;
	}
	for (i = 0; i < n; i++) {
		if (i) for (j = 0; j < 32; j++) d[j][i] += d[j][i - 1];
		if (!d[a[i] & 31][i]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}