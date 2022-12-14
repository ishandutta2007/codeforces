#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200005;
const int MaxLogM = 32;
const int MaxTN = MaxN * MaxLogM;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

int tn = 0;
int next[MaxTN][2];
int size[MaxTN];

inline void insert(int w)
{
	int x = 0;
	for (int k = 29; k >= 0; --k)
	{
		int b = w >> k & 1;
		if (!next[x][b])
			next[x][b] = ++tn;
		x = next[x][b];
		++size[x];
	}
}

inline void remove(int w)
{
	int x = 0;
	for (int k = 29; k >= 0; --k)
	{
		int b = w >> k & 1;
		x = next[x][b];
		--size[x];
	}
}

inline int query(int w)
{
	int x = 0, res = 0;
	for (int k = 29; k >= 0; --k)
	{
		int b = ~w >> k & 1;
		if (size[next[x][b]])
			x = next[x][b], res |= 1 << k;
		else
			x = next[x][!b];
	}
	return res;
}

int main()
{
	insert(0);

	int q = getint();
	while (q--)
	{
		char c;
		while ((c = getchar()) != '+' && c != '-' && c != '?');

		if (c == '+')
			insert(getint());
		else if (c == '-')
			remove(getint());
		else
			printf("%d\n", query(getint()));
	}

	return 0;
}