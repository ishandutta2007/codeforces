#include <bits/stdc++.h>
using namespace std;

struct node
{
	int s, f;
	int ch[27];
	node() : s(-1), f(-1)
	{
		for (int i = 0;i < 30;i++) ch[i] = -1;
	}
} all[4500000];

vector<pair<int, int> > sol;
char buf[2150];
int num_nodes;

int get_new_node(int lo, int hi)
{
	all[num_nodes].s = lo;
	all[num_nodes].f = hi;
	return num_nodes++;
}

int main()
{
	get_new_node(0, 0);
	scanf("%s", buf);
	for (int i = 0;buf[i];i++)
	{
		int at = 0;
		for (int j = i;buf[j];j++)
		{
			if (all[at].ch[buf[j]-'a'] == -1) all[at].ch[buf[j]-'a'] = get_new_node(i, j);
			at = all[at].ch[buf[j]-'a'];
		}
		at = 0;
		for (int j = i;j >= 0;j--)
		{
			if (all[at].ch[buf[j]-'a'] == -1) all[at].ch[buf[j]-'a'] = get_new_node(i, j);
			at = all[at].ch[buf[j]-'a'];
		}
	}
	scanf("%s", buf);
	int at = 0;
	for (int i = 0;buf[i];i++)
	{
		if (all[at].ch[buf[i]-'a'] == -1)
		{
			sol.emplace_back(all[at].s, all[at].f);
			at = 0;
		}
		at = all[at].ch[buf[i]-'a'];
		if (at == -1)
		{
			printf("-1\n");
			return 0;
		}
	}
	sol.emplace_back(all[at].s, all[at].f);
	printf("%d\n", sol.size());
	for (auto u: sol) printf("%d %d\n", u.first+1, u.second+1);
	return 0;
}