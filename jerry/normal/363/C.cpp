#include <cstdio>
#include <cstring>

int next[200010];
char x[200010];
int n;

int main()
{
	scanf("%s", x);
	n = strlen(x);
	for (int i = 0;i < 200010;i++)
		next[i] = i+1;
	for (int i = 0;next[next[i]]<n;)
	{
		if (x[i]==x[next[i]] && x[i]==x[next[next[i]]])
			next[i] = next[next[i]];
		else
			i = next[i];
	}
	for (int i = 0;next[next[next[i]]]<n;)
	{
		if (x[i]==x[next[i]] && x[next[next[i]]]==x[next[next[next[i]]]])
			next[next[i]] = next[next[next[i]]];
		else
			i = next[i];
	}
	for (int i = 0;i < n;i=next[i])
		printf("%c", x[i]);
	printf("\n");
	return 0;
}