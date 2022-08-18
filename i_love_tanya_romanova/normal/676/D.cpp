/*
Loathsome abhorrent betrayer
Heinous recreant I protest
Your wretched birth
Exorcise your vile entity

Blood-sucking leech
Sycophant
Parasitic rogue
Implacability

Dudgeon despiteful vendetta
Sworn to reprisal
Discreate your own existence
Void with no deplore

Constant purveyor of anguish
Animosity
Unlamenting swinish whore
Disdain with revolting scorn

Blood-sucking leech
Sycophant
Parasitic rogue
Implacability

Traitor, envenoming antipathy
Ignoble, disgust, vidictiveness
With murderous fucking hate
Scorching retaliative pernicious spite
Detestable contempt
Revenge, adversely despised

Abject, despicable misanthropy
Repulsion, condemn and nullify with
Rabid violent force, invidious ferocity
Contemptible misprize
Distrust, hostile emnity
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 100000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 1031;

int n, m;
int dist[N][N][4], board[N][N][4];
queue<pair<pair<int, int>, int> > qu;

int get_dir(int x, int y)
{
	if (x == -1)
		return 0;
	if (x == 1)
		return 2;
	if (y == -1)
		return 3;
	return 1;
}

bool outside(int x, int y)
{
	return (x<1 || x>n || y<1 || y>m);
}

void update(int x1, int y1, int dir1, int x2, int y2, int dir2)
{
	if (outside(x2, y2))
		return;
	if (dist[x2][y2][dir2] <= dist[x1][y1][dir1] + 1)
		return;
	dist[x2][y2][dir2] = dist[x1][y1][dir1] + 1;
	qu.push(make_pair(make_pair(x2, y2), dir2));
}

void parse(char c,int a,int b)
{
	if (c == '+')
	{
		for (int i = 0; i <= 3; i++)
		{
			board[a][b][i] = 1;
		}
		return;
	}
	if (c == '-')
	{
		board[a][b][1] = board[a][b][3] = 1;
		return;
	}
	if (c == '|')
	{
		board[a][b][0] = board[a][b][2] = 1;
	}
	if (c == '^')
	{
		board[a][b][0] = 1;
	}
	if (c == '>')
	{
		board[a][b][1] = 1;
	}
	if (c == '<')
	{
		board[a][b][3] = 1;
	}
	if (c == 'v')
	{
		board[a][b][2] = 1;
	}
	if (c == '*')
	{
		return;
	}
	if (c == 'L')
	{
		board[a][b][0] = board[a][b][1] = board[a][b][2] = 1;
	}
	if (c == 'R')
	{
		board[a][b][0] = board[a][b][2] = board[a][b][3] = 1;
	}
	if (c == 'D')
	{
		board[a][b][0] = board[a][b][1] = board[a][b][3] = 1;
	}
	if (c == 'U')
	{
		board[a][b][1] = board[a][b][2] = board[a][b][3] = 1;
	}
}
int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string st;
		cin >> st;
		for (int j = 1; j <= m; j++)
		{
			parse(st[j - 1], i, j);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				dist[i][j][dir] = 1e9;
			}
		}
	}

	int sx, sy, tx, ty;
	cin >> sx >> sy;
	cin >> tx >> ty;

	dist[sx][sy][0] = 0;
	qu.push(make_pair(make_pair(sx, sy), 0));

	while (qu.size())
	{
		pair<pair<int, int>, int> v = qu.front();
		qu.pop();
		int qx, qy;
		qx = v.first.first;
		qy = v.first.second;
		int qrot = v.second;
		int qdir = qrot;
		//cout << qx << " " << qy << " " << qdir << endl;

		//rotate
		update(qx, qy, qrot, qx, qy, (qrot+1)%4);
		// mov
		for (int dx = -1; dx <= 1; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				if (abs(dx) + abs(dy) != 1)
					continue;
				int Tdir = get_dir(dx, dy);
				int Tdir2 = (Tdir + 2) % 4;
				int adj_dir = (Tdir + 4 - qdir) % 4;
				int adj_dir2 = (Tdir2+ 4 - qdir) % 4;
				if (board[qx][qy][adj_dir] == 1 && board[qx + dx][qy + dy][adj_dir2] == 1)
				{
					update(qx, qy, qrot, qx + dx, qy + dy, qrot);
				}
			}
		}
	}
	
	int ans = 1e9;
	for (int i = 0; i < 4; i++)
	{
		ans = min(ans, dist[tx][ty][i]);
	}
	if (ans>1e8)
		ans = -1;
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}