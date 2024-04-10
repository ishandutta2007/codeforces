/*
Lost inside the system, locked away without a key
No one will ever miss a menace to society
A gross lack of potential, bad decisions made in spite
A touchy hairpin trigger and such a wasted life

Trying to break the mold of a broken family
Fight against your failure, and living on his knees
Guilty of a crime of nonconformity
A hanging judge and jury handing down the penalty

A lethal injection, now they watch the body jerk
Exterminate the problem, except it didn't work

No vital sign of life, they declared it wasn't there
Coroner never checked, because he didn't fucking care
Passing off the body, they all believe he died
Starting up the hearse, now for a final drive

Like whistling past a graveyard, when walking by at night
It's a fatal illusion to think that evil never dies

In a darkened mortuary, reeking of formaldehyde
Aroused from deadly slumber, something opened up his eyes
Spilling all their blood was a promise that he'd keep
Hate so strong revived him from a deep necrotic sleep
Clawing away the casket lid until his fingers bleed
He grabbed a knife and set out on a vivisection spree
A butcher, hell bent, massacring each one with his blade
From the first one to the last, he dispatched them to the grave

It's a fatal illusion...

Evil never dies
It never dies
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 102231;

int n, m, W, w[N];
int b[N];
long long dp[N], new_dp[N];
int used[N];
int cur_W, cur_B;
vector<int> cur_group;
vector<int> g[N];

void dfs(int v)
{
	used[v] = 1;
	cur_group.push_back(v);
	cur_W += w[v];
	cur_B += b[v];
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> W;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i <= W; i++)
	{
		dp[i] = -1e10;
	}
	dp[0] = 0;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		cur_W = 0;
		cur_B = 0;
		cur_group.clear();
		dfs(i);
		for (int j = 0; j <= W; j++)
		{
			new_dp[j] = dp[j];
		}
		for (int j = 0; j+cur_W <= W; j++)
		{
			new_dp[j + cur_W] = max(new_dp[j + cur_W], dp[j] + cur_B);
		}
		for (int j = 0; j < cur_group.size(); j++)
		{
			int id = cur_group[j];
			for (int cur_w = 0; cur_w <= W; cur_w++)
			{
				new_dp[cur_w + w[id]] = max(new_dp[cur_w + w[id]], dp[cur_w] + b[id]);
			}
		}
		for (int j = 0; j <= W; j++)
		{
			dp[j] = new_dp[j];
		}
	}

	long long ans = 0;
	for (int j = 0; j <= W; j++)
	{
		ans = max(ans, dp[j]);
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}