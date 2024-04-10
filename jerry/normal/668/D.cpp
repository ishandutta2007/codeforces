#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
 #define D(x...) fprintf(stderr, x)
#else
 #define D(x...)
#endif

struct query
{
	int typ, tim, val;
} qu[1000005];
map<int, vector<int> > wh;
int ans[1000005];
int bit[1000005];
int num;
int n;

void compress()
{
	map<int, map<int, int> > hv;
	for (int i = 0;i < n;i++)
	{
		hv[qu[i].val][qu[i].tim];
		wh[qu[i].val].push_back(i);
	}
	for (auto it = hv.begin();it != hv.end();it++)
	{
		int _ = 1;
		for (auto it2 = it->second.begin();it2 != it->second.end();it2++)
			it2->second = _++;
	}
	for (int i = 0;i < n;i++)
		qu[i].tim = hv[qu[i].val][qu[i].tim];
}

void upd(int at, int va)
{
	for (;at <= num;at += at&-at)
		bit[at] += va;
}

int slv(int at)
{
	int ret = 0;
	for (;at;at -= at&-at)
		ret += bit[at];
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d%d%d", &qu[i].typ, &qu[i].tim, &qu[i].val);
	compress();
	for (int i = 0;i < n;i++)
	{
		D("%d %d %d\n", qu[i].typ, qu[i].tim, qu[i].val);
	}
	for (auto it = wh.begin();it != wh.end();it++)
	{
		num = it->second.size();
		for (int j = 0;j < num;j++)
		{
			int i = it->second[j];
			if (qu[i].typ == 1)
			{
				upd(qu[i].tim, 1);
			} else if (qu[i].typ == 2)
			{
				upd(qu[i].tim, -1);
			} else
			{
				ans[i] = slv(qu[i].tim);
			}
		}
		for (int j = 0;j <= num;j++)
			bit[j] = 0;
	}
	for (int i = 0;i < n;i++) if (qu[i].typ == 3)
		printf("%d\n", ans[i]);
	return 0;
}