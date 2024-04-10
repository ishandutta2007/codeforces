#include <iostream>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
typedef vector<int> vi;
typedef pair<int, int> pii;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef long long i64;
const int inf = 1e9+100500;
const int maxn = 100500;

int n, m;
vector<int> e[maxn];
int q[maxn], d[maxn];
i64 tin[maxn], tout[maxn];

void scan()
{
	cin >> n >> m;
	forn(i, m)
	{
		int u, v;
		cin >> u >> v;
		e[--u].pb(--v);
		e[v].pb(u);
	}
}
void bfs()
{
	int lq = 0, rq = 1;
	forn(i, n) d[i] = inf;
	d[0] = 0;
	while (lq != rq)
	{
		int v = q[lq++];
		forn(i, e[v].size())
		{
			int to = e[v][i];
			if (d[to] > d[v] + 1)
				d[to] = d[v]+1, q[rq++] = to;
		}
	}
}
int order[maxn];
bool cmplt(int i, int j) {return d[i] < d[j];}
void compts()
{
	forn(i, n) order[i] = i;
	sort(order, order+n, cmplt);
	
	tin[0] = 1;
	forn(I, n)
	{
		int i = order[I];
		forn(j, e[i].size())
			if (d[i] + 1 == d[e[i][j]]) tin[e[i][j]] += tin[i];
	}
	
	reverse(order, order+n);
	tout[n-1] = 1;
	forn(I, n)
	{
		int i = order[I];
		forn(j, e[i].size())
			if (d[i] - 1 == d[e[i][j]]) tout[e[i][j]] += tout[i];
	}
}
i64 getnsp(int i, int j) {if (d[i] + 1 == d[j]) return tin[i] * tout[j]; return 0;}
double solve()
{
	bfs();
	compts();
	i64 mx = 0;
	forn(i, n)
	{
		i64 cur = 0;
		forn(j, e[i].size())
			cur += getnsp(i, e[i][j]) + getnsp(e[i][j], i);
		mx = max(mx, cur);
	}
	return (double)mx / (double)tin[n-1];
}

int main()
{
//	freopen("input.txt", "r", stdin);
	
	scan();
	cout.precision(10);
	cout << fixed << solve() << endl;
	
	return 0;
}