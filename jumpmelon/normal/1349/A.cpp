#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	map<int, vector<int>> M;

	void work()
	{
		int n;
		scanf("%d", &n);
		for (int in = 0; in < n; in++)
		{
			int x;
			scanf("%d", &x);
			for (int p = 2; p <= x; p++)
			{
				if (p * p > x)
					p = x;
				if (!(x % p))
				{
					int c = 0;
					while (!(x % p))
					{
						x /= p;
						c++;
					}
					M[p].push_back(c);
				}
			}
		}
		big ans = 1;
		for (auto &&p : M)
		{
			auto V = p.second;
			if (V.size() >= n - 1)
			{
				sort(V.begin(), V.end(), greater<int>());
				for (int i = 0; i < V[n - 2]; i++)
					ans *= p.first;
			}
		}
		printf("%lld\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}