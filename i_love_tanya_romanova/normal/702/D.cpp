/*
Is it the emptiest of
All your broken hearted feelings
A serious misconception
To choose a path that led to ruin

I live for today
Can't get away from the burning inside
Ashes to ash
Dust to dust

So quick to point the finger
When you're the source of your condition
Why should I feel sympathy
When you only show me nothing

I live for today
Can't get away from the burning inside
Ashes to ash
Dust to dust

I could stare for a thousand years
Penetrate your deepest fears
Leave you cold with a faceless embrace
Then disappear without a trace

I live for today
Can't get away from the burning inside
Ashes to ash
Dust to dust
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200000;

long long d, k, a, b, t;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> d >> k >> a >> b >> t;

	long long ans = 5e18;
	//always use

	long long ful = d / k;
	if (d%k == 0)
	{
		--ful;
	}
	long long T_need = a*d + t*ful;
	ans = min(ans, T_need);

	// walk only

	ans = min(ans, b*d);

	// drop 1st break

	if (d >= k)
	{
		long long res = k*a + (d - k)*b;
		ans = min(ans, res);
	}

	// drop last break

	if (d >= k)
	{
		long long ttl = d / k;
		for (long long p = ttl; p >= ttl - 10 && p >= 1; --p)
		{
			long long res = p*k*a + (p - 1)*t + (d - p*k)*b;
			ans = min(ans, res);
		}
/*		long long ful = d / k;
		long long res = ful*k*a + (ful - 1)*t;
		res += (d - (ful*k))*b;
		ans = min(ans, res);*/
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}