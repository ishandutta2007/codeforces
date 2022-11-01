#include <cstdio>

char a[1024];
char b[1024];
int have[256];
int want[256];
int ans;
int n;
int m;

int main()
{
	scanf("%s%s", a, b);
	for (;a[n];n++)
		have[a[n]]++;
	for (;b[m];m++)
		want[b[m]]++;
	for (int i = 'a';i <= 'z';i++)
	{
		if (want[i] && !have[i])
		{
			printf("-1\n");
			return 0;
		}
		ans += (have[i]<want[i])?have[i]:want[i];
	}
	printf("%d\n", ans);
	return 0;
}