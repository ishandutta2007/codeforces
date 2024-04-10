#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int w, m, i, a, b;
	bool operator< (const edge& oth)
	{
		if (w != oth.w)
			return (w < oth.w);
		return (m > oth.m);
	}
} e[100005];

int f[100005];
int n, m;

bool cmp(const edge& a, const edge& b)
{
	return (a.i < b.i);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;i++)
	{
		scanf("%d%d", &e[i].w, &e[i].m);
		e[i].i = i;
	}
	sort(e, e+m);
	for (int i = 0, _ = 2;i < m;i++) if (e[i].m)
	{
		e[i].a = 1, e[i].b = _;
		f[_++] = e[i].w;
	}
	int p = 3, q = 2;
	for (int i = 0;i < m;i++) if (!e[i].m)
	{
		if (e[i].w < f[p])
		{
			printf("-1\n");
			return 0;
		}
		e[i].a = p, e[i].b = q;
		if (++q == p)
			p++, q = 2;
	}
	sort(e, e+m, cmp);
	for (int i = 0;i < m;i++)
		printf("%d %d\n", e[i].a, e[i].b);
	return 0;
}