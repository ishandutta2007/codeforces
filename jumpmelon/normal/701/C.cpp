#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int MAXN = 100000;
	char Str[MAXN + 10];
	int Cnt[CHAR_MAX + 1];

	void work()
	{
		int n, m = 0, cur = 0, ans = INT_MAX;
		scanf("%d%s", &n, Str);
		for(int i = 0; i < n; i++)
			if(!Cnt[Str[i]]++)
				m++;
		memset(Cnt, 0, sizeof(Cnt));
		for(int i = 0, t = 0; i < n; i++)
		{
			if(!Cnt[Str[i]]++)
				cur++;
			while(t < i && Cnt[Str[t]] > 1)
				Cnt[Str[t++]]--;
			if(cur >= m)
				ans = min(ans, i - t + 1);
		}
		printf("%d\n", ans);
	}
}

int main()
{
	program::work();
	return 0;
}