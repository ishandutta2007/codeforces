/*
Often you wake up by nocturnal emissions
But you feel no pleasure, no real satisfaction
Dreams mislead you with blanishment
You can't spend it on sweets or touch it, my friend

They divide you for yourself pollution
Have a hard-on for yourself and your bad illusions
Proceed to action with a snatch to crawl
You know you have to do it now

You consider your obnoxious misdeeds
Get a kick out of fruits you would like to greed
A place of joy, put yourself out of misery
A one night stand for the sake of variety

A vaginal victim, unable to resist
Discover your ass sweep off your feet
Don't hink twice and jump at the chance
Don't harass yourself, screw for deliverance

Abuse
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

long long INF = 1e9;
const int N = 102231;

int n;
string tp[N];
int r[N], b[N];

int dp[1 << 16][265];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tp[i] >> r[i] >> b[i];
	}

	for (int mask = 0; mask < (1 << 16); mask++)
	{
		for (int red_economy = 0; red_economy <= 256; red_economy++)
		{
			dp[mask][red_economy] = -1e9;
		}
	}

	dp[0][0] = 0;

	for (int mask = 0; mask < (1 << n); mask++)
	{
		int cur_cost_r = 0;
		int cur_cost_b = 0;
		int cnt_r = 0;
		int cnt_b = 0;

		for (int i = 0; i < n; i++)
		{
			if (mask&(1 << i))
			{
				cur_cost_r += r[i];
				cur_cost_b += b[i];
				if (tp[i] == "R")
					cnt_r++;
				else
					cnt_b++;
			}
		}
		for (int eco_r = 0; eco_r <= cnt_r*(cnt_r + cnt_b); eco_r++)
		{
			if (dp[mask][eco_r] < 0)
				continue;
			for (int take_now = 0; take_now < n; take_now++)
			{
				if (mask&(1 << take_now))
					continue;
				int neco_r = r[take_now] - max(r[take_now] - cnt_r, 0);
				int neco_b = b[take_now] - max(b[take_now] - cnt_b, 0);
			//	cout <<"%"<< mask << " " << eco_r << " " << neco_r << " " << neco_b << endl;

				dp[mask | (1 << take_now)][eco_r + neco_r] = max(dp[mask | (1 << take_now)][eco_r + neco_r], dp[mask][eco_r] + neco_b);
			}
		}
	}

	int total_r = 0;
	int total_b = 0;

	for (int i = 0; i < n; i++)
	{
		total_r += r[i];
		total_b += b[i];
	}

	int ans = 1e9;

	for (int eco_r = 0; eco_r <= 256; eco_r++)
	{
		if (dp[(1 << n) - 1][eco_r] < 0)
			continue;
		int need_r, need_b;
		need_r = total_r - eco_r;
		need_b = total_b - dp[(1 << n) - 1][eco_r];
		int moves = max(need_r, need_b) + n;
	//	cout << need_r << " " << need_b << " " << eco_r << " " << dp[(1 << n) - 1][eco_r] << endl;

		ans = min(ans, moves);
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}