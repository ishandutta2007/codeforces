#include <bits/stdc++.h>
using namespace std;

vector<int> ch[200005];
bool dp[200005][2];
bool vi[200005][2];
vector<int> ans;
int n;

bool slv(int at, int rem, int par)
{
	if (vi[at][rem]) return dp[at][rem];
	vi[at][rem] = true;
	int cnt[4] = {};
	for (int u: ch[at]) if (u != par)
	{
		int a = slv(u, 0, at);
		a += 2*slv(u, 1, at);
		cnt[a]++;
	}
	if (cnt[0]) return dp[at][rem] = false;
	if ((ch[at].size()-rem)&1)
	{
		if ((cnt[1]%2 == 0) && cnt[3] == 0) return dp[at][rem] = false;
		return dp[at][rem] = true;
	} else
	{
		if ((cnt[1]&1) && cnt[3] == 0) return dp[at][rem] = false;
		return dp[at][rem] = true;
	}
}

void bt(int at, int rem, int par)
{
	vector<int> all[4];
	for (int u: ch[at]) if (u != par)
	{
		int a = slv(u, 0, at);
		a += 2*slv(u, 1, at);
		all[a].push_back(u);
	}
	if ((ch[at].size()-rem)&1)
	{
		for (int u: all[1]) bt(u, 0, at);
		if (all[1].size()%2 == 0)
		{
			bt(all[3].back(), 0, at);
			all[3].pop_back();
		}
		printf("%d\n", at+1);
		for (int u: all[2]) bt(u, 1, at);
		for (int u: all[3]) bt(u, 1, at);
	} else
	{
		for (int u: all[1]) bt(u, 0, at);
		if (all[1].size()&1)
		{
			bt(all[3].back(), 0, at);
			all[3].pop_back();
		}
		printf("%d\n", at+1);
		for (int u: all[2]) bt(u, 1, at);
		for (int u: all[3]) bt(u, 1, at);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		int p; scanf("%d", &p);
		if (p)
		{
			--p;
			ch[p].push_back(i);
			ch[i].push_back(p);
		}
	}
	for (int i = 0;i < n;i++) if (ch[i].size() <= 1)
	{
		if (slv(i, 0, -1))
		{
			printf("YES\n");
			bt(i, 0, -1);
		} else printf("NO\n");
		return 0;
	}
	return 0;
}