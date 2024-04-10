#include <cstdio>

bool can[5][105];
char buf[5][105];
int n, k;

const char* solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 0;i < 3;i++)
	{
		scanf("%s", buf[i]);
		for (int j = n;j < n+3;j++)
			buf[i][j] = '.';
		if (buf[i][0] == 's')
			can[i][0] = true;
	}
	for (int j = 0;j < n+3;j+=3) for (int i = 0;i < 3;i++) if (can[i][j] && buf[i][j+1] == '.')
	{
		if (i != 0)
		{
			if (buf[i-1][j+1] == '.' && buf[i-1][j+2] == '.' && buf[i-1][j+3] == '.')
				can[i-1][j+3] = true;
		}
		if (i != 2)
		{
			if (buf[i+1][j+1] == '.' && buf[i+1][j+2] == '.' && buf[i+1][j+3] == '.')
				can[i+1][j+3] = true;
		}
		if (buf[i][j+1] == '.' && buf[i][j+2] == '.' && buf[i][j+3] == '.')
			can[i][j+3] = true;
	}
	for (int i = 0;i < 3;i++) for (int j = n;j < n+3;j++) if (can[i][j])
		return "YES";
	return "NO";
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		for (int i = 0;i < 5;i++) for (int j = 0;j < 105;j++)
			can[i][j] = buf[i][j] = 0;
		printf("%s\n", solve());
	}
	return 0;
}