/*
I could be mean
I could be angry
You know I could be just like you

I could be fake
I could be stupid
You know I could be just like you

You thought you were standing beside me
You were only in my way
You're wrong if you think that I'll be just like you
You thought you were there to guide me
You were only in my way
You're wrong if you think that I'll be
Just like you

I could be cold
I could be ruthless
You know I could be just like you

I could be weak
I could be senseless
You know I could be just like you

You thought you were standing beside me
You were only in my way
You're wrong if you think that I'll be just like you
You thought you were there to guide me
You were only in my way
You're wrong if you think that I'll be
Just like you

On my own, cause I can't take livin' with you
I'm alone, so I won't turn out like
You want me to

You thought you were standing beside me
You were only in my way
You're wrong if you think that I'll be just like you
You thought you were there to guide me
You were only in my way
You're wrong if you think that I'll be
Just like you

I could be mean
I could be angry
You know I could be just like you
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

const int N = 11000;

using namespace std;

int cnt[N];
int ways[N];
long double dp[11][N];
int n;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		cnt[val]++;
	}

	for (int dif = 1; dif <= 5000; dif++)
	{
		for (int i = 1; i <= 5000; i++)
		{
			if (cnt[i] == 1 && cnt[i + dif] == 1)
				++ways[dif];
		}
	}

	dp[0][0] = 1;
	for (int mov = 1; mov <= 2; mov++)
	{
		for (int old_ohead = 0; old_ohead <= 5000; old_ohead++)
		{
			for (int add = 1; add <= 5000; add++)
			{
				dp[mov][old_ohead + add] += dp[mov - 1][old_ohead] * ways[add];
			}
		}
	}

	long double ans = 0;

	for (int dif_was = 1; dif_was <= 5000; dif_was++)
	{
		for (int dif_now = dif_was + 1; dif_now <= 5000; dif_now++)
		{
			ans += ways[dif_now] * dp[2][dif_was];
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		ans /= (1.0*n*(n - 1) / 2);
	}

	cout.precision(12);
	cout << fixed << ans << endl;

	cin.get(); cin.get();
	return 0;
}