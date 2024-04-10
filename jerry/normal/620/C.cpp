#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > sol;
set<int> vis;
int n;

int main()
{
	scanf("%d", &n);
	int l = -1;
	for (int i = 0;i < n;i++)
	{
		int x; scanf("%d", &x);
		if (vis.find(x) != vis.end())
		{
			vis.clear();
			sol.emplace_back(l+1, i);
			l = i;
		} else vis.insert(x);
	}
	if (sol.size())
	{
		printf("%d\n", sol.size());
		sol.back().second = n-1;
		for (auto u: sol) printf("%d %d\n", u.first+1, u.second+1);
	} else printf("-1\n");
	return 0;
}