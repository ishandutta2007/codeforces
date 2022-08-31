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
const int N = 500031;

int n;
int a, b;
vector<int> g[N];
vector<int> G[N];
int used[N];
int p[N];

void trace(int v)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		G[v].push_back(to);
		p[to] = v;
		trace(to);
	}
}

int res[N], subsize[N];
multiset<int>by_sons[N];
multiset<int>::iterator it;

int good_size(int x)
{
	return (x * 2 <= n);
}

void solve_down(int v)
{
	used[v] = 1;
	subsize[v] = 1;

	for (int i = 0; i < G[v].size(); i++)
	{
		int to = G[v][i];
		solve_down(to);
		res[v] = max(res[v], res[to]);
		by_sons[v].insert(res[to]);
		subsize[v] += subsize[to];
	}
	if (good_size(subsize[v]))
		res[v] = max(res[v], subsize[v]);
}

int best_up[N];

void solve_up(int v)
{
	if (v != 1)
	{
		best_up[v] = best_up[p[v]];
	}
	if (good_size(n - subsize[v]))
	{
		best_up[v] = max(best_up[v], n - subsize[v]);
	}
	if (v != 1)
	{
		if (by_sons[p[v]].size())
		{
			it = by_sons[p[v]].end();
			--it;
			int val = (*it);
			best_up[v] = max(best_up[v], val);
		}
	}
	for (int i = 0; i < G[v].size(); i++)
	{
		int to = G[v][i];
		int val = res[to];
		by_sons[v].erase(by_sons[v].find(val));
		solve_up(to);
		by_sons[v].insert(val);
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	trace(1);

	for (int i = 1; i <= n; i++)
	{
		used[i] = 0;
	}

	solve_down(1);

	for (int i = 1; i <= n; i++)
	{
		used[i] = 0;
	}

	solve_up(1);
	/*
	for (int i = 1; i <= n; i++)
	{
	int v = i;
	cout << subsize[v] << " " << res[v] << " " << best_up[v] << endl;
	}
	*/

	/*for (int i = 1; i <= n; i++)
	{
	cout << "%" << i << " " << best_up[i] << " "<<subsize[i]<<endl;
	}
	*/
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " ";
		int largest_comp = 0;
		int largest_cut = 0;
		for (int j = 0; j < G[i].size(); j++)
		{
			int to = G[i][j];
			largest_comp = max(largest_comp, subsize[to]);
			if (good_size(subsize[to]))
				continue;
			largest_cut = max(largest_cut, res[to]);
		}
		int v = i;
		if (i != 1)
		{
			largest_comp = max(largest_comp, n - subsize[v]);
			if (!good_size(n - subsize[v]))
				largest_cut = max(largest_cut, best_up[v]);//?
		}
		if (good_size(largest_comp - largest_cut))
			cout << 1;
		else
			cout << 0;
		//cout << i << " " << largest_comp << " " << largest_cut << endl;
	}

	cout << endl;

	cin.get(); cin.get();
	return 0;
}