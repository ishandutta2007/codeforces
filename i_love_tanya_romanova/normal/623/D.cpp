/*
A deep voice is rising
From the heart of the mountain
Vibrations of the stone
I can hear in my heart

The call of instinct
The flight of the powerful
I hunger for it
It just keeps me alive

I met the dragon
In a cave by the mountain
Now I bring the evidence
The beast is alive

This ageless army
Will strike in the morning
And then a star will rise
And shine in the sky

But I grow impatient
Cannot stand the wait
And I start to dig
Within me
This tunnel to I

In this region of me
A great dragon is lying
On the wealth of a mighty world
My own world inside

I saw
I saw monsters
And I
And I started to dig within
When I
When I turn my back on them
They devour me
In this region of me
A dragon is lying there
Awake
Monster
Monsters kings
Do not scorn them
But do not fear them
Muster
Muster thy army
Dragons are the myth alive
In the heart of men
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
#include <unordered_set>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 1100000;

using namespace std;

int n;
long double prob[N];
long double ev[N];
long double ans;
long double sum[N];
long double chance_alive[N];
long double win[N];
long double pref[N], suf[N];

long double eval(int ps)
{
	long double all_dead = 1.0;
	all_dead *= pref[ps-1];
	all_dead *= suf[ps + 1];
	all_dead *= (1.0 - chance_alive[ps] * (1.0 - prob[ps]));
	return all_dead;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> prob[i];
//		prob[i] = 1;
		prob[i] *= 1.0 / 100;
		chance_alive[i] = 1;
	}

	sort(prob+1, prob + n+1);
	reverse(prob+1, prob + n + 1);

	for (int iter = 1; iter <= 1000000; iter++)
	{
		int bp = 1;
		long double bres = -1;
		pref[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			pref[i] = pref[i - 1] * (1.0 - chance_alive[i]);
		}
		suf[n + 1] = 1;
		for (int i = n; i; --i)
		{
			suf[i] = suf[i + 1] * (1.0 - chance_alive[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			long double val_here = eval(i);
			if (val_here > bres)
			{
				bres = val_here;
				bp = i;
			}
		}

		if (iter <= n)
			bp = iter;
		chance_alive[bp]*= (1.0 - prob[bp]);

		long double all_dead = 1.0;
		for (int i = 1; i <= n; i++)
		{
			all_dead *= (1.0 - chance_alive[i]);
		}
		win[iter] = all_dead;
		ans += (win[iter] - win[iter - 1])*iter;
	}
	/*
	for (int i = 100; i <= 1000; i += 100)
	{
		cout << win[i] << endl;
	}*/

	cout.precision(12);
//	cout << fixed << win[700000] << endl;
	cout << fixed<<ans << endl;

	cin.get(); cin.get();
	return 0;
}