#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	const int N = 1e5 + 5;

	int n, m, A[N], B[N], Deg[N], Small[N];
	vector<int> E[N];

	inline int read()
	{
		int x = 0, f = 0, ch = getchar();
		while (!isdigit(ch))
			f |= (ch == '-'), ch = getchar();
		while (isdigit(ch))
			x = x * 10 + ch - '0', ch = getchar();
		return f ? -x : x;
	}

	void work()
	{
		n = read(), m = read();
		for (int i = 1; i <= m; i++)
		{
			int u = read(), v = read();
			if (u > v)
				swap(u, v);
			E[u].push_back(v);
			E[v].push_back(u);
			++A[v], ++B[u];
			++Deg[u], ++Deg[v];
		}
		for (int i = 1; i <= n; i++)
			sort(E[i].begin(), E[i].end());
		memcpy(Small, A, sizeof(int[n + 1]));
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			ans += (ll)A[i] * B[i];
		printf("%lld\n", ans);
		for (int q = read(); q; q--)
		{
			int u = read();
			for (int i = Small[u], sz = E[u].size(); i < sz; i++)
			{
				int v = E[u][i];
				E[v].push_back(u);
				ans -= (ll)A[v] * B[v];
				A[v]--, B[v]++;
				ans += (ll)A[v] * B[v];
			}
			ans -= (ll)A[u] * B[u];
			A[u] = Deg[u], B[u] = 0;
			Small[u] = 0;
			E[u].clear();
			printf("%lld\n", ans);
		}	
	}
}

int main()
{
	TYC::work();
	return 0;
}