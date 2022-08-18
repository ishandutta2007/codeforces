/*
Would you come and share
My cross, my pain, my heartbroken nature
For this burden is too heavy to bear
Too troublesome for one man to handle

Since my darkness swallowed
The last gleam of light
I've been rambling in the shadows
Hour after hour in the dark

They who never got sorrow,
Grinding grief in their hearts
Never lost a thing,
Never had a thing

They who never witnessed beauty,
That flamed even the all-encompassing night
Never lost a thing,
Never had a thing

Now these bitter tears run ceaseless,
And drown my hope far too deep
It must've been the day we parted
When I trapped this sadness in me

Since my darkness swallowed
The last gleam of light
I've been clothed in mourning,
Wearing sorrow day and night
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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 3050;

int n, m;
int memo_d[N][N], memo_dr[N][N];
int ans1, ans2, ans3, ans4;
int dist[N];
int root;
vector<int> g[N], gr[N];
queue<int> qu;
int best;
vector<int> order1[N], order2[N];

void bfs1()
{
	qu.push(root);
	dist[root] = 0;
	while (qu.size())
	{
		int v = qu.front();
		order1[root].push_back(v);
		qu.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if (dist[to] <= dist[v] + 1)
				continue;
			dist[to] = dist[v] + 1;
			qu.push(to);
		}
	}
}

void bfs2()
{
	qu.push(root);
	dist[root] = 0;
	while (qu.size())
	{
		int v = qu.front();
		order2[root].push_back(v);
		qu.pop();
		for (int i = 0; i < gr[v].size(); i++)
		{
			int to = gr[v][i];
			if (dist[to] <= dist[v] + 1)
				continue;
			dist[to] = dist[v] + 1;
			qu.push(to);
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
	
	cin >> n >> m;

	for (int i = 1; i <=m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dist[j] = 1e9;
		root = i;
		bfs1();

		for (int j = 1; j <= n; j++)
		{
			memo_d[i][j] = dist[j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dist[j] = 1e9;
		root = i;
		bfs2();
		for (int j = 1; j <= n; j++)
		{
			memo_dr[i][j] = dist[j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		reverse(order1[i].begin(), order1[i].end());
		reverse(order2[i].begin(), order2[i].end());
	}

//	cout << memo_dr[1][2] << endl;

	best = -1;

	for (int vert1 = 1; vert1 <= n; vert1++)
	{
		for (int vert2 = 1; vert2 <= n; vert2++)
		{
			if (vert1 == vert2)
				continue;
			if (memo_d[vert1][vert2] > 1e5)
				continue;
			for (int i = 0; i <= 2 && i < order2[vert1].size(); i++)
			{
				/*if (vert1 == 1 && vert2 == 8)
				{
					cout << order2[vert1][i] << "%" << " "<<memo_dr[vert1][order2[vert1][i]]<<endl;
				}*/

				for (int j = 0; j <= 2 && j < order1[vert2].size(); j++)
				{
					int id1 = order2[vert1][i];
					int id2 = vert1;
					int id3 = vert2;
					int id4 = order1[vert2][j];
					if (id1==id2||id1 == id3 || id1 == id4 || id2 == id3 || id2 == id4||id3==id4)
						continue;
					if (memo_d[id1][id2]>1e6 || memo_d[id2][id3]>1e6 || memo_d[id3][id4] > 1e6)
						continue;
					int here = memo_d[id1][id2] + memo_d[id2][id3] + memo_d[id3][id4];
					if (here >best)
					{
						best = here;
						ans1 = id1;
						ans2 = id2;
						ans3 = id3;
						ans4 = id4;
					}
				}
			}
		}
	}

	//cout << best << endl;
	cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;

	cin.get(); cin.get();
	return 0;
}