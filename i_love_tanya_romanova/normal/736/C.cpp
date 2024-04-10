/*
I can't wait to hear your voice again
I am far from lonely but without you I'm a mess
I close my eyes and drift away
And I'm wondering what you're doing now

When I look at you I see me
We will always be part of history
When I look at you I see me
Forever I will always be

Mind and soul we are the same
A hand on your heart, you know I am there
You are my lighthouse in the dark
I can see you from a thousand miles

Forever I will always be

When I look at you I see me
We will always be part of history
When I look at you I see me
Forever I will always be

I hope you feel that nothing dies
I am alive in all you touch
Close my eyes and drift away
Wondering what you're doing know
(Wondering what you're doing right now)

When I look at you I see me
We will always be part of history
When I look at you I see me (I see me)

When I look at you I see me
We will always be part of history
When I look at you I see me
Forever I will always be
*/

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

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 122231;

int n, k;
vector<int> g[N];
int used[N];
int done[150][150][150];
int memo[150][150][150];
vector<int> sons[N];
int max_dep[N];

void dfs(int v)
{
	used[v] = 1;
	max_dep[v] = 0;

	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		sons[v].push_back(to);
		dfs(to);
		max_dep[v] = max(max_dep[v], max_dep[to] + 1);
	}
}

int solve(int v, int top1,int covered_pref)
{
	if (done[v][top1][covered_pref])
		return memo[v][top1][covered_pref];
	done[v][top1][covered_pref] = 1;
	
	if (top1 == 100) // no black
	{
		memo[v][top1][covered_pref] = (covered_pref > max_dep[v]);
		return memo[v][top1][covered_pref];
	}

	if (top1 > k&&covered_pref==0)
	{
		memo[v][top1][covered_pref] = 0;
		return 0;
	}

	long long ways[2], nways[2];
	ways[0] = ways[1] = nways[0] = nways[1] = 0;

	if (top1 == 0) // should put black
	{
		ways[1] = 1;
	}
	else
	{
		ways[0] = 1; // can't put black
	}

	for (int i = 0; i < sons[v].size(); i++)
	{
		int to = sons[v][i];
		for (int j = 0; j < 2; j++)
			nways[j] = 0;

		int new_pref = max(covered_pref - 1, k - top1); // # of vertices
		if (new_pref < 0)
			new_pref = 0;

		for (int dep_there = 0; dep_there <= 100; dep_there++)
		{
			int is_ok_dep = 1;
			if (dep_there+1 < top1) // better than top
				is_ok_dep = 0;
			if (dep_there == 100)
			{
				if (new_pref <= max_dep[to])
					is_ok_dep = 0;
			}
			else
			{
				int covered2 = dep_there - k;
				if (covered2>new_pref)
					is_ok_dep = 0;
			}
			if (is_ok_dep==0) // some trash picked
				continue;

			if (solve(to, dep_there,new_pref) == 0)
				continue;

			//cout << v << "%" << to << " " << dep_there << " " << new_pref << " "<<top1<<endl;

			for (int j = 0; j < 2; j++)
			{
				nways[j | ((dep_there+1) == top1)] = 1ll * nways[j | ((dep_there+1) == top1)] +1ll*ways[j]* solve(to, dep_there,new_pref) % bs;
				nways[j | ((dep_there+1) == top1)] %= bs;
			}
		}
		for (int j = 0; j < 2; j++)
		{
			ways[j] = nways[j];
		}
	}

	memo[v][top1][covered_pref] = ways[1];
	return memo[v][top1][covered_pref];

}

int main(){
	//freopen("king.in","r",stdin);
	//freopen("king.out","w",stdout);
//	freopen("F:/input.txt", "r", stdin);
//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int a, b;
	//	a = rand() % i + 1;
	//	b = i + 1;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	//dfs(1);

	int root = rand() % n + 1;

	dfs(root);

	int res = 0;
	for (int i = 0; i <= k; i++)
	{
		res += solve(root, i,0);
		//cout << "@" << solve(1, i, 0) << endl;

		res %= bs;
	}

/*	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k+1; j++)
		{
			cout << solve(i, j,0) << " ";
		}
		cout << endl;
	}
	*/
	cout << res << endl;

	cin.get(); cin.get();
	return 0;
}