#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	const int N = 7010;
	
	ll A[N];
	int n, m, V[N], G[N][N], cnt[N], vis[N];

	void work()
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &A[i]);
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &V[i]), ans += V[i];
		for (int i = 1; i <= n; i++)	
			for (int j = i + 1; j <= n; j++)
			{
				G[i][j] = (A[i] & A[j]) != A[i];
				G[j][i] = (A[j] & A[i]) != A[j];
				cnt[i] += G[i][j];
				cnt[j] += G[j][i];
			}
		for (int res = n; res; res--)
		{
			int id = 0;
		   	for (int i = 1; i <= n; i++)
				if (!vis[i] && cnt[i] == res - 1)
				{
					id = i;
					break;
				}
			if (!id)
				break;
			vis[id] = 1;
			ans -= V[id];
			for (int i = 1; i <= n; i++)
				if (!vis[i])
					cnt[i] -= G[i][id];
		}
		printf("%lld\n", ans);
	}
}

int main()
{
	TYC::work();
	return 0;
}