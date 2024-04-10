/*
I don't want to be hostile.
I don't want to be dismal.
But I don't want to rot in an apathetic existance either.
See
I want to believe you,
and I want to trust
and I want to have faith to put away the dagger.

But you lie, cheat, and steal.
And yet
I tolerate you.
Veil of virtue hung to hide your method
while I smile and laugh and dance
and sing your praise and glory.
Shroud of virtue hung to mask your stigma
as I smile and laugh and dance
and sing your glory
while you
lie, cheat, and steal.
How can I tolerate you.

Our guilt,our blame,
I've been far too sympathetic.
Our blood, our fault.
I've been far too sympathetic.

I am not innocent.
You are not innocent.
Noone is innocent.

I will no longer tolerate you
Even if I must go down beside you.
Because,
Noone is innocent.
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

const int N = 110000;

using namespace std;

int n, k, ar[N];
long long t[N * 4];
long long dp[N];

void add(int v, int tl, int tr, int ps, long long val)
{
	if (tl == tr)
	{
		t[v] += val;
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	if (ps <= tm)
		add(v * 2, tl, tm, ps, val);
	else
		add(v * 2 + 1, tm + 1, tr, ps, val);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

long long get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0;
	if (tl == l&&tr == r)
		return t[v];
	int tm = tl + tr;
	tm /= 2;
	return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
	}

	for (int lev = 1; lev <= k; lev++)
	{
		for (int i = 0; i <= 4 * n; i++)
			t[i] = 0;

		for (int i = 1; i <= n; i++)
		{
			long long sum = get(1, 1, n, 1, ar[i] - 1);
			add(1, 1, n, ar[i], dp[i]);
			dp[i] = sum;
//			cout << i << "%" << sum << endl;

//			add(1, 1, n, ar[i], sum);
		}
	}

	//cout << get(1, 1, n, 1, n) << endl;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += dp[i];
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}