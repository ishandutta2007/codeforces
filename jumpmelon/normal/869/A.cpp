#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2000, MAXX = 2000000;
int X[MAXN + 10], Y[MAXN + 10];
bool Vis[MAXX + 10];

int main()
{
	int n, tot = 0;
	scanf("%d", &n);
	memset(Vis, 0, sizeof(Vis));
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &X[i]);
		Vis[X[i]] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &Y[i]);
		Vis[Y[i]] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if((X[i] ^ X[j]) <= MAXX && Vis[X[i] ^ X[j]])
				tot++;
	if(tot & 1)
		puts("Koyomi");
	else
		puts("Karen");
	return 0;
}