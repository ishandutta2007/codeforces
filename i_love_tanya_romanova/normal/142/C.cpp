
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
//#define bs 1234567891
#define bsize 512

const int N = 120000;

using namespace std;

vector<string> fig;
int n,m ;
vector<vector<string> > figs;
int ans;
vector<pair<pair<int, int> ,int> > avec;
int board[200][200];

bool bad(int a, int b)
{
	return (a < 0 || a >= n || b < 0 || b >= m || board[a][b] == 1);
}

vector<string> rotate(vector<string> cur)
{
	char temp[10][10];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = cur[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cur[i][j] = temp[j][2 - i];
		}
	}
	return cur;
}

vector<pair<pair<int, int>, int> > cur;

bool can_put(int x, int y, int id)
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (figs[id][i][j] == '#')
			{
				if (bad(i+x, j+y))
					return false;
			}
		}
	}
	return true;
}

void do_put(int x, int y, int id)
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (figs[id][i][j] == '#')
			{
				board[x + i][y + j] = 1;
			}
		}
	}
	cur.push_back(make_pair(make_pair(x, y), id));
}

void unroll(int x, int y, int id)
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (figs[id][i][j] == '#')
			{
				board[x + i][y + j] = 0;
			}
		}
	}
	cur.pop_back();
}

int flag, iters;

void dfs(int a, int b)
{
	int rem_area = n*m - (a*m + b);
	if (cur.size() + rem_area / 5 <= avec.size())
		return;

	++iters;
	if (iters % 1024 == 0)
	{
		double R = clock()*1.0 / CLOCKS_PER_SEC;
		if (R > 1.4)
			flag = 1;
	}
	if (flag)
		return;
	if (cur.size()>avec.size())
	{
		avec = cur;
	}

	if (a >=n-2)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (can_put(a, b, i))
		{
			do_put(a, b, i);
			if (b + 1 == m)
				dfs(a + 1, 0);
			else
				dfs(a, b + 1);
			unroll(a, b, i);
		}
	}
	
	if (b + 1 == m)
		dfs(a + 1, 0);
	else
		dfs(a, b + 1);
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	fig.push_back("###");
	fig.push_back(".#.");
	fig.push_back(".#.");

	figs.push_back(fig);
	for (int i = 0; i < 3; i++)
	{
		figs.push_back(rotate(figs.back()));
	}

	cin >> n >> m;

	dfs(0,0);

	cout << avec.size() << endl;

	for (int i = 0; i < avec.size(); i++)
	{
		int qi, qj;
		qi = avec[i].first.first;
		qj = avec[i].first.second;

		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				if (figs[avec[i].second][a][b] == '#')
				{
					board[qi + a][qj + b] = i + 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
				cout << ".";
			else
				cout << char('A' + board[i][j] - 1);
		}
		cout << endl;
	}

	cin.get(); cin.get();
	return 0;
}