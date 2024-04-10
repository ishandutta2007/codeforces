#include <bits/stdc++.h>
using namespace std;

char sol[1100][1100];

void solve(int n)
{
	if (n == 0) sol[0][0] = '+';
	else
	{
		solve(n-1);
		n = 1<<(n-1);
		for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
		{
			sol[i+n][j] = sol[i][j+n] = sol[i][j];
			sol[i+n][j+n] = sol[i][j]=='+'?'*':'+';
		}
	}
}

int main()
{
	int n; scanf("%d", &n);
	solve(n);
	for (int i = 0;i < (1<<n);i++) printf("%s\n", sol[i]);
	return 0;
}