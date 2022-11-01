#include <bits/stdc++.h>
using namespace std;

int occ[30];
int n;

int main()
{
	scanf("%d", &n);
	bool flag = false, zero = false;
	for (int i = 0;i < n;i++)
	{
		scanf("%d", occ+i);
		if (occ[i]&1)
		{
			if (flag)
				zero = true;
			else
				flag = true;
		}
	}
	if (zero)
	{
		printf("0\n");
		for (int i = 0;i < n;i++) for (int j = 0;j < occ[i];j++)
			printf("%c", 'a'+i);
		printf("\n");
		return 0;
	}
	if (flag)
	{
		int ans = occ[0];
		for (int i = 1;i < n;i++) ans = __gcd(ans, occ[i]);
		printf("%d\n", ans);
		for (int x = 0;x < ans;x++)
		{
			for (int i = 0;i < n;i++) for (int j = 0;j < occ[i]/ans/2;j++)
				printf("%c", 'a'+i);
			for (int i = 0;i < n;i++) if (occ[i]&1)
				printf("%c", 'a'+i);
			for (int i = n-1;i >= 0;i--) for (int j = 0;j < occ[i]/ans/2;j++)
				printf("%c", 'a'+i);
		}
		printf("\n");
		return 0;
	}
	int ans = occ[0];
	for (int i = 1;i < n;i++) ans = __gcd(ans, occ[i]);
	printf("%d\n", ans);
	for (int x = 0;x < ans;x+=2)
	{
		for (int i = 0;i < n;i++) for (int j = 0;j < occ[i]/ans;j++)
			printf("%c", i+'a');
		for (int i = n-1;i >= 0;i--) for (int j = 0;j < occ[i]/ans;j++)
			printf("%c", i+'a');
	}
	printf("\n");
	return 0;
}