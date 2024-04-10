/*
You live your life so seriously
With fear of trying while others see
In a flash this care can turn into dust

Why always act so carefully?
Why care about the world, indeed?
No one feels the same about you

Lessons from one life and all betrayals
With no more tears to erase
The mess and the stains inside my veins
My soul flies far away

The scream of an angel
My soul flies away
The scream of an angel
Stuck on my heart

It's hard to believe my angel died
Maybe one day I'll learn to cry
I'm trying to breathe, I'm paralyzed

The scream of an angel
My soul flies away
The scream of an angel
Stuck on my heart

When the shade comes to get you
To grab your soul taking control
It's time to hear the scream of an angel
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
#define bs 100000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 500331;

int n, t;
long double am[200][200];
int ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> t;
	for (int i = 1; i <= t; i++)
	{
		am[1][1] += 1;
		for (int j = 1; j <= n; j++)
		{
			for (int q = 1; q <= j; q++)
			{
				double ohead = am[j][q] - 1.0;
				if (ohead < 0)
					continue;
				am[j][q] = 1;
				am[j + 1][q] += ohead / 2;
				am[j + 1][q + 1] += ohead / 2;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (am[i][j] > 1.0 - 1e-12)
				ans++;
		}
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}