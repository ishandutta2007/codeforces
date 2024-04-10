/*
*/

#pragma GCC optimize("O3")
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
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 600331;

int n,m,used[N],deg[N];

int cnt;

vector<int> comp;
int colored[N];

vector<int> g[N];

void dfs(int v)
{
	comp.push_back(v);
	colored[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (colored[to])
			continue;
		dfs(to);
	}
}

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
		used[a]=1;
		used[b]=1;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ok=1;

	for (int i=1;i<=n;i++)
	{
		if (colored[i])
			continue;

		if (used[i])
		{
			comp.clear();
			dfs(i);
			for (int j=0;j<comp.size();j++)
			{
				int id=comp[j];
				if (deg[id]!=comp.size()-1)
					ok=0;
			}
		}
	}

	if (!ok)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;

	cin.get(); cin.get();
	return 0;
}