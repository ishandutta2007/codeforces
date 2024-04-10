#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, k, sum[maxn];
char str1[maxn], str2[maxn];

bool comp(int p) {
	for (int i = 1; i <= m; i++) {
		if (str2[i] != str1[i + p - 1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	gets(str1);
	gets(str1 + 1);
	gets(str2 + 1);
	for (int i = 1; i <= n - m + 1; i++) {
		if (comp(i)) {
			sum[i + m - 1]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		sum[i] += sum[i - 1];
	}
	for (int l, r; k--; ) {
		scanf("%d %d", &l, &r);
		printf("%d\n", r - l + 1 < m ? 0 : sum[r] - sum[l + m - 2]);
	}
	return 0;
}