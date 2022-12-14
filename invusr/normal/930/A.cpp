#include <bits/stdc++.h>
using namespace std;

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

int n;
vector<int> adj[MaxN + 1];

int mark[MaxN];

void dfs(const int &u, const int &d)
{
	mark[d] ^= 1;
	for (int v : adj[u])
		dfs(v, d + 1);
}

int main()
{
	cin >> n;
	for (int v = 2; v <= n; ++v)
		adj[getint()].push_back(v);

	dfs(1, 0);

	cout << count(mark, mark + n, 1) << endl;

	return 0;
}