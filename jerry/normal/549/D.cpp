#include <bits/stdc++.h>
using namespace std;

char x[128][128];
int use[128][128];
int r;
int c;
int ans;

int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0;i < r;i++)
		scanf("%s", x[i]);
	for (int i = r-1;i >= 0;i--) for (int j = c-1;j >= 0;j--)
	{
		int tot = 0;
		for (int k = i;k < r;k++) for (int l = j;l < c;l++)
			tot += use[k][l];
		if ((x[i][j] == 'W' && tot != 1) || (x[i][j] == 'B' && tot != -1))
		{
			ans++;
			if (x[i][j] == 'W')
				use[i][j] = 1 - tot;
			else
				use[i][j] = -1 - tot;
		}
	}
	printf("%d\n", ans);
	return 0;
}