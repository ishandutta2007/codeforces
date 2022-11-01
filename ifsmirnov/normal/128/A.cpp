#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define fi first
#define se second
#define mp make_pair
const int maxn = 10;
typedef pair<int, int> pii;
const int dx[] = {-1,0,1,-1,0,1,-1,0,1};
const int dy[] = {1,1,1,0,0,0,-1,-1,-1};
#define ok(x, y) ((x)<8&&(y)>=0&&(y)<8&&(x)>=0)

int n=8, m=8;
int a[maxn][maxn];
int b[maxn][maxn][100];

void scan()
{
	char t[maxn];
	forn(i, n)
	{
		cin >> t;
		forn(j, n)
			if (t[j] == 'S')
				a[i][j] = 1;
	}
}
bool solve()
{
	forn(i, n) forn(j, n) forn(k, 100) b[i][j][k] = 0;
	queue<pair<pii, int> > q;
	q.push(mp(mp(7,0), 0));
	b[7][0][0] = 1;
	while (!q.empty())
	{
		pair<pii, int> w = q.front();
		q.pop();
		int x = w.fi.fi, y = w.fi.se, t = w.se;
		//cout << x << " " << y << " " << t << endl;
		if (t >= 90)
			break;
		forn(i, 9)
		{
			int tx = x+dx[i], ty=y+dy[i], tt = t+1;
			if (ok(tx, ty) && !(ok(tx-tt, ty) && a[tx-tt][ty]) && !(ok(tx-t, ty) && a[tx-t][ty]) && !b[tx][ty][tt])
			{
				/*if (x == 7 && y == 0 && t == 0)
				{
					cout << tx << " " << ty << " " << tt << endl;
					cout << ok(tx-tt, ty) << endl;
				}*/
				b[tx][ty][tt] = 1;
				q.push(mp(mp(tx, ty), tt));
			}
		}
	}
	forn(i, 90) if (b[0][7][i]) return true;
	return false;
}


int main()
{
	//freopen("input.txt", "r", stdin);
	scan();
	cout << (solve() ? "WIN" : "LOSE");
	
	return 0;
}