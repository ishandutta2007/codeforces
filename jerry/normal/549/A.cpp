#include <bits/stdc++.h>
using namespace std;

char s[64][64];
int r, c, a;

int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0;i < r;i++)
		scanf("%s", s[i]);
	for (int i = 0;i < r-1;i++) for (int j = 0;j < c-1;j++)
	{
		bool have[256] = {};
		have[s[i][j]] = true;
		have[s[i][j+1]] = true;
		have[s[i+1][j]] = true;
		have[s[i+1][j+1]] = true;
		if (have['f'] && have['a'] && have['c'] && have['e'])
			a++;
	}
	printf("%d\n", a);
	return 0;
}