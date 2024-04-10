/*
Passion stains the godless taste
The human eye now raped and dazed
Our marks of shame soon worn away
The spider's trapped in a web of clay

Naked in the desert of delight
Banish the throughts into the night
Scarecrow servant of demise
Parting the honey from the flies

What's in the veins is what to keep
Still the floods of raptures sound asleep
Visions fade and die at ease
Inferior slaves are ours to please

The last of shadows shapes the end
From mountains high it all descends
One single dagger unleash the doom
Creation falls in my closed room
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
const int N = 7000000;

int tests;

int have[N][2];
int cnt[N];

int C;

int new_vertex()
{
	C++;
	return C - 1;
}

void add(int val,int coef)
{
	int cur_v = 0;
	for (int i = 30; i >= 0; --i)
	{
		int cb;
		if (val&(1 << i))
		{
			cb = 1;
		}
		else
			cb = 0;
		if (!have[cur_v][cb])
		{
			have[cur_v][cb] = new_vertex();
		}
		cur_v = have[cur_v][cb];
		cnt[cur_v] += coef;
	}
}

bool check(int a, int b)
{
	if (have[a][b] == 0)
		return 0;
	int to = have[a][b];
	if (cnt[to] == 0)
		return 0;
	return 1;
}

int solve(int val)
{
	int cur = 0;
	int res = 0;
	for (int i = 30; i >= 0; --i)
	{
		int cb = 0;
		if (val&(1 << i))
			cb = 1;
		cb ^= 1;
		int ok = check(cur, cb);
		if (ok == 1)
		{
			res += (1 << i);
			cur = have[cur][cb];
		}
		else
			cur = have[cur][cb ^ 1];
	}
	return res;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	C = 1;

	cin >> tests;

	add(0, 1);

	for (; tests; --tests)
	{
		string tp;
		cin >> tp;
		int val;
		cin >> val;
		if (tp == "+")
		{
			add(val, 1);
		}
		if (tp == "-")
		{
			add(val, -1);
		}
		if (tp == "?")
		{
			int res = solve(val);
			cout << res << "\n";
		}
	}
	cin.get(); cin.get();
	return 0;
}