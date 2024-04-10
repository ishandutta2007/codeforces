#include <cstdio>
#include <algorithm>

using namespace std;

int t[50000][5];
int read[5];
int n;
int p;

int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 0;i < n;i++) for (int j = 0;j < p;j++)
		scanf("%d", &t[i][j]);
	for (int i = 0;i < n;i++)
	{
		int ans = 0;
		for (int j = 0;j < p;j++)
			ans = read[j] = max(read[j], ans) + t[i][j];
		printf("%d ", ans);
	}
	return 0;
}