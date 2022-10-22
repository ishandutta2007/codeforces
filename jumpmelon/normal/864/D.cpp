#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 200000;
int A[MAXN + 10];
int Cnt[MAXN + 10];
int Q[MAXN + 10];
int Ch[MAXN + 10];

int main()
{
	int n, tot = 0;
	scanf("%d", &n);
	memset(Cnt + 1, 0, sizeof(int) * n);
	memset(Ch + 1, 0, sizeof(int) * n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		Cnt[A[i]]++;
	}
	for(int i = 1; i <= n; i++)
	{
		Ch[i] = Cnt[i] - 1;
		if(!Cnt[i])
			Q[++tot] = i;
	}
	for(int i = 1, j = 1; j <= tot; i++)
		if(Ch[A[i]] >= Cnt[A[i]]-- || (A[i] > Q[j] && Ch[A[i]]))
		{
			Ch[A[i]]--;
			A[i] = Q[j++];
		}
	printf("%d\n", tot);
	for(int i = 1; i <= n; i++)
		printf("%d ", A[i]);
	puts("");
	return 0;
}