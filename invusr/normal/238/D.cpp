#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

template <class T>
inline void tense(T &a, const T &b)
{
	if (b < a)
		a = b;
}

const int MaxN = 100005;
const int MaxM = 100005;
const int ND = 10;

int n, m;
char prog[MaxN];

int prev[MaxN];
int next[MaxN];

int occur_l[MaxN][ND];
int occur_r[MaxN][ND];
int occur[ND];
int book[MaxN];

inline void init_l()
{
	for (int i = 0; i <= n + 1; ++i)
		prev[i] = i - 1, next[i] = i + 1;
}

inline void remove_l(const int &x)
{
	prev[next[x]] = prev[x];
	next[prev[x]] = next[x];
}

inline bool is_dir(const char &c)
{
	return c == '<' || c == '>';
}

inline void prog_run(int now)
{
	int last = 0;
	char dir = '>';
	while (now > 0 && now <= n)
	{
		if (!book[now])
		{
			for (int i = 0; i < ND; ++i)
				occur_l[now][i] = occur[i];
			book[now] = 1;
		}

		if (is_dir(prog[now]))
		{
			dir = prog[now];
			if (is_dir(prog[last]))
			{
				if (book[last] == 2)
					remove_l(last);
				else
					prog[last] = 'R';
			}

			last = now;
		}
		else if (prog[now] >= '0' && prog[now] <= '9')
		{
			++occur[prog[last = now] - '0'];
			if (prog[now] > '0')
				--prog[now];
			else
			{
				if (book[now] == 2)
					remove_l(now);
				else
					prog[now] = 'R';
			}
		}

		if (dir == '<' && book[now] == 1)
		{
			book[now] = 2;
			for (int i = 0; i < ND; ++i)
				occur_r[now][i] = occur[i];

			if (prog[now] == 'R')
				remove_l(now);
		}

		if (dir == '<')
			now = prev[now];
		else
			now = next[now];
	}
}

inline void prog_run()
{
	init_l();
	while (next[0] != n + 1)
	{
		prog_run(next[0]);
		while (next[0] != n + 1 && book[next[0]])
			remove_l(next[0]);
	}
	for (int i = 0; i < ND; ++i)
		occur_l[n + 1][i] = occur[i];
}

inline void query(int l, int r)
{
	for (int i = 0; i < ND; ++i)
		occur[i] = occur_l[r + 1][i];
	if (book[l] == 2)
		for (int i = 0; i < ND; ++i)
			tense(occur[i], occur_r[l][i]);
	for (int i = 0; i < ND; ++i)
		printf("%d ", occur[i] - occur_l[l][i]);
	puts("");
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%s", prog + 1);

	prog_run();

	while (m--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		query(l, r);
	}

	return 0;
}