/*
Waves of chaos all around
The birth of new religion
Rise from the underground
Empower enslave
Insurrection breaking down
In dark and brutal vision
Symphonic violent sound
The symbol is raised

This is nouveau supremacy
A neo nightmare
The wolf is rising from its lair
There is no turning back

The code is black
The code is black
Rise
This is the new world order

Pulling on the strings of hate
Sadistic revolution
Crushing subhuman faith
Objective engaged
Killing becomes industry
Defining resolution
War on impurity
Relentless campaign

This is nouveau supremacy
A neo nightmare
The wolf is rising from its lair
There is no turning back

The code is black
The code is black
Rise
This is the new world order

Death become the weak
Only strong will survive
Machine like propaganda
Fills a nation with pride
Hatred never seen
In the speeches of peace
From the designers of a dream
Only hell can unleash
Soldiers of the storm
Shock, divide and deploy
Elitist special forces
Operate and destroy
The sacrificial lamb
At the jaws of a beast
Total destruction of a kind
And religious belief

This is nouveau supremacy
A neo nightmare
The wolf is rising from its lair
There is no turning back

The code is black
The code is black
Rise
This is the new world order
The code is black
Rise
The code is black
The code, the code is black
The code, the code is black
The code, the code is black
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

#define eps 1e-7
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;
const int M = 1555;

long long n, m, a, b, k;

long long fact[N];
long long invf[N];

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

long long C(long long n, long long m)
{
	if (m > n)
		return 0;
	long long res = fact[n];
	res *= invf[m];
	res %= bs;
	res *= invf[n - m];
	return res%bs;
}

long long chance[N];

long long sum_dp[M][M];
long long sum_prob[M];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	fact[0] = 1;
	invf[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = fact[i - 1] * i%bs;
		invf[i] = inv(fact[i]);
	}

	cin >> n >> m >> a >> b >> k;
	
	long long prob = a*inv(b) % bs;
	long long prob2 = bs +1  - prob;
	prob2 %= bs;

	//cout << prob << " " << prob2 << endl;

	for (int i = 0; i <= m; i++)
	{
		if (i > k)
			chance[i] = 0;
		else
		{
			chance[i] = pw(prob, i)*pw(prob2, k - i) % bs;
			chance[i] *= C(k, i);
			chance[i] %= bs;
		}
	}
	
	sum_dp[0][m] = 1;

	/*
	for (int i = 0; i <= 2; i++)
	{
		cout << chance[i] << " ";
	}
	cout << endl;
	*/

	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= m; j++)
		{
			sum_prob[j] += chance[i - 1] * chance[m - j] % bs;
			sum_prob[j] %= bs;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		long long lead = 0;

		for (int r = 1; r <= m; r++)
		{
			sum_dp[i][r] = sum_dp[i][r - 1];
			lead += sum_dp[i - 1][r - 1]*chance[r-1];
			lead %= bs;
			sum_dp[i][r] -= chance[m-r]* lead%bs;

			if (sum_dp[i][r] < 0)
				sum_dp[i][r] += bs;
			
			sum_dp[i][r] -= sum_dp[i-1][m-r]*sum_prob[r] % bs;
			if (sum_dp[i][r] < 0)
				sum_dp[i][r] %= bs;
			sum_dp[i][r] += sum_prob[r] * sum_dp[i - 1][m] % bs;
			sum_dp[i][r] %= bs;
		}
	}

	cout << sum_dp[n][m] << endl;

	cin.get(); cin.get();
	return 0;
}