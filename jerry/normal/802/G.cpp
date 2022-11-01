#include <bits/stdc++.h>
using namespace std;

char buf[1005];
char req[] = "heidi";

int main()
{
	scanf("%s", buf);
	int j = 0;
	for (int i = 0;buf[i];i++)
		if (buf[i] == req[j])
		{
			j++;
			if (j == 5)
			{
				printf("YES\n");
				return 0;
			}
		}
	printf("NO\n");
	return 0;
}