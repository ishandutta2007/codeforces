/*
We live for the magic in the sound, distorted guitars are breaking ground
The drum pounding faster than my heart, the vocals are screaming extreme art
The passion for metal drives us forth, the best heavy metal comes from north

The powerful tunes, spectacular shows, the audience screams in ecstasy

Metal, Metal
Back with the vengeance
Metal, Metal
All that I need is heavy metal
Metal
Screaming together
Metal, Metal
Metal is all that I need

While hell bends for leather we stand strong, a rocker can party all night long
the school couldn't teach us rock' n roll, the school couldn't help us reach our goal
We live for the magic in the sound, distorted guitars are breaking ground

The powerful tunes, spectacular shows, the audience screams in ecstasy
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
#define bs 1000000007
#define bsize 512

const int N = 1100000;

using namespace std;

vector<vector<int> >cycles[N];
int used[N];
int ans[N];
int p[N];
vector<int> cycle;
int n;

void dfs(int v)
{
	cycle.push_back(v);
	used[v] = 1;
	int to = p[v];
	if (used[to])
		return;
	dfs(to);
}

void update(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		ans[v[i]] = v[(i + 1) % v.size()];
	}
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		cycle.clear();
		dfs(i);
		cycles[cycle.size()].push_back(cycle);
	}

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0 && cycles[i].size() % 2 == 1)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		used[i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 0; j < cycles[i].size(); j++)
			{
				vector<int> V;
				for (int q = 0; q < i / 2; q++)
				{
					V.push_back(cycles[i][j][q]);
					V.push_back(cycles[i][j][(q+1) + i / 2]);
				}
				V.push_back(cycles[i][j][i / 2 ]);
				update(V);
			}
		}
		else
		{
			for (int j = 0; j < cycles[i].size(); j += 2)
			{
				vector<int> V;
				for (int q = 0; q < cycles[i][j].size(); q++)
				{
					V.push_back(cycles[i][j][q]);
					V.push_back(cycles[i][j + 1][q]);
				}
				update(V);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			printf(" ");
		printf("%d", ans[i]);
//		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}