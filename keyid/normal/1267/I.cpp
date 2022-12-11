#include <cstdio>
#include <random>
#include <algorithm>
using namespace std;
#define N 2000 + 5
#define INF 19260817

int Case, n, A[N], Ord[N], T[N];

int Cmp(int u, int v)
{
	printf("? %d %d\n", u, v);
	fflush(stdout);
	char s[9];
	scanf("%s", s);
	return s[0] == '<' ? u : v;
}

bool cmp(int u, int v)
{
	return Cmp(u, v) == u;
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i ++)
		{
			if (cmp(i, i + n))
				A[i] = i, A[i + n] = i + n;
			else A[i] = i + n, A[i + n] = i;
			Ord[i] = i;
		}
		sort(Ord + 1, Ord + n + 1, [](int u, int v) {
			return cmp(A[u], A[v]);
		});
		for (int i = 1; i <= n; i ++)
			T[i] = A[Ord[i]], T[i + n] = A[Ord[i] + n];
		sort(T + n + 1, T + 2 * n, cmp);
		for (int t = 1, i = 1, j = n + 1; t <= n; t ++)
		{
			if (cmp(T[i], T[j]))
				i ++;
			else j ++;
		}
		
		puts("!");
		fflush(stdout);
	}
	return 0;
}