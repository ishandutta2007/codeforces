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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 500000;

int n, m;

vector<int> ve[N];
vector<pair<int, int> > g[N];

int w[N];
int used[N];

int get(int x)
{
	if (x == w[x])
		return x;
	return w[x] = get(w[x]);
}

void merge(int a, int b,int val)
{
	g[a].push_back(make_pair(b, val));
	g[b].push_back(make_pair(a, val));
}

vector<int> ans;

int paired(int x)
{
	if (x < n)
		return x + n;
	return x - n;
}

int shit;

void dfs(int v,int clr)
{
	used[v] = clr;

	ve[clr].push_back(v);

	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int nval = clr;
		if (g[v][i].second == 1)
			nval = 3 - nval;
		if (used[to] == 0)
		{
			dfs(to, nval);
		}
		else
		{
			if (used[to]!=nval)
				shit = 1;
		}
	}
}

vector<int> solve()
{
	for (int i = 0; i < n * 2; i++)
	{
		used[i] = 0;
	}

	vector<int> res;

	shit = 0;

	for (int i = 0; i < n; i++)
	{
		if (used[i])
			continue;
		ve[2].clear();
		ve[1].clear();
		dfs(i,1);
		if (ve[2].size() < ve[1].size())
			swap(ve[1], ve[2]);
		for (int j = 0; j < ve[1].size(); j++)
			res.push_back(ve[1][j]);
	}

	if (shit)
	{
		for (int i = 0; i <= n + 20; i++)
			res.push_back(-1);
	}
	return res;
}

vector<pair<int, int> >edges;
vector<string> temps;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		assert(a != b);
		edges.push_back(make_pair(a, b));

		string temp;
		cin >> temp;
		temps.push_back(temp);
	}

	//make B

	for (int i = 0; i < n * 2; i++)
	{
		w[i] = i;
	}
	for (int i = 0; i < n * 2; i++)
	{
		used[i] = 0;
		g[i].clear();
	}

	for (int i = 0; i < edges.size(); i++)
	{
		int id1 = edges[i].first;
		int id2 = edges[i].second;
		string temp = temps[i];
		if (temp == "B")
			merge(id1, id2, 0);
		else
			merge(id1, id2, 1);
	}

	vector<int> ans1 = solve();

	for (int i = 0; i < n * 2; i++)
	{
		w[i] = i;
	}
	for (int i = 0; i < n * 2; i++)
	{
		used[i] = 0;
		g[i].clear();
	}

	// make R
	for (int i = 0; i < edges.size(); i++)
	{
		int id1 = edges[i].first;
		int id2 = edges[i].second;
		string temp = temps[i];
		if (temp == "R")
			merge(id1, id2, 0);
		else
			merge(id1, id2, 1);
	}

	vector<int> ans2 = solve();

	if (ans1.size() > ans2.size())
		ans1 = ans2; 

	sort(ans1.begin(), ans1.end());

	if (ans1.size() > n)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans1.size() << endl;
		for (int i = 0; i < ans1.size(); i++)
		{
			if (i)
				cout << " ";
			cout << ans1[i]+1;
		}
		cout << endl;
	}

	cin.get(); cin.get();
	return 0;
}