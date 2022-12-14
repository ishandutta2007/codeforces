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

const int MaxN = 200005;
const int K = 3;

int n, m;
int pr[MaxN], a[MaxN], b[MaxN];

bool book[MaxN];

int cur[K], cnt[K];
int pos[K][MaxN * 2];

inline bool comparator(int i, int j)
{
	return pr[i] < pr[j];
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		pr[i] = getint();
	for (int i = 1; i <= n; ++i)
		a[i] = getint() - 1;
	for (int i = 1; i <= n; ++i)
		b[i] = getint() - 1;

	for (int i = 1; i <= n; ++i)
	{
		pos[a[i]][cnt[a[i]]++] = i;
		pos[b[i]][cnt[b[i]]++] = i;
	}

	sort(pos[0], pos[0] + cnt[0], comparator);
	sort(pos[1], pos[1] + cnt[1], comparator);
	sort(pos[2], pos[2] + cnt[2], comparator);

	m = getint();
	for (int i = 0; i < m; ++i)
	{
		int c = getint() - 1;
		while (cur[c] < cnt[c] && book[pos[c][cur[c]]])
			++cur[c];
		if (cur[c] == cnt[c])
			printf("-1 ");
		else
		{
			int x = pos[c][cur[c]++];
			book[x] = true;
			printf("%d ", pr[x]);
		}
	}

	return 0;
}