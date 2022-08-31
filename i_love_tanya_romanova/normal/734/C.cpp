/*
A Blank Expression
Pales eyes wide cocked back
The sheer stagnation
Shame to all who thought this an act
The best years of this life
Felt wasted protecting a secret
Insecurities fed on like a rat

Depression
True fears of dependency
Affliction
The scars on such a fragile little body

Look
Take a look inside the horror
Take a look inside
Visualize the horrors inside
Burning Sensation
To live just one day
In pure elation

Blame the ones who took this away
Can't provide shelter from
The dangers festering outside
Can't provide safety from
Monsters trapped within the mind
Depression
True fears of dependency
Affliction
The scars on such a fragile little body

Look
Take a look inside the horror
Take a look inside
Visualize the horrors inside
Shake the hand of God
As the blade moves closer
The reflection is brighter than the sun
The perception becomes weaker

The sun starts to fade away
The blank expression on the blade
Skin Calloused yet easy to pierce
On the floor, blood mixed with, tears

Look
Take a look inside the horror
Take a look inside
Visualise the horrors inside
Shake the hand of God
As the blade moves closer
The reflection is brighter than the sun
The perception becomes weaker
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
const int N = 200031;

int n, m, k;
int x, s, a[N], b[N], c[N], d[N];
long long ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> k;
	cin >> x >> s;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}

	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> d[i];
	}

	ans = 1ll * n*x;

	for (int i = 1; i <= m; i++)
	{
		if (b[i] <= s)
		{
			ans = min(ans, n * 1ll * a[i]);
		}
	}

	for (int i = 1; i <= k; i++)
	{
		if (d[i] <= s)
			ans = min(ans, (n - c[i]) * 1ll * x);
	}

//	cout << ans << endl;

	for (int i = 1; i <= m; i++)
	{
		if (b[i] > s)
			continue;
		int rem_money = s - b[i];
		int ps = lower_bound(d + 1, d + k + 1, rem_money + 1) - d;
		if (ps == 1)
			continue;
		--ps;
		int taken = c[ps];
		ans = min(ans, (n - taken) * 1ll * a[i]);
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}