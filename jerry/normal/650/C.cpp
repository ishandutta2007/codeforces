#include <bits/stdc++.h>
using namespace std;

#define nom(x, y) ( (x)*(c)+(y) )

namespace UF
{
	int par[1000005], ran[1000005];
	int n;
	void init(int N)
	{
		n = N;
		for (int i = 0;i < n;i++) par[i] = i;
	}
	int getpar(int at)
	{
		return (par[at]==at)?at:par[at]=getpar(par[at]);
	}
	void merge(int a, int b)
	{
		a = getpar(a), b = getpar(b);
		if (a != b)
		{
			if (ran[a] > ran[b])
				par[b] = a;
			else
			{
				par[a] = b;
				if (ran[a] == ran[b])
					ran[b]++;
			}
		}
	}
};

vector<int> ch[1000005];
int assign[1000005];
int arr[1000005];
int ind[1000005];
int r, c;

int& ar(int x, int y) { return arr[nom(x, y)]; }

int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0;i < r;i++) for (int j = 0;j < c;j++) scanf("%d", &ar(i, j));
	UF::init(r*c);
	for (int i = 0;i < r;i++)
	{
		set<pair<int, int> > s;
		for (int j = 0;j < c;j++) s.emplace(ar(i, j), j);
		int lval = (*s.begin()).first, wh = (*s.begin()).second;
		for (s.erase(s.begin());!s.empty();s.erase(s.begin()))
		{
			if ((*s.begin()).first == lval) UF::merge(nom(i, wh), nom(i, (*s.begin()).second));
			else
			{
				ch[nom(i, wh)].push_back(nom(i, (*s.begin()).second));
				lval = (*s.begin()).first;
				wh = (*s.begin()).second;
			}
		}
	}
	for (int j = 0;j < c;j++)
	{
		set<pair<int, int> > s;
		for (int i = 0;i < r;i++) s.emplace(ar(i, j), i);
		int lval = (*s.begin()).first, wh = (*s.begin()).second;
		for (s.erase(s.begin());!s.empty();s.erase(s.begin()))
		{
			if ((*s.begin()).first == lval) UF::merge(nom(wh, j), nom((*s.begin()).second, j));
			else
			{
				ch[nom(wh, j)].push_back(nom((*s.begin()).second, j));
				lval = (*s.begin()).first;
				wh = (*s.begin()).second;
			}
		}
	}
	for (int i = 0;i < r;i++) for (int j = 0;j < c;j++)
	{
		int id = nom(i, j), gp = UF::getpar(id);
		if (gp != id) for (int u: ch[id])
			ch[gp].push_back(u);
	}
	for (int i = 0;i < r;i++) for (int j = 0;j < c;j++)
	{
		int id = nom(i, j), gp = UF::getpar(id);
		if (gp == id)
		{
			for (int& u: ch[gp]) u = UF::getpar(u);
			sort(ch[gp].begin(), ch[gp].end());
			ch[gp].resize(unique(ch[gp].begin(), ch[gp].end())-ch[gp].begin());
			for (int u: ch[gp]) ind[u]++;
		} else ind[id] = -1;
	}
	queue<int> q;
	for (int i = 0;i < r*c;i++) if (ind[i] == 0) q.push(i);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int v: ch[u])
		{
			assign[v] = max(assign[v], assign[u]+1);
			if (--ind[v] == 0)
				q.push(v);
		}
	}
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++) printf("%d ", assign[UF::getpar(nom(i, j))]+1);
		printf("\n");
	}
	return 0;
}