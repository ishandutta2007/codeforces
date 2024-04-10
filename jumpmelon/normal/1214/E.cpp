#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef pair<int, int> pa;

	const int MAXN = 100000;
	int V[(MAXN << 1) + 1];
	pa D[MAXN + 1];
	vector<int> G[(MAXN << 1) + 1];

	void work()
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &D[i].first);
			D[i].second = i;
		}
		sort(D + 1, D + n + 1, greater<pa>());
		int c = n;
		for (int i = 1; i <= n; i++)
			V[i] = D[i].second << 1;
		for (int i = 2; i <= c; i++)
			printf("%d %d\n", V[i - 1], V[i]);
		for (int i = 1; i <= n; i++)
		{
			if (i + D[i].first > c)
				V[++c] = (D[i].second << 1) - 1;
			printf("%d %d\n", V[i + D[i].first - 1], (D[i].second << 1) - 1);
		}
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}