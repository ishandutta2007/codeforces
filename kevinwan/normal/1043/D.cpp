#include <bits/stdc++.h>
#define m(x,y) (a[x]>a[y]?x:y)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int a[10][100001],p[10][100001],at[10];
bool d[100001];
vector<int> ans;
int main() {
	int n, m, i, j,k;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)for (j = 1; j <= n; j++)scanf("%d", &a[i][j]), p[i][a[i][j]] = j;
	ll ans = 0;
	for (i = 1; i <= n; ) {
		for (j = 0; j < m; j++) {
			at[j] = p[j][a[0][i]];
		}
		for (j = 0; 1; j++) {
			bool flag = 0;
			for (k = 0; k < m; k++)if (at[k]+j > n)flag = 1;
			if (flag)break;
			for (k = 0; k < m; k++)if (a[k][at[k] + j] != a[0][at[0] + j])flag = 1;
			if (flag)break;
		}
		ans += 1LL * j*(j + 1) / 2;
		i += j;
	}
	printf("%lld", ans);
	getchar(); getchar();
}