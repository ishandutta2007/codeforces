/*
Taking chances
Will they take their toll?
Will you focus or will you lose control

Your eyes are open
Your path is chosen
You cant back down now
Youve come to falling down

And now its time to stand up and take your best shot
You made it
Just take it
This might be your once in a lifetime (take your best shot)
Dont waste it
Or youll be that faceless
Cause its once in a lifetime,
So take your best shot

Second chances
Will they come at all?
Is your mind set to use all self control?
Conscience speaking
That tells you nothing
That certain but certainly some things are worth it

So now its time to stand up and take your best shot
You made it
Just take it
This might be your once in a lifetime (take your best shot)
Dont waste it
Or youll be that faceless
Cause its once in a lifetime,
So take your best shot

Taking chances
Will they take their toll?
Will you focus or will you lose control?
Will you make it?
Will you make it?
Will you make it?
Will you make it?

You made it
Just take it
This might be your once in a lifetime (take your best shot)
Dont waste it
Or youll be that faceless
Cause its once in a lifetime, so take your best shot
Its once in a lifetime, so take your best shot
So take your best shot.
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;
/*
long long dp[100][10];
*/

long long gcd(long long a, long long b)
{
	while (a&&b)a > b ? a %= b : b %= a;
	return a + b;
}

long long pw(long long a, long long b)
{
	if (b == 0)
		return 1;
	if (b % 2)
		return a*pw(a, b - 1) % bs;
	return pw(a*a%bs, b / 2);
}

long long inv(long long x)
{
	return pw(x, bs - 2);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	/*
	dp[0][1] = 1;
	for (int iter = 1; iter <= 50; iter++)
	{
	dp[iter][0] += dp[iter - 1][1] + dp[iter - 1][0];
	dp[iter][1] += dp[iter - 1][0] + dp[iter - 1][2];
	dp[iter][2] += dp[iter - 1][1] + dp[iter - 1][2];
	cout
	<< dp[iter][1] << endl;
	}*/

	long long n;
	cin >> n;

	long long pw2 = 2;
	int parity = 0;

	for (int i = 1; i <= n; i++)
	{
		long long val;
		cin >> val;
		pw2 = pw(pw2, val);
		if (val % 2 == 0)
			parity = 1;
	}

	//cout << pw2 << " " << parity << endl;
	long long res = pw2;
	long long todivide = res;
	if (parity == 0)
		res -= 2;
	else
		res += 2;
	res %= bs;
	if (res < 0)
		res += bs;
	res *= inv(3);
	res %= bs;
	/*res *= inv(todivide);
	res %= bs;
	*/
	res *= inv(2);
	res %= bs;
	todivide *= inv(2);
	todivide %= bs;
	//		cout << gcd(res, todivide) << endl;
	cout << res << "/" << todivide << endl;

	cin.get(); cin.get();
	return 0;
}