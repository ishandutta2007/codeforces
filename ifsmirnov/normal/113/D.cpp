#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define se second
#define fi first
#define pb push_back
#define mp make_pair
typedef double ld;
const int maxn = 25;

ld p[maxn];
ld res[maxn];
int n, m, s, t;
int e[maxn][maxn];
ld cur[maxn][maxn], nxt[maxn][maxn];
int deg[maxn];

void scan()
{
	cin >> n >> m >> s >> t;
	s--, t--;
	int u, v;
	forn(i, m)
	{
		cin >> u >> v;
		u--, v--;
		e[u][deg[u]++] = v;
		e[v][deg[v]++] = u;
	}
	forn(i, n) cin >> p[i];
}
void iter()
{
	forn(i, n) forn(j, n)
		swap(cur[i][j], nxt[i][j]);
	forn(i, n) forn(j, n)
	{
		//cout << i << " " << j << ": " << cur[i][j] << endl;
		if (i == j)
			res[i] += cur[i][j];
		else
		{
			ld add;
			//stay stay
			nxt[i][j] += cur[i][j] * p[i] * p[j];
			
			//move stay
			add = cur[i][j] * (1 - p[i]) * p[j] / (ld)deg[i];
			forn(k, deg[i])
				nxt[e[i][k]][j] += add;
				
			//stay move
			add = cur[i][j] * p[i] * (1 - p[j]) / (ld)deg[j];
			forn(k, deg[j])
				nxt[i][e[j][k]] += add;
				
			//move move
			add = cur[i][j] * (1 - p[i]) * (1 - p[j]) / (ld)deg[i] / (ld)deg[j];
			forn(k, deg[i]) forn(l, deg[j])
				nxt[e[i][k]][e[j][l]] += add;
		}
		cur[i][j] = 0;
	}
	//cout << endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scan();
	nxt[s][t] = 1;
	
	int cnt = 0;
	while (1)
	{
		if (++cnt == 50)
		{
			if (clock() > CLOCKS_PER_SEC * 1.8)
				break;
			cnt = 0;
		}
		iter();
	}
	
	cout.precision(10);
	forn(i, n)
		cout << fixed << res[i] << " ";
		
	return 0;
}