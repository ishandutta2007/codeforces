#include <bits/stdc++.h>
using namespace std;

int ans[45][45][45][45], cu[45][45], r, c, q, i, j, k, l;
char buf[45];

int main()
{
	scanf("%d%d%d", &r, &c, &q);
	for (i = 1;i <= r;i++)
	{
		scanf("%s", buf+1);
		for (j = 1;j <= c;j++) cu[i][j] = buf[j]-'0'+cu[i-1][j]+cu[i][j-1]-cu[i-1][j-1];
	}
	for (i = 1;i <= r;i++) for (j = 1;j <= c;j++) for (k = i;k <= r;k++) for (l = j;l <= c;l++) if (cu[k][l]-cu[i-1][l]-cu[k][j-1]+cu[i-1][j-1] == 0) ans[i][j][k][l]++;
	for (i = 1;i <= r;i++) for (j = 1;j <= c;j++) for (k = 1;k <= r;k++) for (l = 1;l <= c;l++) ans[i][j][k][l] += ans[i-1][j][k][l]+ans[i][j-1][k][l]+ans[i][j][k-1][l]+ans[i][j][k][l-1]-ans[i-1][j-1][k][l]-ans[i-1][j][k-1][l]-ans[i-1][j][k][l-1]-ans[i][j-1][k-1][l]-ans[i][j-1][k][l-1]-ans[i][j][k-1][l-1]+ans[i-1][j-1][k-1][l]+ans[i-1][j-1][k][l-1]+ans[i-1][j][k-1][l-1]+ans[i][j-1][k-1][l-1]-ans[i-1][j-1][k-1][l-1];
	while (q--)
	{
		scanf("%d%d%d%d", &i, &j, &k, &l); i--, j--;
		printf("%d\n", ans[k][l][k][l]-ans[i][l][k][l]-ans[k][j][k][l]-ans[k][l][i][l]-ans[k][l][k][j]+ans[i][j][k][l]+ans[i][l][i][l]+ans[i][l][k][j]+ans[k][j][i][l]+ans[k][j][k][j]+ans[k][l][i][j]-ans[i][j][i][l]-ans[i][j][k][j]-ans[i][l][i][j]-ans[k][j][i][j]+ans[i][j][i][j]);
	}
	return 0;
}