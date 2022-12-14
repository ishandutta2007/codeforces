#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5000;

int n;
char s[MaxN + 2];

int vis[MaxN + 1][MaxN + 1];

int main()
{
	cin >> s + 1;
	n = strlen(s + 1);

	for (int i = 1; i <= n; ++i)
	{
		int v = 0;
		for (int j = i; j <= n; ++j)
		{
			v += s[j] == ')' ? -1 : 1;
			if (v < 0)
				break;

			++vis[i][j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		int v = 0;
		for (int j = i; j; --j)
		{
			v += s[j] == '(' ? -1 : 1;
			if (v < 0)
				break;

			++vis[j][i];
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			res += ((i ^ j) & 1) && (vis[i][j] == 2);

	cout << res << endl;

	return 0;
}