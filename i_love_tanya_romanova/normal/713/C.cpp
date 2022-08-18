/*
I see invaders comin'
Runnin' over the hill
No time to sound a warning
The night is still
Hide away the parents
The band is on
Smoke is slowly rising
The youth are one

Crash the gates
Necks will break
Now they're comin' after you
Shout with rage
Rush the stage
And there's nothing you can do

Shout it out
Shout it out - We love it loud
Shout it out
Shout it out

I sense inebiation
The hordes are ready
Fists are quickly rising
The chants are steady
Stand to greet the heroes
Move your heads
Inject metal infection
Let it spread

Crash the gates
Necks will break
Now they're comin' after you
Shout with rage
Rush the stage
And there's nothing you can do

Shout it out
Shout it out - We love it loud
Shout it out
Shout it out

I see invaders comin'
Runnin' over the hill
No time to sound a warning
The night is still
Hide away the parents
The band is on
Smoke is slowly rising
The youth are one

Crash the gates
Necks will break
Now they're comin' after you
Shout with rage
Rush the stage
And there's nothing you can do

Shout it out
Shout it out - We love it loud
Shout it out
Shout it out - Ah
Shout it out
Shout it out
Shout it out
Shout it out
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
const int N = 3031;

int n, ar[N];
long long dp[N][N];
vector<pair<long long, long long> > order;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		order.push_back(make_pair(ar[i] - i, i));
	}

	sort(order.begin(), order.end());

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = 1e18;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		long long val = ar[i];
		val -= (i - 1);
		dp[1][i] = abs(val - ar[1]);
	}

	for (int i = 2; i <= n; i++)
	{
		long long cur_best = 1e18;

		int ptr = 0;

		for (int j = 0; j < order.size(); j++)
		{
			while (ptr < order.size() && order[ptr].first <= order[j].first)
			{
				int id = order[ptr].second;
				cur_best = min(cur_best, dp[i - 1][id]);
				++ptr;
			}
			int id = order[j].second;
			long long val = ar[id] + (i - id);
			long long cost = cur_best + abs(val - ar[i]);
			dp[i][id] = cost;
		}

	}

	long long ans = 1e18;
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}