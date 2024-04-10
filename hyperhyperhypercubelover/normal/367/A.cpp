#include <cstdio>
#include <algorithm>

using namespace std;

char a[111111];
int d[3][111111];

int main()
{
	int i, j, n;
	scanf("%s%d", a + 1, &n);
	for (i = 1; a[i]; i++)
	{
		d[0][i] = d[0][i - 1];
		d[1][i] = d[1][i - 1];
		d[2][i] = d[2][i - 1];
		d[a[i] - 120][i]++;
	}
	while (n--)
	{
		scanf("%d%d", &i, &j);
		i--;
		puts(j - i < 3 || max(d[0][j] - d[0][i], max(d[1][j] - d[1][i], d[2][j] - d[2][i])) - min(d[0][j] - d[0][i], min(d[1][j] - d[1][i], d[2][j] - d[2][i])) < 2 ? "YES" : "NO");
	}
}