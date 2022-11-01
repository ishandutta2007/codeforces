#include <bits/stdc++.h>
using namespace std;

int foobar[1000005];
map<int, int> foo;
int bar[1000005];
int n, m, a = 1;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", foobar+i);
		foo[foobar[i]]++;
	}
	for (auto u: foo) for (int v = u.first;v <= m;v += u.first)
		bar[v] += u.second;
	for (int i = 2;i <= m;i++) if (bar[i] > bar[a])
		a = i;
	printf("%d %d\n", a, bar[a]);
	for (int i = 0;i < n;i++) if (a%foobar[i] == 0)
		printf("%d ", i+1);
	printf("\n");
	return 0;
}