#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int ans[100][100];
int a[100], b[100];
int main() {
	int n, m,x,i,j,k;
	scanf("%d%d", &n, &m);
	int cum = 0;
	for (i = 0; i < n; i++)scanf("%d", a + i),cum^=a[i];
	for (i = 0; i < m; i++)scanf("%d", b + i), cum ^= b[i];;
	if (cum) { printf("NO"); return 0; }
	for (i = 0; i < 30; i++) {
		int ln = -1;
		for (j = 0; j < n; j++) {
			if (!((a[j] >> i) & 1))continue;
			if (ln == -1)ln = j;
			else ans[j][0] ^= 1 << i, ans[ln][0] ^= 1<<i,ln=-1;
		}
		int lm = -1;
		for (j = 0; j < m; j++) {
			if (!((b[j] >> i) & 1))continue;
			if (lm == -1)lm = j;
			else ans[0][j] ^= 1 << i, ans[0][lm] ^= 1 << i,lm=-1;
		}
		if (ln != -1)ans[ln][lm] ^= 1 << i;
	}
	printf("YES\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)printf("%d ", ans[i][j]);
		printf("\n");
	}
}