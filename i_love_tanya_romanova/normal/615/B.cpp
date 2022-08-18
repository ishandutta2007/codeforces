/*
You get high
With your destructive instinct
You get high
With your corrosive instinct

Where can I go
To escape your foul mind trick
You're trying it more
But you will never break me

'Cause you presume the winner is you
But that's not true
So say just words to me

Unreal what your hate's providing
Say just words to me
Your talk is always contradiction
Say just words to me

You won't feel the warmth of friends around you
Say just words to me
Is it true that there is worth inside
So say just words to me

Your desires
Are all the worse from power craving
Your desires
Are only where there's fire burning

I'll show you the way
A pleasure that's for the talking
You're trying it more
But you won't get satisfaction

'Cause you presume the winner is you
But that's not true
So say just words to me

Unreal what your hate's providing
Say just words to me
Your talk is always contradiction
Say just words to me

You won't feel the warmth of friends around you
Say just words to me
Is it true that there is worth inside
So say just words to me

Unreal what your hate's providing
Say just words to me
Your talk is always contradiction
Say just words to me

You won't feel the warmth of friends around you
Say just words to me
Is it true that there is worth inside
So say just words to me
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

#define eps 1e-8
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 200050;

using namespace std;

int n, m;
vector<int> g[N];
int dp[N];
long long ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i], 1);
		for (int j = 0; j < g[i].size(); j++)
		{
			int to = g[i][j];
			if (to < i)
				continue;
			dp[to] = max(dp[to], dp[i] + 1);
		}
		ans = max(ans, dp[i] * 1ll * g[i].size());
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}