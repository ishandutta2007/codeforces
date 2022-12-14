#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

#define prev PREV

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100000;
const int MaxM = 200000;

int n, m, sv;
vector<int> adj[MaxN + 1];

bool vis[MaxN + 1][2];
int prev[MaxN + 1][2];

void dfs(const int &u, const int &k)
{
	vis[u][k] = true;

	for (int v : adj[u])
		if (!vis[v][!k])
		{
			prev[v][!k] = u;
			dfs(v, !k);
		}
}

bool insta[MaxN + 1];
bool book[MaxN + 1];

bool circle = false;

void dfs(const int &u)
{
	insta[u] = book[u] = true;

	for (int v : adj[u])
	{
		if (!book[v])
			dfs(v);
		else if (insta[v])
			circle = true;
	}

	insta[u] = false;
}

int main()
{
	cin >> n >> m;
	for (int u = 1; u <= n; ++u)
	{
		int k = getint();

		adj[u].resize(k);
		for (int i = 0; i < k; ++i)
			adj[u][i] = getint();
	}
	cin >> sv;

	dfs(sv, 0);

	for (int u = 1; u <= n; ++u)
		if (adj[u].empty() && vis[u][1])
		{
			cout << "Win" << endl;

			vector<int> path;

			int p = u, k = 1;
			while (p != sv || k)
			{
				path.push_back(p);
				p = prev[p][k];
				k = !k;
			}

			reverse(path.begin(), path.end());

			printf("%d", sv);
			for (int v : path)
				printf(" %d", v);
			printf("\n");

			return 0;
		}

	dfs(sv);

	cout << (circle ? "Draw" : "Lose");
	cout << endl;

	return 0;
}