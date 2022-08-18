/*
It feels like yesterday
When I was told a little tale
About a broken road
A tale of fortune and of fame

There was a time
When a man couldn't find his kind
There was a rhyme
Which made a man make up his mind

In those lines I heard you say
Fare well on your way
There every root and stone and wishing well
Has a tale to tell

The air that I breathe
Is made of dreams and memories
Of past and future days
And countless new pathways

When I look behind
I see my footprints on the road
Those remind of the time
When your haven always welcomed me

In those lines I heard you say
Fare well on your way
And when the broken road turns home again
There's a tale to tell
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
#define bsize 512

const int N = 205000;

using namespace std;

long long dif, a, b;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> a >> b;
	
	dif = a - b;

	if (dif < 0||dif%2==1)
	{
		cout << 0 << endl;
		return 0;
	}

	dif /= 2;

	long long ans = 1;
	for (int i = 0; i <= 40; i++)
	{
		if (b&(1ll << i))
			ans *= 2;
		if (dif&(1ll << i))
		{
			if (b&(1ll << i))
			{
				cout << 0 << endl;
				return 0;
			}
		}
	}

	if (a == b)
		ans -= 2;

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}