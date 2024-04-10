#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1050;
const int inf = 1e9+100500;
#define forn(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int> pii;
#define se second
#define fi first
#define mp make_pair

int n;
bool dbl;
int t[maxn];
int d[maxn][maxn];
pii anc[maxn][maxn];
pii val[maxn][maxn];

void scan();
void solve();
void print();

int main()
{
	//freopen("input.txt", "r", stdin);
	
	scan();
	solve();
	print();
	
	return 0;
};
void scan()
{
	cin >> n;
	forn(i, n) cin >> t[i];
	if (n%2) n++, dbl = 1;
	else dbl = 0;
};
void solve()
{
	forn(i, maxn) forn(j, maxn) d[i][j] = inf;
	d[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
		//	cout << endl;
			//cout << i << " " << j << endl;
			//cout << d[i][j] << endl;
			// ... j .... | i i+1
			
			// 1)all last customers taken
			if (i == j)
			{
				//(i i+1)  ->  i+2,1+2
				if (d[i+2][i+2] > d[i][j] + max(t[i], t[i+1]))
				{
					d[i+2][i+2] = d[i][j] + max(t[i], t[i+1]);
					anc[i+2][i+2] = mp(i,j);
					val[i+2][i+2] = mp(i, i+1);
				}	
				//(i i+2)  ->  i+3, i+1
				if (d[i+3][i+1] > d[i][j] + max(t[i], t[i+2]))
				{
					d[i+3][i+1] = d[i][j] + max(t[i], t[i+2]);
					anc[i+3][i+1] = mp(i,j);
					val[i+3][i+1] = mp(i, i+2);
				}	
				//(i+1 i+2)  ->  i+3, i
				if (d[i+3][i] > d[i][j] + max(t[i+1], t[i+2]))
				{
					d[i+3][i] = d[i][j] + max(t[i+1], t[i+2]);
					anc[i+3][i] = mp(i,j);
					val[i+3][i] = mp(i+1, i+2);
				}	
			}
			else
			{
				//(j i)  ->  i+1, i+1
				if (d[i+1][i+1] > d[i][j] + max(t[i], t[j]))
				{
					d[i+1][i+1] = d[i][j] + max(t[i], t[j]);
					anc[i+1][i+1] = mp(i,j);
					val[i+1][i+1] = mp(i, j);
				}	
				//(j i+1)  ->  i+2, i
				if (d[i+2][i] > d[i][j] + max(t[i+1], t[j]))
				{
					d[i+2][i] = d[i][j] + max(t[i+1], t[j]);
					anc[i+2][i] = mp(i,j);
					val[i+2][i] = mp(i+1, j);
				}	
				//(i i+1)  ->  i+2, j
				if (d[i+2][j] > d[i][j] + max(t[i], t[i+1]))
				{
					d[i+2][j] = d[i][j] + max(t[i], t[i+1]);
					anc[i+2][j] = mp(i,j);
					val[i+2][j] = mp(i, i+1);
				}	
			}
		}
};
void print()
{
	cout << d[n][n] << endl;
	vector<pii> res;
	int x = n, y = n;
	forn(i, n/2)
	{
		res.push_back(val[x][y]);
		pii t = anc[x][y];
		x = t.fi; y = t.se;
	}
	reverse(res.begin(), res.end());
	forn(i, n/2) res[i].fi++, res[i].se++;
	forn(i, n/2)
	{
		if (!dbl) cout << res[i].fi << " " << res[i].se << "\n";
		else 
		{
			if (res[i].fi != n) cout << res[i].fi << " ";
			if (res[i].se != n) cout << res[i].se << " ";
			cout << "\n";
		}
	}
};