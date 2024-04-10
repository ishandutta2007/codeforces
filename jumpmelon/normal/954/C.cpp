#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int MAXN = 200000;
	int A[MAXN + 10];

	void work()
	{
		int n, y = -1, mx = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &A[i]);
			if(A[i] > mx)
				mx = A[i];
		}
		for(int i = 1; i < n; i++)
		{
			int t = abs(A[i] - A[i + 1]);
			if(t != 1)
			{
				if(y == -1)
					y = t;
				else if(y != t)
					goto fail;
			}
		}
		if(y == 0)
			goto fail;
		if(y == -1)
			y = mx;
		mx = 0;
		for(int i = 1; i <= n; i++)
			if((A[i] - 1) / y + 1 >= mx)
				mx = (A[i] - 1) / y + 1;
		for(int i = 1; i < n; i++)
			if(abs(A[i] - A[i + 1]) == 1 && (A[i] - 1) / y != (A[i + 1] - 1) / y)
				goto fail;
		puts("YES");
		printf("%d %d\n", mx, y);
		return;
	fail:
		puts("NO");
	}
}

int main()
{
	program::work();
	return 0;
}