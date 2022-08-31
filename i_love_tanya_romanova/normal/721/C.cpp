/*
Hustle, bustle and so much muscle, aww
Cells about to separate
And I find it hard to concentrate and

Temporary this cash and carry
I'm stepping up to indicate
The time has come to deviate and

All I want is for you to be happy and
Take this moment to make you my family and
Finally you have found something perfect and
Finally you have found

Death defying this mess I'm buying
It's raining down with love and hate
And I find it hard to motivate and

Estuary is blessed but scary your
Heart's about to palpitate
And I'm not about to hesitate and

One to treasure the rest of your days here and
Give you pleasure in so many ways dear and
Finally you have found something perfect and
Finally you have found
Here we go

Do you want me to show up for duty and
Serve this woman and honor her beauty and
Finally you have found something perfect and
Finally you have found
Yourself

With me, will you, agree, to take
This man, into your world
And now, we are as one

My lone ranger the heat exchanger
Is living in this figure eight
And I'll do my best to recreate and

Sweet precision and soft collision, aww
Hearts about to palpitate
And I find it hard to separate and

All I want is for you to be happy and
Take this woman and make you my family and
Finally you have found someone perfect and
Finally you have found

All I want is for you to be happy and
Take this woman and make you my family and
Finally you have found someone perfect and
Finally you have found
Yourself
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
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;

int dp[5005][5005], par[5005][5005];

int n, m, T;
vector<pair<int, int> > g[N];
int used[N];
vector<int> av;
int ans;
vector<int> order;

void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if (used[to])
			continue;
		dfs(to);
	}
	order.push_back(v);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> T;

	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
	}

	dfs(1);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = 1e9 + 1e6;
		}
	}

	dp[1][1] = 0;
	reverse(order.begin(), order.end());

	for (int ii = 0; ii < order.size(); ii++)
	{
		int i = order[ii];
		for (int cnt = 0; cnt <= n; cnt++)
		{
			if (dp[i][cnt]>T)
				continue;
			for (int q = 0; q < g[i].size(); q++)
			{
				int to = g[i][q].first;
				int cost = g[i][q].second + dp[i][cnt];
				if (cost < dp[to][cnt + 1])
				{
					dp[to][cnt + 1] = cost;
					par[to][cnt + 1] = i;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dp[n][i] <= T)
		{
			ans = i;
		}
	}

	cout << ans << endl;

	for (; ans; --ans)
	{
		av.push_back(n);
		n = par[n][ans];
	}
	reverse(av.begin(), av.end());
	for (int i = 0; i < av.size(); i++)
	{
		if (i)
			cout << " ";
		cout << av[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}