#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef pair<int, int> pa;
	typedef long long big;

	const int MAXN = 300000;
	char Ans[MAXN + 2];
	struct item
	{
		int id, a, b;
	} V[MAXN + 1];
	pa R[MAXN + 1];

	inline bool operator<(const item &a, const item &b) { return a.b < b.b; }

	void work()
	{
		int n, w;
		scanf("%d%d", &n, &w);
		for (int i = 1; i <= n; i++)
		{
			V[i].id = i;
			scanf("%d%d", &V[i].a, &V[i].b);
		}
		sort(V + 1, V + n + 1);
		int pos = 0;
		big ans = LLONG_MAX, cur = 0, curs = 0;
		set<pa> S;
		for (int i = 1; i <= n; i++)
		{
			S.insert({V[i].a, V[i].id});
			curs += V[i].a;
		}
		for (int i = 0; i <= n; i++)
		{
			if (i)
			{
				cur += V[i].a;
				auto it = S.find({V[i].a, V[i].id});
				if (it != S.end())
				{
					curs -= it->first;
					S.erase(it);
				}
				curs += V[i].b - V[i].a;
				S.insert({V[i].b - V[i].a, V[i].id});
			}
			while (S.size() > w - i)
			{
				auto it = prev(S.end());
				curs -= it->first;
				S.erase(it);
			}
			if (i + S.size() >= w && cur + curs < ans)
			{
				ans = cur + curs;
				pos = i;
			}
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= pos; i++)
		{
			Ans[V[i].id] = '1';
			R[i] = {V[i].b - V[i].a, V[i].id};
		}
		for (int i = pos + 1; i <= n; i++)
		{
			Ans[V[i].id] = '0';
			R[i] = {V[i].a, V[i].id};
		}
		sort(R + 1, R + n + 1);
		for (int i = 1; i <= w - pos; i++)
			Ans[R[i].second]++;
		puts(Ans + 1);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}