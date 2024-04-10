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
#define bs 1000000009
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 300331;

int n, m, tests, a[N], b[N], l[N], r[N], s[N], t[N];
int best[1031][1031];
vector<int> queries[N];
int ans[N];

void add_edge(int a, int b, int id)
{
	for (int i = 1; i <= n; i++)
	{
		if (best[a][i]<id)
			best[b][i] = max(best[b][i], best[a][i]);
	}
	best[b][a] = max(best[b][a], id);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> tests;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
		//	a[i] = rand() % n + 1;
		//	b[i] = rand() % n + 1;
	}
	for (int i = 1; i <= tests; i++)
	{
		cin >> l[i] >> r[i] >> s[i] >> t[i];
		queries[r[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			best[i][j] = -1e9;
		}
		best[i][i] = 1e9;
	}

	for (int i = 1; i <= m; i++)
	{
		add_edge(a[i], b[i], i);
		add_edge(b[i], a[i], i);
		for (int j = 0; j < queries[i].size(); j++)
		{
			int id = queries[i][j];
			if (best[t[id]][s[id]]<l[id])
				ans[id] = 0;
			else
				ans[id] = 1;
		}
	}

	for (int i = 1; i <= tests; i++)
	{
		if (ans[i])
			puts("Yes");
		else
			puts("No");
	}

	cin.get(); cin.get();
	return 0;
}