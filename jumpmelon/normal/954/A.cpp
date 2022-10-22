#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int MAXN = 100;
	char Str[MAXN + 10];

	void work()
	{
		int n, tot = 0;
		scanf("%d%s", &n, Str);
		for(int i = 0; i + 1 < n; i++)
			if(Str[i] != Str[i + 1])
			{
				tot++;
				i++;
			}
		printf("%d\n", n - tot);
	}
}

int main()
{
	program::work();
	return 0;
}