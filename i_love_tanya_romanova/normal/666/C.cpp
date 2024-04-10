/*
Brought back from the silence
As darkness whitened into a day
Tried to weave the pieces together
Force the past away

Mind weary of sorrow
Body tired from the way
Welcomed yet another morning
Of longing and dismay

What have I for you to offer
Besides this long haul
Wade across vast snowfields
Journey through endless moors

Death walked the earth today
Without a sound, motionless
Forced its way into my arms
Caressed me with the dark

Dragged again up to surface
From the bowels of the earth
To face yet another morning
Breath gasping black steam of death

These are our waking hours
In cold sunlight we pine away
Towards yet another morning
Till following hopeless day
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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

string st;
int tests;
int cur_size;
int whr[N];
int done[N];
vector<int> memo[N];

int DIF;

long long Pw[N];

long long fact[N], invf[N];

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
	long long res = fact[n];
	res *= invf[m];
	res %= bs;
	res *= invf[n - m];
	return res%bs;
}
long long count_ways(int n, int m)
{
	if (n < m)
		return 0;
	long long picks = C(n, m);
	return picks*Pw[n - m] % bs;
}
	
void run_solver(int sz)
{
	if (done[sz])
		return;
	done[sz] = 1;
	long long total = 0;

	++DIF;

	vector<int> v;
	v.push_back(0);
	for (int len = 1; len <N; len++)
	{
		total = total * 26 % bs;
		//if (len<10)
			//cout << count_ways(len - 1, sz - 1) << endl;

		total += count_ways(len - 1, sz - 1);
		total %= bs;
		v.push_back(total);
	}
	
	memo[DIF] = v;
	whr[sz] = DIF;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	Pw[0] = 1;
	for (int i = 1; i < N; i++)
	{
		Pw[i] = Pw[i - 1] * 25 % bs;
	}

	fact[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = fact[i - 1] * i%bs;
	}

	for (int i = 0; i < N; i++)
	{
		invf[i] = inv(fact[i]);
	}

	cin >> tests;
	cin >> st;

	run_solver(st.size());

	cur_size = st.size();

	for (; tests; --tests)
	{
		int tp;
		cin >> tp;
		if (tp == 1)
		{
			cin >> st;
			run_solver(st.size());
			cur_size = st.size();
		}
		else
		{
			int len;
			cin >> len;
			int id = whr[cur_size];
			cout << memo[id][len] << endl;
		}
	}

	cin.get(); cin.get();
	return 0;
}