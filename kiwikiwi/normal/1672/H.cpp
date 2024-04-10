#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int n, m, sum[2][maxN];
char s[maxN];
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 2; i <= n; i++) {
		if (s[i] == s[i - 1]) {
			int d = s[i] - '0';
			sum[d][i] = sum[d][i - 1] + 1;
			sum[1 - d][i] = sum[1 - d][i - 1];
		} else {
			sum[0][i] = sum[0][i - 1];
			sum[1][i] = sum[1][i - 1];
		}
	}
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", max(sum[0][r] - sum[0][l], sum[1][r] - sum[1][l]) + 1);
	}
}