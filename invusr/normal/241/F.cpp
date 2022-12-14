#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 105;
const int MaxM = 105;
const int MaxL = 1005;
const int NLet = 26;

int n, m, qt;
int sx, sy, ex, ey;
int jx[NLet], jy[NLet];

char s[MaxN][MaxM];
char path[MaxL];

int main()
{
	scanf("%d %d %d", &n, &m, &qt);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	scanf("%d %d", &sx, &sy);
	scanf("%s", path);
	scanf("%d %d", &ex, &ey);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (islower(s[i][j]))
				jx[s[i][j] - 'a'] = i, jy[s[i][j] - 'a'] = j;

	int path_n = strlen(path);
	for (int i = 0; i <= path_n; ++i)
	{
		int tx, ty;
		if (i < path_n)
			tx = jx[path[i] - 'a'], ty = jy[path[i] - 'a'];
		else
			tx = ex, ty = ey;
		while (sx != tx || sy != ty)
		{
			int t = isdigit(s[sx][sy]) ? s[sx][sy] - '0' : 1;
			if (t > qt)
			{
				printf("%d %d\n", sx, sy);
				return 0;
			}

			if (sx < tx)
				++sx;
			else if (sx > tx)
				--sx;
			if (sy < ty)
				++sy;
			else if (sy > ty)
				--sy;
			qt -= t;
		}
	}

	printf("%d %d\n", sx, sy);

	return 0;
}