#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++) 
#define pb push_back
const int maxn = 5050;

int a[maxn];
vector<int> e[maxn];
map<int, int> index;
int u[maxn];
int v[maxn];
int c[maxn];
int h[maxn];
void dfs (int, int, int);
int ans[maxn];
void scan();
void solve();
int n;

int main()
{
	//freopen("input.txt", "r", stdin);
	scan();
	solve();
	
	return 0;
};

void scan ()
{
	cin >> n;
	forn(i, n)
	{
		cin >> a[i];
		index[a[i]] = i;
	}
	forn(i, n-1)
	{
		cin >> v[i] >> u[i] >> c[i];
		u[i]--;v[i]--;
		e[v[i]].pb(u[i]);
		e[u[i]].pb(v[i]);
	}
};
void solve()
{
	dfs(0,-1, 0);
	forn(i, n-1) if (h[u[i]] < h[v[i]]) swap(u[i], v[i]); //u->v
	
	vector<vector<int> > cur(n), nxt(n);
	int cnt = 0;
	forn(i, n) nxt[i].pb(a[i]);
	for (int i = 0;; i++) 
	{
		/*forn(j, n) 
		{
			cout << j << ": ";
			forn(k, nxt[j].size()) cout << nxt[j][k] << " ";
			cout << endl;
		}
		cout << endl;*/
		cnt += nxt[0].size();
		forn(j, nxt[0].size())
			ans[index[nxt[0][j]]] = i;
		if (cnt == n) break;
		nxt[0].resize(0);
		swap(cur, nxt);
		forn(j, n) nxt[j].resize(0);
		
		forn(j, n-1)
		{
			int lim = min(c[j], (int)(cur[u[j]].size()));
			forn(k, lim)
				nxt[v[j]].pb(cur[u[j]][k]);
			for (int k = lim; k < (int)(cur[u[j]].size()); k++)
				nxt[u[j]].pb(cur[u[j]][k]);
		}
		forn(j, n) sort(nxt[j].begin(), nxt[j].end());
	}
	forn(i, n) cout << ans[i] << " ";
};
void dfs (int v, int anc, int h0)
{
	h[v] = h0;
	forn(i, e[v].size())
	{
		int to = e[v][i];
		if (to != anc) dfs(to, v, h0+1);

	}
};