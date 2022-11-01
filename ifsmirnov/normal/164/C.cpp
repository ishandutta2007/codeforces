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
const int maxn = 2050;

int n, k;
struct edge
{
	int v, c, cost, rev;
	edge(){}
	edge(int V, int C, int Cost, int R): v(V), c(C), cost(Cost), rev(R) {} 
};
vector<edge> e[maxn];
void add_edge(int u, int v, int cost)
{
	//cout << "add edge " << u << " " << v << " " << cost << endl;
	e[u].pb(edge(v, 1, cost, e[v].size()));
	e[v].pb(edge(u, 0, -cost, e[u].size() - 1));
}
int s[maxn], t[maxn], c[maxn];
int S, T;
void scan()
{
	cin >> n >> k;
	forn(i, n)
		cin >> s[i] >> t[i] >> c[i];
	forn(i, n) add_edge(i*2, i*2+1, -c[i]);
	forn(i, n) forn(j, n)
		if (s[i] + t[i] <= s[j])
			add_edge(i*2+1, j*2, 0);
	S = 2*n;
	T = S+1;
	forn(i, n)
	{
		add_edge(S, 2*i, 0);
		add_edge(2*i+1, T, 0);
	}
	n = n*2 + 2;
}

int d[maxn];
int h[maxn];
int b[maxn];
int anc[maxn], ancn[maxn];
void fb()
{
	forn(i, n) 
		d[i] = inf;
	d[S] = 0;
	bool upd = true;
	while (upd)
	{
		upd = false;
		forn(v, n) forn(i, e[v].size())
		{
			if (e[v][i].c <= 0) continue;
			int to = e[v][i].v;
			int w = e[v][i].cost;
			if (d[to] > d[v] + w)
				d[to] = d[v] + w, upd = true;
		}
	}
	forn(i, n) h[i] = d[i];
}

int dijkstra()
{
	forn(i, n) d[i] = inf, b[i] = 0;
	d[S] = 0;
	forn(III, n)
	{
		int v = 0;
		forn(i, n) if (b[v] || (!b[i] && d[i] < d[v]))
			v = i;
			
		if (d[v] == inf)
			break;
			
		b[v] = 1;
		forn(i, e[v].size())
		{
			if (e[v][i].c <= 0) continue;
			int to = e[v][i].v;
			if (b[to]) continue;
			int w = e[v][i].cost + h[v] - h[to];
			//cout << w << endl;
			if (d[to] > d[v] + w)
				d[to] = d[v] + w, anc[to] = v, ancn[to] = i;
		}
	}
	
	if (!b[T])
		return inf;
		
	int cur = T;
	int res = 0;
	while (cur != S)
	{
		//cout << "cur = " << cur << endl;
		int prev = anc[cur];
		int i = ancn[cur];
		//cout << "prev = " << prev << ", e[prev][i].v = " << e[prev][i].v << ", e[prev][i].cost = " << e[prev][i].cost << endl;
		res += e[prev][i].cost;
		e[prev][i].c--;
		e[cur][e[prev][i].rev].c++;
		cur = prev;
	}
	//cout << endl;
	forn(i, n) h[i] += d[i];
	return res;
}

int res[maxn];
void capture()
{
	forn(i, n/2-1)
		res[i] = (bool)(e[i*2][0].c == 0);
}
void solve()
{
	fb();	
	int best = 0;
	int cur = 0;
	forn(i, k)
	{
		int ret = dijkstra();
		//cout << "ret = " << ret << endl;
		if (ret == inf)
			break;
		cur += ret;
		if (cur < best)
		{
			best = cur;
			capture();
		}
	}
	
	forn(i, n/2-1)
		cout << res[i] << " ";
	cout << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	
	scan();
	solve();
	
	return 0;
}