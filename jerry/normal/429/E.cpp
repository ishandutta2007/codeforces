#include <bits/stdc++.h>
using namespace std;

struct seg
{
	int l, r, id;
};

vector<pair<int, int> > ch[200005];
map<int, int> nd;
int asn[200005];
seg s[200005];
int m, n;

void preprocess()
{
	multiset<pair<int, int> > swp;
	for (int i = 0;i < n;i++)
	{
		swp.emplace(s[i].l, 1);
		swp.emplace(s[i].r+1, -1);
	}
	int tot = 0, lft = -1;
	while (!swp.empty())
	{
		int at = (*swp.begin()).first;
		while (!swp.empty() && (*swp.begin()).first == at)
		{
			tot += (*swp.begin()).second;
			swp.erase(swp.begin());
		}
		if (((tot&1)^1) && lft+1) { s[m] = {lft, at-1, m}; m++, lft = -1; }
		else if ((tot&1) && !(lft+1)) lft = at;
		int sz = nd.size();
		nd[at] = sz;
	}
	for (int i = 0;i < m;i++)
	{
		ch[nd[s[i].l]].emplace_back(nd[s[i].r+1], s[i].id);
		ch[nd[s[i].r+1]].emplace_back(nd[s[i].l], s[i].id);
	}
}

void dfs(int at)
{
	while (ch[at].size())
	{
		auto u(ch[at].back()); ch[at].pop_back();
		if (asn[u.second]) continue;
		asn[u.second] = ((int)(at<u.first))+1;
		dfs(u.first);
	}
}

int main()
{
	scanf("%d", &n); m = n;
	for (int i = 0;i < n;i++) scanf("%d%d", &s[i].l, &s[i].r), s[i].id = i;
	preprocess();
	for (auto u: nd) dfs(u.second);
	for (int i = 0;i < n;i++) printf("%d ", asn[i]-1);
	printf("\n");
	return 0;
}