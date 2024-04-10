#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int e[1 << 12],w[12],n;
int s[1 << 12][101];
int v[1 << 12];
int val(int k) {
	int ans = 0;
	for (int i = 0; i < n; i++)if (!((k>>(n-i-1)) & 1))ans += w[i];
	return ans;
}
int main() {
	int  m, q,i,j,a,k;
	char c;
	scanf("%d%d%d", &n, &m, &q);
	for (i = 0; i < n; i++)scanf("%d", w + i);
	for (i = 0; i < 1 << n; i++)v[i] = val(i);
	for (i = 0; i < m; i++) {
		a = 0;
		scanf(" ");
		for (j = 0; j < n; j++)c = getchar() , a <<= 1, a |= (c - '0');
		e[a]++;
	}
	for (i = 0; i < 1 << n; i++) {
		for (j = 0; j < 1 << n; j++) {
			if(v[i^j]<=100)s[i][v[i^j]] += e[j];
		}
		for (j = 1; j <=100; j++)s[i][j] += s[i][j - 1];
	}
	for (i = 0; i < q; i++) {
		a = 0;
		scanf(" ");
		for (j = 0; j < n; j++)c = getchar() , a <<= 1, a |= (c - '0');
		scanf("%d", &k);
		printf("%d\n", s[a][k]);
	}
	getchar(); getchar();
}