#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;
bool done[200005];
char buf[200005];
int to[200005];
int n;

int main()
{
	scanf("%s", buf); n = strlen(buf);
	for (int i = 0;i < n;i++) to[i] = -1;
	vector<int> hv[2];
	for (int i = 0;i < n;i++)
	{
		int w = buf[i] - '0';
		if (hv[w^1].size() > 0)
		{
			to[hv[w^1].back()] = i;
			hv[w^1].pop_back();
		} else if (w == 1)
		{
			printf("-1\n");
			return 0;
		}
		hv[w].push_back(i);
	}
	if (hv[1].size() > 0)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 0;i < n;i++) if (!done[i])
	{
		ans.emplace_back();
		for (int j = i;j != -1;j = to[j])
		{
			ans.back().push_back(j);
			done[j] = true;
		}
	}
	printf("%lu\n", ans.size());
	for (auto &u: ans)
	{
		printf("%lu", u.size());
		for (unsigned i = 0;i < u.size();i++) printf(" %d", u[i]+1);
		printf("\n");
	}
	return 0;
}