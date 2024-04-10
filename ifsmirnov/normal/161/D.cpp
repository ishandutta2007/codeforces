#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef double ld;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define unq(x) {sort(all(x));(x).resize(unique(all(x))-(x).begin());}
#define lb lower_bound
const int inf = 1e9+100500;
const int maxn = 50010;

int n, k;
int d[maxn][505];
vector<int> e[maxn];

void scan()
{
	cin >> n >> k;
	forn(i, n-1)
	{
		int u, v;
		cin >> u >> v;
		e[--v].pb(--u);
		e[u].pb(v);
	}
}

i64 res = 0;
void dfs (int v, int anc)
{
	forn(i, e[v].size()) if (e[v][i] != anc)
	{
		int to = e[v][i];
		dfs(to, v);
		res += d[to][k-1];
		for (int t = 1; k-t-1 >= 0; t++)
			res += (i64)d[v][t] * d[to][k-t-1];
		forn(i, k)
			d[v][i+1] += d[to][i];
	}
	d[v][0] = 1;
	
	/*cout << "V = " << v << endl;
	forn(i, k+1)
		cout << d[v][i] << " ";
	cout << endl;*/
}

int main()
{
	//freopen("input.txt", "r", stdin);
	
	scan();
	dfs(0, -1);
	cout << res << endl;
	
	return 0;
}