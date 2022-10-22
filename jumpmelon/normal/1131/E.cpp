#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXL = 100000;
	int F[26];
	char S[MAXL + 1];

	void work()
	{
		int n;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%s", S);
			int m = strlen(S), a = 0, b = m - 1;
			while (a < m && S[a] == S[0])
				a++;
			while (b >= 0 && S[b] == S[m - 1])
				b--;
			if (a == m)
			{
				for (int i = 0; i < 26; i++)
					if (i != S[0] - 'a' && F[i] > 1)
						F[i] = 1;
				F[S[0] - 'a'] += (F[S[0] - 'a'] + 1) * m;
			}
			else
			{
				for (int i = 0; i < 26; i++)
					if (F[i] > 1)
						F[i] = 1;
				if (S[0] != S[m - 1] || F[S[0] - 'a'])
				{
					F[S[0] - 'a'] += a;
					F[S[m - 1] - 'a'] += m - 1 - b;
				}
			}
			for (int i = 0, j; i < m; i = j)
			{
				j = i;
				while (j < m && S[i] == S[j])
					j++;
				if (j - i > F[S[i] - 'a'])
					F[S[i] - 'a'] = j - i;
			}
		}
		int ans = 0;
		for (int i = 0; i < 26; i++)
			if (F[i] > ans)
				ans = F[i];
		printf("%d\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}