/*
Scrape the pain off of my lips and watch our lives unwind
When I am in the camera eye self-immolation can never purify

Look at me, I'm on display
Another animal in this zoo our creator betrayed
If you don't feel the lesson, you're blind and deaf my son
But don't run

Look at me, I'm on the wire

I am not your saviour

Scrape the pain off of my lips and watch our lives unwind
When I am in the camera eye self-immolation can never purify

I am not your saviour

Look at me, I'm never afraid
I'll never look back in disdain

Scrape the pain off of my lips and watch our lives unwind
When I am in the camera eye self-immolation can never purify
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
#define bsize 512

const int N = 1100000;

using namespace std;

vector<vector<int> > ar;
int w[N];
int dp[N];
queue<int> leaves;
int n, m;
int indeg[N];
vector<pair<int, int> > order;
vector<int> g[N];

int get(int x)
{
	if (x == w[x])
		return x;
	return w[x] = get(w[x]);
}

void merge(int a, int b)
{
	a = get(a);
	b = get(b);
	if (a == b)
		return;
	w[a] = b;
}

void add_edge(int a, int b)
{
	//cout << "@" << a << " " << b << endl;
	a = get(a);
	b = get(b);
	//cout << a << "%" << b << endl;
	indeg[b]++;
	g[a].push_back(b);
}

int main(){
	//	freopen("packing.in", "r", stdin);
	//	freopen("packing.out", "w", stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;

	ar.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		ar[i].resize(m + 1);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ar[i][j];
		}
	}

	for (int i = 0; i < n*m; i++)
	{
		w[i] = i;
	}

	// merge 1
	for (int i = 0; i < n; i++)
	{
		order.clear();

		for (int j = 0; j < m; j++)
		{
			order.push_back(make_pair(ar[i][j], j));
		}
		sort(order.begin(), order.end());
		for (int j = 1; j < order.size(); j++)
		{
			if (order[j].first == order[j - 1].first)
			{
				merge(i*m + order[j].second, i*m + order[j - 1].second);
			}
		}
	}
	// merge 2
	for (int i = 0; i < m; i++)
	{
		order.clear();
		for (int j = 0; j < n; j++)
		{
			order.push_back(make_pair(ar[j][i], j));
		}
		sort(order.begin(), order.end());
		for (int j = 1; j < order.size(); j++)
		{
			if (order[j].first == order[j - 1].first)
			{
				merge(i + order[j].second*m, i + order[j - 1].second*m);
			}
		}
	}

	// graph

	for (int i = 0; i < n; i++)
	{
		order.clear();
		for (int j = 0; j < m; j++)
		{
			order.push_back(make_pair(ar[i][j], j));
		}
		sort(order.begin(), order.end());
		for (int j = 1; j < order.size(); j++)
		{
			if (order[j].first != order[j - 1].first)
			{
				add_edge(i*m + order[j - 1].second, i*m + order[j].second);
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		order.clear();
		for (int j = 0; j < n; j++)
		{
			order.push_back(make_pair(ar[j][i], j));
		}
		sort(order.begin(), order.end());
		for (int j = 1; j < order.size(); j++)
		{
			if (order[j].first != order[j - 1].first)
			{
				add_edge(i + order[j-1].second*m, i + order[j].second*m);
			}
		}
	}

	for (int i = 0; i < n*m; i++)
	{
		if (w[i] != i)
			continue;
		if (indeg[i] == 0)
		{
			leaves.push(i);
		}
	}

	while (leaves.size())
	{
		int val = leaves.front();
		leaves.pop();
		for (int i = 0; i < g[val].size(); i++)
		{
			int to = g[val][i];
			dp[to] = max(dp[to], dp[val] + 1);
			--indeg[to];
			if (indeg[to] == 0)
				leaves.push(to);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int id = i*m + j;
			id = get(id);
			if (j)
				cout << " ";
			cout << dp[id] + 1;
		}
		cout << "\n";
	}

	cin.get(); cin.get();
	return 0;
}