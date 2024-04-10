#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, f, k, cur, tot = 0;
	scanf("%d%d%d%d", &a, &b, &f, &k);
	cur = b;
	if((cur -= f) < 0)
	{
		puts("-1");
		return 0;
	}
	for(int i = 1; i < k; i++)
	{
		if(i & 1)
		{
			if((cur -= (a - f) * 2) < 0)
			{
				if((cur = b - (a - f) * 2) < 0)
				{
					puts("-1");
					return 0;
				}
				tot++;
			}
		}
		else
		{	
			if((cur -= f * 2) < 0)
			{
				if((cur = b - f * 2) < 0)
				{
					puts("-1");
					return 0;
				}
				tot++;
			}
		}
	}
	if(k & 1)
	{
		if((cur -= a - f) < 0)
		{
			if((cur = b - (a - f)) < 0)
			{
				puts("-1");
				return 0;
			}
			tot++;
		}
	}
	else
	{
		if((cur -= f) < 0)
		{
			if((cur = b - f) < 0)
			{
				puts("-1");
				return 0;
			}
			tot++;
		}
	}
	printf("%d\n", tot);
	return 0;
}