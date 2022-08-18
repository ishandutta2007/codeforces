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

int n, tests;
int par[N];
vector<int> g[N];
int subsize[N];
int centroid[N];

void trace(int v)
{
	subsize[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		trace(g[v][i]);
		subsize[v] += subsize[g[v][i]];
	}
	int bad = -1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (subsize[to] * 2 > subsize[v])
			bad = g[v][i];
	}
	if (bad == -1)
	{
		centroid[v] = v;
		return;
	}
	centroid[v] = centroid[bad];
	while (subsize[centroid[v]] * 2 < subsize[v])
		centroid[v] = par[centroid[v]];
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> tests;
	for (int i = 2; i <= n; i++)
	{
		int v;
		cin >> v;
		g[v].push_back(i);
		par[i] = v;
	}
	trace(1);

	for (; tests; --tests)
	{
		int v;
		cin >> v;
		cout << centroid[v] << "\n";
	}

	cin.get(); cin.get();
	return 0;
}