/*
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
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200040;

int n, m, k;
int ar[500][500];
vector<pair<int, int> > entries[500000];
int d[500][500];

int get_dist(int a, int b, int c, int d)
{
	return abs(a - c) + abs(b - d);
}

bool outside(int x, int y)
{
	return (x<1 || x>n || y<1 || y>m);
}

int dist[400 * 400], new_dist[400 * 400];
queue<pair<int, int> > qu;
int queued[500][500];

vector<pair<int, pair<int, int> > > order;

bool should_move_ptr(pair<int, pair<int, int> > p)
{
	int Qd = 1e9;
	if (qu.size())
	{
		Qd = d[qu.back().first][qu.back().second];
	}
	else
		Qd = 1e9;
	return (p.first <= Qd);
}

void bfs_solver(int lev)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			d[i][j] = 1e9;
			queued[i][j] = 0;
		}
	}

	order.clear();

	int bst = 1e9;
	for (int i = 0; i < entries[lev].size(); i++)
	{
		bst = min(bst, dist[i]);
	}
	for (int i = 0; i < entries[lev].size(); i++)
	{
		order.push_back(make_pair(dist[i], entries[lev][i]));
		//d[entries[lev][i].first][entries[lev][i].second] = dist[i];
		//qu.push(entries[lev][i]);
		//queued[entries[lev][i].first][entries[lev][i].second] = 1;

	}

	int ptr = 0;
	sort(order.begin(), order.end());

	while (true)
	{
		if (ptr == order.size() && qu.size() == 0)
			break;
		while (ptr < order.size()&&should_move_ptr(order[ptr]))
		{
			if (d[order[ptr].second.first][order[ptr].second.second]>1e7)
			{
				qu.push(order[ptr].second);
				d[order[ptr].second.first][order[ptr].second.second] = order[ptr].first;
			}
			++ptr;
		}
		pair<int, int> p = qu.front();
		qu.pop();
		queued[p.first][p.second] = 0;
		for (int dx = -1; dx <= 1; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				if (abs(dx) + abs(dy) != 1)
					continue;
				int nx = p.first + dx;
				int ny = p.second + dy;
				if (outside(nx, ny))
					continue;
				if (d[nx][ny] <= d[p.first][p.second] + 1)
					continue;
				d[nx][ny] = d[p.first][p.second] + 1;
				if (queued[nx][ny] == 0)
				{
					qu.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> ar[i][j];
			entries[ar[i][j]].push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < entries[1].size(); i++)
	{
		dist[i] = get_dist(1, 1, entries[1][i].first, entries[1][i].second);
	}

	for (int lev = 1; lev < k; lev++)
	{
		if (entries[lev].size()>500 && entries[lev + 1].size() > 500)
		{
			bfs_solver(lev);
			for (int j = 0; j < entries[lev + 1].size(); j++)
			{
				int qx = entries[lev + 1][j].first;
				int qy = entries[lev + 1][j].second;
				dist[j] = d[qx][qy];
			}
		}
		else
		{
			for (int j = 0; j < entries[lev + 1].size(); j++)
			{
				new_dist[j] = 1e9;
			}
			for (int j = 0; j < entries[lev].size(); j++)
			{
				for (int q = 0; q < entries[lev + 1].size(); q++)
				{
					new_dist[q] = min(new_dist[q], dist[j] + get_dist(entries[lev][j].first, entries[lev][j].second,
						entries[lev + 1][q].first, entries[lev + 1][q].second));
				}
			}
			for (int j = 0; j < entries[lev + 1].size(); j++)
			{
				dist[j] = new_dist[j];
			}
		}
	}

	cout << dist[0] << endl;

	cin.get(); cin.get();
	return 0;
}