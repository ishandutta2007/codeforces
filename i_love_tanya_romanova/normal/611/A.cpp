/*
I've been waiting for you for hours, babe
And you still ain't here
Waiting, waiting, hanging on the phone
It feels like a hundred years

You always keep me hanging on
Driving me crazy all the time
But when it comes down to fooling around
You're the one that rings my chimes

Come on now, honey, spend my money
Take me around the world
All this time, out of my mind
A really nasty girl

English rose, a crown of thorns
I hope you're staying around
English rose, a long, long time
Before you wear me down

The first time and it was amazing
But the next time's gonna be hell
I know your momma thinks
You're a sweet young thing
But she don't know you too well

Come on now, lover, don't run for cover
You're the one I deserve
All this time, way out of line
A great nasty girl

English rose, a crown of thorns
Don't you let me down
English rose, a long, long time
You should be wearing the crown

A long time we been lovers
A long time doing that stuff
A long time I been waiting here
But I still ain't had enough

Come on now, woman, hold on, I'm coming
I'm just a bundle of nerves
Stay right there, you ain't going nowhere
Be my nasty girl

Come on now, baby, drive me crazy
Take me around the world
You're so fine, just making time
A real nasty girl

English rose, a crown of thorns
You better stick around
English rose, a long, long time
You'll never wear me down

English rose, English rose, growing wild
I like to keep you unwound
English rose, gonna be a long, long time
Before you wear me down
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 105000;

using namespace std;

int dw, d, m, ans1[N], ans2[N];
string st;
int n;

int gl(int x)
{
	if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
		return 31;
	if (x == 2)
		return 29;
	return 30;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("C:/input.txt","r",stdin);
	//freopen("C:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	dw = 5;
	d = 1;
	m = 1;
	for (int i = 1; i <= 366; i++)
	{
		ans1[dw]++;
		ans2[d]++;
		++d;
		++dw;
		if (dw > 7)
			dw = 1;
		if (d > gl(m))
		{
			m++;
			d = 1;
		}
	}

	cin >> n;
	cin >> st;
	cin >> st;
	if (st == "week")
		cout << ans1[n] << endl;
	else
		cout << ans2[n] << endl;

	cin.get(); cin.get();
	return 0;
}