#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	int n, n1, n2, c1 = 0, c2 = 0;
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		if(c1 == 0)
		{
			n1 = x;
			c1 = 1;
		}
		else if(x == n1)
			c1++;
		else if(c2 == 0)
		{
			n2 = x;
			c2 = 1;
		}
		else if(x == n2)
			c2++;
		else
		{
			puts("NO");
			return 0;
		}
	}
	if(c1 == c2)
	{
		puts("YES");
		printf("%d %d\n", n1, n2);
	}
	else
		puts("NO");
	return 0;
}