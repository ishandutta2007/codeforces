#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int MAXN = 100;
	char Str[MAXN + 10];

	void work()
	{
		int n, ans = 0;
		scanf("%d%s", &n, Str);
		for(int i = 2; (i << 1) <= n; i++)
			if(!memcmp(Str, Str + i, sizeof(char) * i))
				ans = i - 1;
		printf("%d\n", n - ans);
	}
}

int main()
{
	program::work();
	return 0;
}