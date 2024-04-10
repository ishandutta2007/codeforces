#include <bits/stdc++.h>
using namespace std;

set<int> have;
int n, m; vector<int> ans;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		int x; scanf("%d", &x);
		have.insert(x);
	}
	for (int i = 1;m >= i;i++)
		if (have.empty() || *have.begin() != i)
		{
			m -= i;
			ans.push_back(i);
		} else if (!have.empty() && *have.begin() == i)
			have.erase(have.begin());
	printf("%d\n", ans.size());
	for (int u: ans) printf("%d ", u);
	printf("\n");
	return 0;
}