/*
She nursed him there, ooh, over a night
Wasn't so sure she wanted him to stay
What to say, what to say
But soon she was down, soon he was low

At a quarter past a holy no
She had to turn around

When she couldn't hold, oh, she folded
A dissident is here
Escape is never the safest path
Oh, a dissident, a dissident is here

And to this day, she's glided on
Always home but so far away
Like a word misplaced
Nothing to say, what a waste

When she had contact with the conflict
There was meanin', but she sold him to the state
She had to turn around

When she couldn't hold, she folded
A dissident is here
Escape is never the safest path
Oh, a dissident, a dissident is here, oh

She gave him away
When she couldn't hold, no, she folded
A dissident is here
Escape is never the safest path
Oh, a dissident, a dissident is here, oh

Couldn't hold on, she couldn't hold, no, she folded
A dissident is here
Escape is never the safest place, oh
A dissident is here
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
const int N = 1000031;

vector<vector<long long> > mult(vector<vector<long long> > a, vector<vector<long long> > b)
{
	vector<vector<long long> > res;
	res = a;
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res.size(); j++)
		{
			res[i][j] = 0;
		}
	}
	for (int k = 0; k < res.size(); k++)
	{
		for (int i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < res.size(); j++)
			{
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % bs;
			}
		}
	}
	return res;
}

vector<vector<long long> >pw(vector<vector<long long> > a, long long b)
{
	if (b == 1)
		return a;
	if (b == 0)
	{
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a.size(); j++)
			{
				a[i][j] = (i == j);
			}
		}
		return a;
	}

	if (b % 2)
		return mult(a, pw(a, b - 1));
	return pw(mult(a,a), b / 2);
}

int n;
long long k, ar[1000];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i-1];
	}

	vector<vector<long long> > res;
	res.resize(n);
	for (int i = 0; i < res.size(); i++)
	{
		res[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			res[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long long val = (ar[i] ^ ar[j]);
			long long cnt = 0;
			for (int q = 0; q < 63; q++)
			{
				if (val&(1ll << q))
					++cnt;
			}
			if (cnt % 3 == 0)
				res[i][j]++;
		}
	}

	res = pw(res, k - 1);

	long long ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans = ans + res[i][j];
		}
	}
	cout << ans%bs << endl;

	cin.get(); cin.get();
	return 0;
}