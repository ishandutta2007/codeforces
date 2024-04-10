// What's the point of it anyway?
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, q, A[N];
int main()
{
	scanf("%d", &q);
	for (; q; q --)
	{
		scanf("%d", &n); A[0] = 0;
		for (int i = 1; i <= n; i ++)
			scanf("%d", &A[i]), A[0] ^= A[i];
		if (!A[0])
			{printf("DRAW\n"); continue;}
		int hb = 31 - __builtin_clz(A[0]), c = 0;
		for (int i = 1; i <= n; i ++)
			if (A[i] >> hb & 1)
				c ++;
		if (c % 4 == 3 && (n - c) % 2 == 0)
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}