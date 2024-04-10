/*
A man appeared before Wells Fargo
Wells Fargo's stage driver man
Wearing long white linen
And a dust flour sack over his head

Pointed a double barreled shotgun
At the driver and forced him to halt
Please throw down the box sir
And madame please I don't need your money or pearls

They call him Black Bart P08
The highway bandit poetry man
Leaving his poem, disappeared
Like a ghost on his own, all on his own
The road he owns

Rise Black Bart, rise I'm calling
Calling your spirit out
Dust off your hat and hatchet
There are boxes out there with your name and mark

The road has been cold and lonely
The road has been out of good tales
Let's shake up some dust
We'll be opening the box like before, just like before
And leave a poem

For honor and for riches
I've labored long and hard for the bread
But on my corns too long you tread
You fine haired sons of bitches

A man appeared before Wells Fargo
Wells Fargo's stage driver man
Wearing long white linen
And a dust flour sack over his head

They call him Black Bart P08
The highway bandit poetry man
Leaving his poem, disappeared
Like a ghost on his own, all on his own
The road he owns

For honor and for riches
I've labored long and hard for the bread
But on my corns too long you tread
You fine haired sons of bitches
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 300331;

int used[N];
int a[N], b[N];
vector<int> g[N];
vector<int> ans[N];
int n, m;
int shit;

void dfs(int v, int c)
{
	used[v] = c;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
		{
			if (used[to] == used[v])
				shit = 1;
			continue;
		}
		dfs(to, 3 - c);
	}
}

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
		cin >> a[i] >> b[i];
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		dfs(i, 1);
	}

	if (shit)
	{
		cout << -1 << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			ans[used[i]].push_back(i);
		}
		cout << ans[1].size() << endl;
		for (int i = 0; i < ans[1].size(); i++)
		{
			if (i)
				cout << " ";
			cout << ans[1][i];
		}
		cout << endl;
		cout << ans[2].size() << endl;
		for (int i = 0; i < ans[2].size(); i++)
		{
			if (i)
				cout << " ";
			cout << ans[2][i];
		}
		cout << endl;
	}

	cin.get(); cin.get();
	return 0;
}