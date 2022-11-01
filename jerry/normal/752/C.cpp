#include <bits/stdc++.h>
using namespace std;

int n, ans;
char buf[200005];

int main()
{
	scanf("%d%s", &n, buf);
	for (int i = 0;i < n;)
	{
		char lr = 0, ud = 0;
		for (;i < n;i++)
		{
			if (buf[i] == 'L')
			{
				if (lr == 'R') break;
				lr = 'L';
			} else if (buf[i] == 'R')
			{
				if (lr == 'L') break;
				lr = 'R';
			} else if (buf[i] == 'U')
			{
				if (ud == 'D') break;
				ud = 'U';
			} else if (buf[i] == 'D')
			{
				if (ud == 'U') break;
				ud = 'D';
			} else
			{
				// :-) merry christmas
			}
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}