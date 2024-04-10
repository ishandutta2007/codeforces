#include <bits/stdc++.h>
using namespace std;

int tr[524288][5][5], ans[5], tmp[5], n, q;
char buf[200005];

void qu(int at, int lo, int hi, int rlo, int rhi)
{
	if (lo == rlo && hi == rhi)
	{
		for (int i = 0;i < 5;i++)
		{
			tmp[i] = 1000000;
			for (int j = 0;j < 5;j++) tmp[i] = min(tmp[i], ans[j]+tr[at][j][i]);
		}
		for (int i = 0;i < 5;i++) ans[i] = tmp[i];
	} else
	{
		int mid = (lo+hi) >> 1;
		if (rhi <= mid) qu(at*2, lo, mid, rlo, rhi);
		else if (rlo >= mid) qu(at*2+1, mid, hi, rlo, rhi);
		else { qu(at*2, lo, mid, rlo, mid); qu(at*2+1, mid, hi, mid, rhi); }
	}
}

int main()
{
	scanf("%d%d%s", &n, &q, buf);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < 5;j++) for (int k = 0;k < 5;k++) tr[i+262144][j][k] = (j!=k)*1000000;
		switch (buf[i])
		{
		case '0':
			tr[i+262144][1][1] = 1; tr[i+262144][1][2] = 0;
			break;
		case '1':
			tr[i+262144][2][2] = 1; tr[i+262144][2][3] = 0;
			break;
		case '2':
			tr[i+262144][0][0] = 1; tr[i+262144][0][1] = 0;
			break;
		case '6':
			tr[i+262144][3][3] = tr[i+262144][4][4] = 1;
			break;
		case '7':
			tr[i+262144][3][3] = 1; tr[i+262144][3][4] = 0;
			break;
		}
	}
	for (int i = 262143;i;i--) for (int j = 0;j < 5;j++) for (int k = 0;k < 5;k++)
	{
		tr[i][j][k] = 1000000;
		for (int l = 0;l < 5;l++) tr[i][j][k] = min(tr[i][j][k], tr[i*2][j][l]+tr[i*2+1][l][k]);
	}
	while (q--)
	{
		int a, b; scanf("%d%d", &a, &b);
		ans[0] = 0; ans[1] = ans[2] = ans[3] = ans[4] = 1000000;
		qu(1, 0, 262144, a-1, b);
		if (ans[4] == 1000000) printf("-1\n");
		else printf("%d\n", ans[4]);
	}
	return 0;
}