#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace UF
{
	int n, par[1000005], ran[1000005], sz[1000005];
	void init(int _n)
	{
		n = _n;
		for (int i = 0;i < n;i++) par[i] = i, sz[i] = 1;
	}
	int getpar(int i)
	{
		return par[i]==i?par[i]:par[i]=getpar(par[i]);
	}
	void merge(int a, int b)
	{
		a = getpar(a), b = getpar(b);
		if (a != b)
		{
			if (ran[a] < ran[b])
			{
				par[a] = b;
				sz[b] += sz[a];
			} else
			{
				par[b] = a;
				sz[a] += sz[b];
				if (ran[a] == ran[b])
					ran[a]++;
			}
		}
	}
};

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
set<pair<ll, pair<int, int> > > pq;
ll a[1005][1005];
bool v[1005][1005];
int r, c;
ll k, nd, wh;

int foo(int x, int y)
{
	return x*c+y;
}

void dfs(int x, int y)
{
	if (x < 0 || x >= r || y < 0 || y >= c) return;
	if (v[x][y]) return;
	if (nd == 0) return;
	if (a[x][y] < wh) return;
	v[x][y] = true;
	nd--;
	a[x][y] = wh;
	for (int i = 0;i < 4;i++) dfs(x+dx[i], y+dy[i]);
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> r >> c >> k;
	UF::init(r*c);
	for (int i = 0;i < r;i++) for (int j = 0;j < c;j++)
	{
		cin >> a[i][j];
		pq.emplace(a[i][j], make_pair(i, j));
	}
	while (!pq.empty())
	{
		wh = (*pq.rbegin()).first;
		vector<int> id;
		while (!pq.empty() && (*pq.rbegin()).first == wh)
		{
			pair<int, int> u = (*pq.rbegin()).second; pq.erase(--pq.end());
			int x = u.first, y = u.second;
			for (int i = 0;i < 4;i++) if (x+dx[i] >= 0 && x+dx[i] < r && y+dy[i] >= 0 && y+dy[i] < c && a[x+dx[i]][y+dy[i]] >= wh)
				UF::merge(foo(x, y), foo(x+dx[i], y+dy[i]));
			id.push_back(foo(x, y));
		}
		if (k%wh == 0)
		{
			nd = k/wh;
			for (int u: id) if (UF::sz[UF::getpar(u)] >= nd)
			{
				cout << "YES\n";
				dfs(u/c, u%c);
				for (int i = 0;i < r;i++)
				{
					for (int j = 0;j < c;j++) cout << a[i][j]*v[i][j] << " ";
					cout << "\n";
				}
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}