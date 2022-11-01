#include <bits/stdc++.h>
using namespace std;

int p[5005][5005];
int b[5005][5005];
bool in[5005];
int n, m, ans;
int x[5005];

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		printf("? 0 %d\n", i); fflush(stdout);
		scanf("%d", x+i);
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			b[m][j] = i ^ x[j];
		bool ok = !b[m][i];
		for (int j = 0;j < n;j++) if (b[m][j] >= n)
			ok = false;
		if (ok)
		{
			for (int j = 0;j < n;j++) p[m][b[m][j]] = j;
			in[m] = true;
			m++;
		}
	}
	ans = m;
	int idx = 0;
	for (int i = 1;i < m;i++)
	{
		int cP = p[idx][0]^p[i][0], cB = b[idx][0]^b[i][0];
		for (int j = 0;j < n;j++)
		{
			int aP = p[idx][j]^p[i][j], aB = b[idx][j]^b[i][j];
			int qP = 0, qB = 0;
			if (aP != cP) qP = j;
			else if (aB != cB) qB = j;
			else continue;
			printf("? %d %d\n", qP, qB); fflush(stdout);
			int r = 0; scanf("%d", &r);
			for (int k = 0;k < m;k++) if ((p[k][qP]^b[k][qB]) != r && in[k])
			{
				in[k] = false;
				ans--;
			}
			while (!in[idx]) idx++;
			break;
		}
	}
	printf("!\n%d\n", ans);
	for (int i = 0;i < n;i++) printf("%d%c", p[idx][i], " \n"[i==n-1]);
	fflush(stdout);
	return 0;
}