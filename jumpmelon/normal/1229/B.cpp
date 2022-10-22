#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	const int N = 1e5 + 5, B = 17, mod = 1e9 + 7;

	int n, Fa[B][N], Dep[N];
	ll V[N], Gcd[B][N];
	vector<int> E[N];

	ll gcd(const ll a, const ll b) { return !b ? a : gcd(b, a % b); }

	void dfs(const int u, const int f)
	{
		Gcd[0][u] = gcd(V[u], V[f]);
		Dep[u] = Dep[Fa[0][u] = f] + 1;
		for (int i = 1; i < B && Fa[i - 1][u]; i++)
		{
			Fa[i][u] = Fa[i - 1][Fa[i - 1][u]];
			Gcd[i][u] = gcd(Gcd[i - 1][u], Gcd[i - 1][Fa[i - 1][u]]);
		}	
		for (int v : E[u])
			if (v != f)
				dfs(v, u);
	}

	inline int find(int x, const ll g)
	{
		for (int i = B - 1; ~i; i--)
			if (Fa[i][x] && (g == 0 ? Gcd[i][x] == 0 : Gcd[i][x] % g == 0))
				x = Fa[i][x];
		return Fa[0][x];
	}

	void work()
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &V[i]);
		for (int i = 1, u, v; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		dfs(1, 0);
		int ans = 0;
		for (int v = 1; v <= n; v++)
		{
			int u = v, t;
			ll g = V[v];
			while (u)
			{
				t = find(v, g);
				ans = (ans + g * (Dep[u] - Dep[t]) % mod) % mod;
				g = gcd(g, V[u = t]);
			}
		}
		printf("%d\n", ans);
	}
}

int main()
{
	TYC::work();
	return 0;
}