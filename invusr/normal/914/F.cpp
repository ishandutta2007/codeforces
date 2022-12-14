#include <bits/stdc++.h>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

inline int nextChar()
{
	char c = '1';
	while (c < 'a' || c > 'z')
		c = getchar();
	return c - 'a';
}

const int MaxN = 100000;
const int NLet = 26;

int n, m;
char s[MaxN + 2], t[MaxN + 2];

bitset<MaxN + 1> mask[NLet];
bitset<MaxN + 1> all, res;

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);

	for (int i = 1; i <= n; ++i)
		mask[s[i] - 'a'].set(i);
	for (int i = 0; i < n; ++i)
		all.set(i);

	cin >> m;
	while (m--)
	{
		int type = getint();
		if (type == 1)
		{
			int x = getint(), c = nextChar();
			mask[s[x] - 'a'][x] = 0;
			mask[c][x] = 1;
			s[x] = c + 'a';
		}
		else
		{
			int l = getint();
			int r = getint();
			scanf("%s", t + 1);

			int k = strlen(t + 1);
			if (r - l + 1 < k)
			{
				puts("0");
				continue;
			}

			res = all;
			for (int i = 1; i <= k; ++i)
				res &= mask[t[i] - 'a'] >> i;

			int a = (res >> (l - 1 + 0)).count();
			int b = (res >> (r - k + 1)).count();
			printf("%d\n", a - b);
		}
	}

	return 0;
}