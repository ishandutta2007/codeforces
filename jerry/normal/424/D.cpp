#include <cstdio>
#include <algorithm>

using namespace std;

int right[302][302];
int up[302][302];
int down[302][302];
int left[302][302];
int val[302][302];
int ans(2147483647);
int I, J, K, L;
int tp;
int tu;
int td;
int r;
int c;
int t;

int cost(int b, int a)
{
	if (a < b)
		return tu;
	if (a > b)
		return td;
	return tp;
}

int main()
{
	scanf("%d%d%d%d%d%d", &r, &c, &t, &tp, &tu, &td);
	for (int i = 1;i <= r;i++) for (int j = 1;j <= c;j++)
		scanf("%d", &val[i][j]);
	for (int i = 1;i <= r;i++) for (int j = 2;j <= c;j++)
		right[i][j] = cost(val[i][j], val[i][j-1]) + right[i][j-1];
	for (int i = 1;i <= r;i++) for (int j = c-1;j >= 1;j--)
		left[i][j] = cost(val[i][j], val[i][j+1]) + left[i][j+1];
	for (int i = 2;i <= r;i++) for (int j = 1;j <= c;j++)
		down[i][j] = cost(val[i][j], val[i-1][j]) + down[i-1][j];
	for (int i = r-1;i >= 1;i--) for (int j = 1;j <= c;j++)
		up[i][j] = cost(val[i][j], val[i+1][j]) + up[i+1][j];
	for (int i = 1;i <= r;i++) for (int j = 1;j <= c;j++)
		for (int k = i+2;k <= r;k++) for (int l = j+2;l <= c;l++)
	{
		int temp = abs(right[i][l]-right[i][j]
		             + down[k][l]-down[i][l]
					 + left[k][j]-left[k][l]
					 + up[i][j]-up[k][j] - t);
		if (temp < ans)
		{
			ans = temp;
			I = i; J = j; K = k; L = l;
		}
	}
	printf("%d %d %d %d\n", I, J, K, L);
	return 0;
}