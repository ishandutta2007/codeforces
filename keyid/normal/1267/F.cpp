#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int a, b, ka, kb, A[N], B[N], Deg[N << 1];
priority_queue<int, vector<int>, greater<int>> Q;

inline void Add(int u, int v)
{
	printf("%d %d\n", u, v);
	Deg[u] --, Deg[v] --;
	if (Deg[u] == 1)
		Q.push(u);
	if (Deg[v] == 1)
		Q.push(v);
}

int main()
{
	scanf("%d%d%d%d", &a, &b, &ka, &kb);
	if (ka >= b || kb >= a)
		puts("NO");
	else
	{
		for (int i = 1; i <= ka; i ++)
			scanf("%d", A + i);
		for (int i = ka + 1; i < b; i ++)
			A[i] = 1;
		ka = b - 1;
		
		for (int i = 1; i <= kb; i ++)
			scanf("%d", B + i);
		for (int i = kb + 1; i < a; i ++)
			B[i] = a + b;
		kb = a - 1;
		
		for (int i = 1; i <= ka; i ++)
			Deg[A[i]] ++;
		for (int i = 1; i <= kb; i ++)
			Deg[B[i]] ++;
		for (int i = 1; i <= a + b; i ++)
		{
			Deg[i] ++;
			if (Deg[i] == 1)
				Q.push(i);
		}
		
		puts("YES");
		for (int t = 1, i = 1, j = 1; t <= ka + kb; t ++)
		{
			int x = Q.top();
			Q.pop();
			if (x <= a)
				Add(x, B[j ++]);
			else Add(x, A[i ++]);
		}
		int retu = -1, retv = -1;
		for (int i = 1; i <= a; i ++)
			if (Deg[i] == 1)
				retu = i;
		for (int i = a + 1; i <= a + b; i ++)
			if (Deg[i] == 1)
				retv = i;
		printf("%d %d\n", retu, retv);
	}
	return 0;
}