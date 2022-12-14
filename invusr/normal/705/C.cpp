#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tense(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

const int MaxN = 300005;

int n, q, m = 0, last = 0;
vector<int> msg[MaxN];

int outcome = 0;
bool book[MaxN];

int orz[MaxN];

int main()
{
	scanf("%d%d", &n, &q);
	while (q--)
	{
		int type, x;
		scanf("%d%d", &type, &x);

		if (type == 3)
		{
			while (last < x)
			{
				++last;
				if (!book[last])
				{
					book[last] = true;
					--outcome;
				}
			}
		}
		else if (type == 1)
		{
			book[++m] = false;
			++outcome;
			msg[x].push_back(m);
		}
		else
		{
			int l = msg[x].size();
			for (int i = orz[x]; i < l; ++i)
			{
				int y = msg[x][i];
				if (!book[y])
				{
					book[y] = true;
					--outcome;
				}
			}
			orz[x] = l;
		}
		printf("%d\n", outcome);
	}

	return 0;
}