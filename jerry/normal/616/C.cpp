#include <bits/stdc++.h>
using namespace std;

const int d[] = {-1, 0, 1, 0, -1};
int id[1005][1005], sz[1000005], n, m, _;
char mp[1005][1005];

void dfs(int r, int c, int $)
{
	if (r < 0 || c < 0) return;
	if (mp[r][c] != '.') return;
	if (id[r][c]) return;
	sz[id[r][c] = $]++;
	for (int i = 0;i < 4;i++)
		dfs(r+d[i], c+d[i+1], $);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) scanf("%s", mp[i]);
	for (int i = 0;i < n;i++) for (int j = 0;j < m;j++) if (mp[i][j] == '.' && !id[i][j])
		dfs(i, j, ++_);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
			if (mp[i][j] == '.') printf(".");
			else
			{
				set<int> have; int ans = 1;
				for (int k = 0;k < 4;)
				{
					int I = i+d[k], J = j+d[++k];
					if (I >= 0 && J >= 0 && id[I][J] && have.find(id[I][J]) == have.end())
					{
						have.insert(id[I][J]);
						ans += sz[id[I][J]];
					}
				}
				printf("%d", ans%10);
			}
		printf("\n");
	}
	return 0;
}