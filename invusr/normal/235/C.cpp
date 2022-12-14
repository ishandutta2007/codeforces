#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxNL = 1000005;

int tex_n, pat_n, q_n;
char tex[MaxNL];
char pat[MaxNL * 2];

namespace suffix_automation
{
	const int MaxTN = MaxNL * 2;
	const int NLet = 26;

	int tn, last;
	int next[MaxTN][NLet];
	int fail[MaxTN];
	int length[MaxTN], weight[MaxTN];

	int mark = 0;
	int book[MaxTN];

	inline void sa_init()
	{
		last = tn = 1;
		mark = 0;
	}

	inline void sa_extend(const int &c)
	{
		int p = last;
		int np = last = ++tn;
		length[np] = length[p] + 1;
		weight[np] = 1;

		while (p && !next[p][c])
			next[p][c] = np, p = fail[p];
		if (!p)
			fail[np] = 1;
		else
		{
			int q = next[p][c];
			if (length[q] == length[p] + 1)
				fail[np] = q;
			else
			{
				int nq = ++tn;
				length[nq] = length[p] + 1;
				for (int i = 0; i < NLet; ++i)
					next[nq][i] = next[q][i];
				fail[nq] = fail[q];
				fail[np] = fail[q] = nq;
				while (next[p][c] == q)
					next[p][c] = nq, p = fail[p];
			}
		}
	}

	inline void sa_count()
	{
		static int pre[MaxNL];
		static int ver[MaxTN];
		for (int i = 2; i <= tn; ++i)
			++pre[length[i]];
		for (int i = 1; i <= tex_n; ++i)
			pre[i] += pre[i - 1];
		for (int i = 2; i <= tn; ++i)
			ver[pre[length[i]]--] = i;
		for (int i = tn - 1; i >= 1; --i)
			weight[fail[ver[i]]] += weight[ver[i]];
	}

	inline int sa_query()
	{
		++mark;

		int res = 0;
		int now = 1, len = 0;
		for (int i = 1; i <= pat_n * 2; ++i)
		{
			int c = pat[i] - 'a';
			while (now && !next[now][c])
				len = length[now = fail[now]];
			if (!now)
				now = 1, len = 0;
			else
				now = next[now][c], ++len;

			while (length[fail[now]] >= pat_n)
				len = length[now = fail[now]];
			if (len >= pat_n && book[now] != mark)
				res += weight[now], book[now] = mark;
		}

		return res;
	}
}
using namespace suffix_automation;

int main()
{
	scanf("%s", tex + 1);
	tex_n = strlen(tex + 1);

	sa_init();
	for (int i = 1; i <= tex_n; ++i)
		sa_extend(tex[i] - 'a');
	sa_count();

	scanf("%d", &q_n);
	while (q_n--)
	{
		scanf("%s", pat + 1);
		pat_n = strlen(pat + 1);
		for (int i = 1; i <= pat_n; ++i)
			pat[i + pat_n] = pat[i];

		printf("%d\n", sa_query());
	}

	return 0;
}