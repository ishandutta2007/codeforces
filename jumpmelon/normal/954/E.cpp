#include <bits/stdc++.h>

using namespace std;

namespace program
{
	typedef long double ld;

	const int MAXN = 200000;
	int A[MAXN + 10], T[MAXN + 10];
	pair<int, int> X[MAXN + 10], Y[MAXN + 10];

	void work()
	{
		int n, t, px = 0, py = 0;
		ld ans = 0, s1 = 0, s2 = 0;
		scanf("%d%d", &n, &t);
		for(int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &T[i]);
			if(T[i] <= t)
			{
				X[px++] = {t - T[i], A[i]};
				s1 += (ld)A[i] * (t - T[i]);
			}
			else
			{
				Y[py++] = {T[i] - t, A[i]};
				s2 += (ld)A[i] * (T[i] - t);
			}
		}
		sort(X, X + px);
		sort(Y, Y + py);
		for(int i = 0; i < px; i++)
		{
			ld c = min((ld)X[i].second, (ld)s2 / X[i].first);
			s2 -= c * X[i].first;
			ans += c;
		}
		for(int i = 0; i < py; i++)
		{
			ld c = min((ld)Y[i].second, (ld)s1 / Y[i].first);
			s1 -= c * Y[i].first;
			ans += c;
		}
		cout << setprecision(15) << fixed << ans << endl;
	}
}

int main()
{
	program::work();
	return 0;
}