/*
If I begin to feel lighter
Hold me down
And I'll be yours for evermore

God bless this mess I'm in
For it is time
To be rid of a certain sin

A cool breeze down my spine
And if I'm really here
Then I feel fine

A freelance child
You bring it all back
This world is eating me inside

Don't look too far
Don't look too far

Missing a degree of warmth
A name without a face
I'm losing grip all the same

I sever the line that divides
I sever the feelings inside
I sever between you and me

And I want to learn to fly
Bring the pain right back again
Is this all there is of me

Hearts and minds, find the time
That in the end there was no
Possible reason for anything

Don't look too far
Don't look too far
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

struct res
{
	long long t_w;
	long long min_w;
	long long endpoint;
};

res combine(res a, res b)
{
	res temp;
	temp.t_w = a.t_w + b.t_w;
	temp.min_w = min(a.min_w, b.min_w);
	temp.endpoint = b.endpoint;
	return temp;
}

res R[N][50];

int n;
long long k;
long long f[N];
long long w[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}

	for (int i = 0; i < n; i++)
	{
		R[i][0].t_w = w[i];
		R[i][0].endpoint = f[i];
		R[i][0].min_w = w[i];
	}
	
	for (int lev = 1; lev <= 40; lev++)
	{
		for (int i = 0; i < n; i++)
		{
			R[i][lev] = combine(R[i][lev-1], R[R[i][lev - 1].endpoint][lev - 1]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		res temp;
		temp.min_w = 1e18;
		temp.t_w = 0;
		temp.endpoint = i;

		for (long long j = 40; j >= 0; --j)
		{
			if (k&(1ll << j))
			{
				int here = temp.endpoint;
				temp = combine(temp, R[here][j]);
			}
		}
		cout << temp.t_w << " " << temp.min_w << "\n";
	}

	cin.get(); cin.get();
	return 0;
}