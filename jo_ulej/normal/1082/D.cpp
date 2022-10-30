#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int n;
vector<pair<int, int>> edges;
vector<int> leaves;
vector<int> sticks;
vector<int> a;
bool matr[510][510];
bool used[510];
int d[510];

void make_edge(int u, int v)
{
	edges.emplace_back(u, v);
	matr[u][v] = true;
	matr[v][u] = true;

	--a[u];
	--a[v];
}

int find_unused_leaf()
{
	for(auto l: leaves)
		if(a[l] > 0)
			return l;

	return -1;
}

int find_unused_stick()
{
	for(auto s: sticks)
		if(a[s] > 0)
			return s;

	return -1;
}

void bfs(int start)
{
	d[start] = 0;
	deque<int> q;
	q.push_front(start);

	while(!q.empty())
	{
		int v = q.back();
		used[v] = true;
		q.pop_back();

		for(int u = 1; u <= n; ++u)
		{
			if(matr[v][u] && !used[u])
			{
				d[u] = d[v] + 1;
				q.push_front(u);
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin >> n;
	a.resize(n + 1);

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			matr[i][j] = false;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(a[i] == 1)
			leaves.push_back(i);
		else
			sticks.push_back(i);
	}

	if(sticks.size() == 0)
	{
		cout << "NO" << endl;

		return 0;
	}

	for(int i = 0; i < sticks.size() - 1; ++i)
		make_edge(sticks[i], sticks[i + 1]);

	if(a[sticks[0]] > 0)
	{
		int u = find_unused_leaf();

		if(u != -1)
			make_edge(sticks[0], u);
	}

	if(a[sticks[sticks.size() - 1]] > 0)
	{
		int u = find_unused_leaf();

		if(u != -1)
			make_edge(sticks[sticks.size() - 1], u);
	}

	for(;;)
	{
		int u = find_unused_stick();
		int v = find_unused_leaf();

		if(v == -1)
			break;

		if(u == -1)
		{
			cout << "NO" << endl;

			return 0;
		}

		make_edge(u, v);
	}

	int diameter = 0;

	fill(used, used + 510, false);
	bfs(1);

	int idx = 1;

	for(int j = 2; j <= n; ++j)
		if(d[j] > d[idx])
			idx = j;

	fill(used, used + 510, false);
	bfs(idx);

	for(int j = 1; j <= n; ++j)
		diameter = max(diameter, d[j]);

	cout << "YES " << diameter << endl;

	cout << edges.size() << endl;

	for(int i = 0; i < edges.size(); ++i)
		cout << edges[i].first << " " << edges[i].second << endl;

    return 0;
}