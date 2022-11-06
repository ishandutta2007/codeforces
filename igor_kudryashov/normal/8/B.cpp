#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sqr(a) ((a) * (a))

typedef long long li;
typedef pair <int, int> pt;
const int INF = 1e9;
const int NMAX = 1e4;
const double EPS = 1e-9;


const int dx [] = {0, 0, 1, -1};
const int dy [] = {-1, 1, 0, 0};

string s;
bool used[300][300];
int curx = 150, cury = 150;
int finx, finy;
int d[300][300];

int bfs () {
	queue <pt> q;
	q.push(mp(150, 150));
	memset(d, 120, sizeof(d));
	d[150][150] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		forn(i, 4) {
			int tx = x + dx[i], ty = y + dy[i];
			if (!used[tx][ty]) continue;
			if (d[tx][ty] <= d[x][y] + 1) continue;
			d[tx][ty] = d[x][y] + 1;
			q.push(mp(tx, ty));
		}
	}
	return d[finx][finy];
}

bool ok () {
	forn(i, s.size()) {
		if (s[i] == 'L') cury--; else
			if (s[i] == 'R') cury++; else
				if (s[i] == 'U') curx--; else curx++;
		used[curx][cury] = true;
	}
	finx = curx;
	finy = cury;	
	int t = bfs();
	if (t < (int) s.size()) return false;
	return true;
}

int main()
{
	cin >> s;
	used[curx][cury] = true;
	if (ok()) cout << "OK"; else cout << "BUG";
	cout << endl;
	return 0;
}