#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define se second
#define fi first
#define mp make_pair
typedef pair<int, int> pii;
typedef long long i64;
const int inf = 1e9+100500;
const int maxn = 100500;

int n, m;
int act[maxn];
vector<int> e[maxn], er[maxn];

void scan()
{
	cin >> n >> m;
	forn(i, n) cin >> act[i];
	forn(i, m)
	{
		int u, v;
		cin >> u >> v;
		--u,--v;
		e[u].pb(v);
		er[v].pb(u);
	}
}

int q[maxn];
int b[maxn];
int ok1[maxn], ok2[maxn];

void bfs1()
{
	int lq = 0, rq = 0;
	memset(b, 0, sizeof b);
	forn(i, n) if (act[i] == 1)
		b[i] = 1, q[rq++] = i;
	
	while (lq != rq)
	{
		int v = q[lq++];
		forn(i, e[v].size())
		{
			int to = e[v][i];
			if (b[to]) continue;
			b[to] = 1;
			q[rq++] = to;
		}
	}
	memcpy(ok1, b, sizeof b);
}
void bfs2()
{
	int lq = 0, rq = 0;
	memset(b, 0, sizeof b);
	forn(i, n) if (act[i] == 2)
		b[i] = 1, q[rq++] = i;
	
	while (lq != rq)
	{
		int v = q[lq++];
		if (act[v] == 1) continue;
		forn(i, er[v].size())
		{
			int to = er[v][i];
			if (b[to]) continue;
			b[to] = 1;
			q[rq++] = to;
		}
	}
	memcpy(ok2, b, sizeof b);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	
	ios :: sync_with_stdio(false);
	
	scan();
	bfs1();
	bfs2();
	//forn(i, n) cout << ok1[i] << " " << ok2[i] << endl;
	forn(i, n) cout << (bool)(ok1[i] && ok2[i]) << "\n";
	
	return 0;
}