#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100, MAXD = 2000;
struct item
{
	int id, t, d, p;
	bool operator<(const item &x) const
	{
		return d < x.d;
	}
}A[MAXN + 10];
int Dp[MAXN + 10][MAXD + 10];
bool U[MAXN + 10][MAXD + 10];
int Item[MAXN + 10];

int main()
{
	int n, tot = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		A[i].id = i;
		scanf("%d%d%d", &A[i].t, &A[i].d, &A[i].p);
	}
	sort(A + 1, A + n + 1);
	memset(Dp[n + 1], 0, sizeof(Dp[n + 1]));
	memset(U, 0, sizeof(U));
	for(int i = n; i >= 1; i--)
	{
		memcpy(Dp[i], Dp[i + 1], sizeof(Dp[i]));
		for(int j = 0; j < A[i].d - A[i].t; j++)
			if(Dp[i + 1][j + A[i].t] + A[i].p > Dp[i][j])
			{
				Dp[i][j] = Dp[i + 1][j + A[i].t] + A[i].p;
				U[i][j] = 1;
			}
	}
	int i = 1, j = 0;
	while(i <= n)
	{
		if(U[i][j])
		{
			Item[++tot] = A[i].id;
			j += A[i].t;
		}
		i++;
	}
	printf("%d\n", Dp[1][0]);
	printf("%d\n", tot);
	//sort(Item + 1, Item + tot + 1);
	for(int i = 1; i <= tot; i++)
		printf("%d ", Item[i]);
	puts("");
	return 0;
}