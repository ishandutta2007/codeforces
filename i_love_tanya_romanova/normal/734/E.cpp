/*
Pull up your car you're home from the night on the town
Could not find anyone to go home with to show off your insecurity
So you put your "I love you face" back on
When you are this way you think you are God
But the people around you are destroyed
Coming home getting off by killing who you love
I hope you end up in a body bag

Walk up to your room to be with your lover
Although they don't share your desire
That night frustrated and intoxicated
You need to leech onto another

When you are this way you think you are God
While the people around you are destroyed
Coming home getting off by killing who you love
I hope you end up in a body bag
Pretend you are the king

One day this will all come back to you
One day your child will be a man
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
const int N = 500031;

int n, clr[N];
vector<int> g[N];
int used[N];
int dp[N];
int ans;

void dfs(int v)
{
	used[v] = 1;
	dp[v] = 1;

	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		dfs(to);
		ans = max(ans, dp[v] + dp[to] - (clr[v] == clr[to]));
		dp[v] = max(dp[v], dp[to] + (clr[to] != clr[v]));
	}
	ans = max(ans, dp[v]);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> clr[i];
	}

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	int ohead = ans - 1;
	cout << (ohead + 1) / 2 << endl;

	cin.get(); cin.get();
	return 0;
}