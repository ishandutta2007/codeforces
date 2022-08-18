/*
Here I am in all my majesty
There is nothing you won't get to see
Come along and I'll give you my world
In one-hundred-forty characters

Don't you try to analyze
We are just raised to reach the stars

Can't you see it's generation me
I don't need anyone or anything
I'll make it alone
Can't you see it's generation me
We don't need anyone or anything
Just leave me alone

I don't know if I spend my time in vain
In getting everyone to know my name
All I know is my face looks fucking right
From this certain angle certain light

Don't you try to criticize
It's no crime, but a product of our time
So here I am
And here I am
So here I am

Can't you see it's generation me
I don't need anyone or anything
I'll make it alone
Can't you see it's generation me
We don't need anyone or anything
Just leave me alone
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

int n, s, ar[N], ans;

int safe_sub;
int cnt[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		if (i == s&&ar[i] != 0)
			++ans;
		if (i != s&&ar[i] == 0)
			++ans,
			++safe_sub;
	}

	if (n == 1)
	{
		cout << ans << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (i == s)
			continue;
		if (ar[i] == 0)
			continue;
		cnt[ar[i]]++;
	}

	int best_forced = 1e9;

	int below = safe_sub;
	++below;
	int cnt_zeros = 0;

	for (int dep = 1; dep <= n; dep++)
	{
		below += cnt[dep];
		if (cnt[dep] == 0)
			++cnt_zeros;
		int above = n - below;
		int cur_zer=cnt_zeros-safe_sub;

		int forced_moves = max(above, cur_zer);
		if (forced_moves < best_forced)
		{
			best_forced = forced_moves;
		}
		//cout << forced_moves << "%" << above << " " << cur_zer << endl;
	}

	cout << ans + best_forced << endl;

	cin.get(); cin.get();
	return 0;
}