/*
We had fire in our eyes
In the beginning I
Never felt so alive
In the beginning you
You blame me, but
It's not fair when you say that I didn't try
I just don't want to hear it anymore

I swear, I never meant to let it die
I just don't care about you anymore
It's not fair when you say that I didn't try
I just don't care about you anymore

We had time on our side
In the beginning we
We had nothing to hide
In the beginning you
You blame me, but
It's not fair when you say that I didn't try
I just don't want to hear it anymore

I swear, I never meant to let it die
I just don't care about you anymore
It's not fair when you say that I didn't try
I just don't care about you anymore

You say that I didn't try
You say that I didn't try
You say that I didn't try

I swear, I never meant to let it die
I just don't care about you anymore
It's not fair when you say that I didn't try
I just don't care about you anymore
I just don't care about you anymore
I just don't care about you anymore
I just don't care about you anymore
I just don't care about you anymore
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 220000;

using namespace std;

int n, k, ar[N];

void add(int&a, int b)
{
	a += b;
	if (a >= bs)
		a -= bs;
}

int dp[2][201][105000];
int s[1000];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
//		ar[i] = rand() % 500;
//		ar[i] = 500;
	}

	sort(ar, ar + n);

	reverse(ar, ar + n);

	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + ar[i];

	dp[0][0][0] = 1;

	int can_del;

	for (int id = 0; id < n; id++)
	{
		for (int i = 0; i <=id; i++)
		{
			for (int j = 0; j <= id * 500;j++)
			{
				dp[1 - id % 2][i][j] = 0;
			}
		}
		for (int open_groups = 0; open_groups <= id&&open_groups<=(n-id); open_groups++)
		{
			int l, r;
			l = s[id + 1] - s[id - open_groups+1];
			r = 500 * id;
			can_del = open_groups*ar[id];
			r = min(r, can_del + k);
			for (int i =l; i <= r; i++)
			{
				// new group,open
				if (dp[id % 2][open_groups][i] == 0)
					continue;
				add(dp[1 - id % 2][open_groups + 1][i + ar[id]], dp[id % 2][open_groups][i]);
				//open&close
				add(dp[1 - id % 2][open_groups][i], dp[id % 2][open_groups][i]);
				// to exsting, keep
				int ways = 1ll * dp[id % 2][open_groups][i] * open_groups%bs;
				add(dp[1 - id % 2][open_groups][i], ways);
				//cout << id << " " << open_groups << " " << i << " " << dp[id % 2][open_groups][i] << " " << ways << endl;
				// to exstn, close
				if (open_groups)
					add(dp[1 - id % 2][open_groups - 1][i - ar[id]], ways);
			}
		}
	}
	/*
	for (int i = 100000; i <= 100010; i++)
	{
		cout << i << " " << dp[n % 2][0][i] << endl;
	}
	*/
	int ans = 0;
	for (int i = 0; i <= k; i++)
	{
		add(ans, dp[n % 2][0][i]);
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}