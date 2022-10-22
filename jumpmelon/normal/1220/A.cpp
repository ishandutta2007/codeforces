#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
char s[N];

int main()
{
	scanf("%d%s", &n, s + 1);
	int c1 = 0, c0 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'n')
			++c1;
		if (s[i] == 'z')
			++c0;
	}
	while (c1--)
		printf("1 ");
	while (c0--)
		printf("0 ");
	return 0;
}