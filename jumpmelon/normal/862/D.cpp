#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define ask { putchar('?'); putchar(' '); }
#define end { putchar('\n'); fflush(stdout); scanf("%d", &res); res -= d; }

using namespace std;

int main()
{
	int n, res, tot, d = 0;
	int f, lt, rt;
	scanf("%d", &n);
	ask
		for(int i = 1; i <= n; i++)
			putchar('0');
	end
	tot = res;
	ask
		putchar('1');
		for(int i = 2; i <= n; i++)
			putchar('0');
	end
	if(res < tot)
		f = 1;
	else
		f = 0;
	if(f)
		tot = n - tot;
	lt = 1; rt = n;
	while(lt < rt)
	{
		int mid = (lt + rt) >> 1;
		ask
			for(int i = 1; i < lt; i++)
				putchar(f ^ 1 + '0');
			for(int i = lt; i <= mid; i++)
				putchar(f + '0');
			for(int i = mid + 1; i <= n; i++)
				putchar(f ^ 1 + '0');
		end
		if(((res - (rt - mid) + tot) >> 1) <= 0)
		{
			d += mid - lt + 1 - ((res - (rt - mid) + tot) >> 1);
			tot = (tot - res + (rt - mid)) >> 1;
			lt = mid + 1;
		}
		else
		{
			
			d += rt - mid - ((tot - res + (rt - mid)) >> 1);
			tot = (res - (rt - mid) + tot) >> 1;
			rt = mid;
		}
	}
	if(f)
		printf("! %d %d\n", lt, 1);
	else
		printf("! %d %d\n", 1, lt);
	fflush(stdin);
	return 0;
}