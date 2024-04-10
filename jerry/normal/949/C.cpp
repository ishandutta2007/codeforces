#include <bits/stdc++.h>
using namespace std;

vector<int> ch[100005];
int upd[100005];
int n, m, h;

int sccid[100005];
bool ons[100005];
int idx[100005];
int lo[100005];
vector<int> S;
int numscc;

vector<int> sccto[100005];
vector<int> bel[100005];

int dfs(int at)
{
	static int I;
	S.push_back(at); ons[at] = true;
	lo[at] = idx[at] = ++I;
	for (int u: ch[at])
	{
		if (!idx[u]) lo[at] = min(lo[at], dfs(u));
		else if (ons[u]) lo[at] = min(lo[at], idx[u]);
	}
	if (lo[at] == idx[at])
	{
		int u = -1;
		while (u != at)
		{
			u = S.back(); S.pop_back();
			ons[u] = false;
			sccid[u] = numscc;
			bel[numscc].push_back(u);
		}
		numscc++;
	}
	return lo[at];
}

int main()
{
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0;i < n;i++) scanf("%d", upd+i);
	for (int i = 0;i < m;i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		--x, --y;
		if ((upd[x]+1)%h == upd[y]) ch[x].push_back(y);
		if ((upd[y]+1)%h == upd[x]) ch[y].push_back(x);
	}
	for (int i = 0;i < n;i++) if (!idx[i]) dfs(i);
	for (int i = 0;i < n;i++) for (int u: ch[i]) if (sccid[i] != sccid[u]) sccto[sccid[i]].push_back(sccid[u]);
	int best = -1;
	for (int i = 0;i < numscc;i++) if (sccto[i].size() == 0)
	{
		if (best == -1 || bel[i].size() < bel[best].size())
			best = i;
	}
	printf("%lu\n", bel[best].size());
	for (unsigned i = 0;i < bel[best].size();i++) printf("%d%c", bel[best][i]+1, " \n"[i+1==bel[best].size()]);
	return 0;
}