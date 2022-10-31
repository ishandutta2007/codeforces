// Hydro submission #61665fcd35b03a4e0189cb6d@1634099150413
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
 
int main()
{
	int T, n, i, j;
	char a[110];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", a);
		int flag = 1;
		for (i = 0, j = n - 1; i < n; i++, j--)
		{
			if (abs(a[i] - a[j]) != 2 && a[i] != a[j])
			{
				flag = 0;
			}
		}
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}