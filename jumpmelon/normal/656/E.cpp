#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int MAXN = 10;
	int n, ans = 0, A[MAXN + 10][MAXN + 10];

	template <typename T>
	void JFOR(int a_i, int a_n, T a_fun)
	{ a_i < a_n ? a_fun(a_i), JFOR(a_i + 1, a_n, a_fun) : void(); }

	void work()	
	{
		scanf("%d", &n);
		JFOR(0, n, [](int i)										{
			JFOR(0, n, [i](int j)									{
				scanf("%d", &A[i][j]);								});});
		JFOR(0, n, [](int k)										{
			JFOR(0, n, [k](int i)									{
				JFOR(0, n, [i, k](int j)							{
					A[i][j] = min(A[i][j], A[i][k] + A[k][j]);		});});});
		JFOR(0, n, [](int i)										{
			JFOR(0, n, [i](int j)									{
				ans = max(ans, A[i][j]);							}); });
		printf("%d\n", ans);
	}
}

int main()
{
	program::work();
	return 0;
}