#include <bits/stdc++.h>
using namespace std;

char x[128][128];
vector<int> use;
int rem[128];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%s", x[i]);
	for (int i = 0;i < n;i++)
		scanf("%d", rem+i);
	while (true)
	{
		bool done = true;
		for (int i = 0;i < n;i++) if (rem[i] == 0)
		{
			for (int j = 0;j < n;j++) if (x[i][j] == '1')
				rem[j]--;
			done = false;
			use.push_back(i+1);
			break;
		}
		if (done) break;
	}
	printf("%d\n", use.size());
	for (int x: use) printf("%d ", x); printf("\n");
	return 0;
}