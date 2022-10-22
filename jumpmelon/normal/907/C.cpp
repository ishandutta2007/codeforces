#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int MAXL = 100000;
	const int M = 26, S = 1 << M;
	char Cmd[10], Str[MAXL + 10];

	int val(int x)
	{
		for(int i = 0; i < M; i++)
			if((1 << i) == x)
				return i;
		return -1;
	}

	void work()
	{
		int n, s = S - 1, t = 0, ans = 0;
		scanf("%d", &n);
		while(n--)
		{
			int v = val(s & ~t);
			scanf("%s%s", Cmd, Str);
			if(Cmd[0] == '.')
			{
				for(char *ch = Str; *ch; ch++)
					t |= 1 << (*ch - 'a');
			}
			else if(Cmd[0] == '!')
			{
				if(~v)
					ans++;
				else
				{
					int tmp = 0;
					for(char *ch = Str; *ch; ch++)
						tmp |= 1 << (*ch - 'a');
					s &= tmp;
				}
			}
			else if(Cmd[0] == '?')
			{
				if(v == Str[0] - 'a')
					break;
				if(~v)
					ans++;
				else
					t |= 1 << (Str[0] - 'a');
			}
		}
		printf("%d\n", ans);
	}
}

int main()
{
	program::work();
	return 0;
}