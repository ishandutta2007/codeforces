#include <bits/stdc++.h>
using namespace std;

struct sofa
{
	int x1, y1, x2, y2, l, r, t, b;
} s[100005];
set<int> hx[100005], hv;
int n, x, y, l, r, t, b;

#define foo(WHAT) \
	hv.clear(); \
	for (int i = 0;i < x;i++) \
	{ \
		for (int u: hx[i]) \
		{ \
			if (s[u].x1 != s[u].x2) s[u].WHAT = (int)(hv.size())-1; \
			else s[u].WHAT = (int)hv.size(); \
		} \
		for (int u: hx[i]) hv.insert(u); \
		hx[i].clear(); \
	}

int main()
{
	scanf("%d%d%d", &n, &x, &y); x++; y++;
	for (int i = 0;i < n;i++)
		scanf("%d%d%d%d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
	scanf("%d%d%d%d", &l, &r, &t, &b);

	for (int i = 0;i < n;i++) hx[s[i].x1].insert(i), hx[s[i].x2].insert(i);
	foo(l);
	for (int i = 0;i < n;i++) hx[x-s[i].x1].insert(i), hx[x-s[i].x2].insert(i);
	foo(r);
	for (int i = 0;i < n;i++) swap(s[i].x1, s[i].y1), swap(s[i].x2, s[i].y2);
	swap(x, y);
	for (int i = 0;i < n;i++) hx[s[i].x1].insert(i), hx[s[i].x2].insert(i);
	foo(t);
	for (int i = 0;i < n;i++) hx[x-s[i].x1].insert(i), hx[x-s[i].x2].insert(i);
	foo(b);

	for (int i = 0;i < n;i++) if (s[i].l == l && s[i].r == r && s[i].t == t && s[i].b == b)
	{
		printf("%d\n", i+1);
		return 0;
	}
	printf("-1\n");
	return 0;
}