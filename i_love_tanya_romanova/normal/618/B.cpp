/*
You've got nowhere to hide and all bullshit aside
You've committed a terrible crime
You've stepped over the line
And you'd better be running for your life

Fucked over again, I even called you a friend
A mistake I won't be repeating
I just don't understand
How you can even continue to deny

You know why?
(You don't remember why)
Don't you pretend that you don't know why
(You fucking parasite)
Because you're living through
Association that has been getting you high
You sell your soul for just a taste of my life

Now what a surprise, to discover the lies
You'll be telling again in no time
You just don't realize they'll come back
And be fucking up your life

In trouble again, I just don't understand
This whole pattern that keeps repeating
You know, you'll do it again
And admit you can step into the light

You know why?
(You don't remember why)
Don't you pretend that you don't know why
(You fucking parasite)
Because you're living through
Association that has been getting you high
You sell your soul for just a taste of my life

Determination has been running on high
No control, for just a taste of my life
Because your association has been getting you high
You sell your soul for just a taste of my life

Determination has been running on high
No control, for just a taste of my life
For just a taste of my life

You've got nowhere to hide and all bullshit aside
You've committed a terrible crime
You've stepped over the line
And you'd better be running for your life
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 100;

using namespace std;

int n, ar[N][N];
int ans[N], used[N];

bool is_ok(int val, int ps)
{
	for (int i = 1; i <= n; i++)
	{
		if (i == ps)
			continue;
		if (used[i])
			continue;
		if (ar[ps][i] != val || ar[i][ps] != val)
			return false;
	}
	return true;
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
		for (int j = 1; j <= n; j++)
		{
			cin >> ar[i][j];
		}
	}

	for (int val = 1; val <= n; val++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (is_ok(val, i))
			{
				ans[i] = val;
				used[i] = 1;
				break;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}