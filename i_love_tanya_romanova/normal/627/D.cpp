/*
Can you sense our somewhat misaligned
Attention spans, uninterested minds
Feels like only white noise on the air
A substance without meaning
Who are we?
And why should we believe?

How much more of this can you contain?
Why is it your head feels like a drain?
But you don't have to be an end-link in this chain
Become our counter-culture
Broadcast yourself into
The revolution on YouTube

I don't wanna know
Kill the radio
I will find my own transmission in the storm
Hurry on below
With the antidote
I wanna see the underground
Rise up and soar

Sick of pimps and bland generic blondes?
And poser wannabe fake rocker spawns?
Come now be your own media whore
Become our counter-culture
Unleash yourself it's free
The generation and the seas

It's the way to go
Kill the radio
Time to make your own transmission in the storm
Hurry on below
With the antidote
I wanna see the underground
Rise up and soar

I don't wanna know
Kill the radio
I will find my own transmission in the storm
Hurry on below
With the antidote
I wanna see the underground
Rise up and...

It's the way to go
Kill the radio
Time to make your own transmission in the storm
Hurry on below
With the antidote
I wanna see the underground
Rise up and soar
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
#define bsize 512

const int N = 205000;

using namespace std;

int n, k, ar[N];
vector<int> g[N];
int BOUND;
int subsize[N], cbad[N], used[N];

void trace(int v)
{
	used[v] = 1;
	subsize[v] = 1;
	if (ar[v] < BOUND)
		cbad[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		trace(to);
		subsize[v] += subsize[to];
		cbad[v] += cbad[to];
	}
}

int best;

int solve(int v)
{
	used[v] = 1;
	vector<int> good, bad;

	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		int here=solve(to);
		if (cbad[to] == 0)
			good.push_back(here);
		else
			bad.push_back(here);
	}
	if (ar[v] < BOUND)
		return 0;
	sort(good.begin(), good.end());
	sort(bad.begin(), bad.end());
	reverse(good.begin(), good.end());
	reverse(bad.begin(), bad.end());
	int res = 1;
	for (int i = 0; i < good.size(); i++)
		res += good[i];
	int memo = res;
	for (int i = 0; i < 2 && i < bad.size(); i++)
		res += bad[i];
	int bad_out = cbad[1] - cbad[v];
	if (bad_out == 0)
		res += n - subsize[v];
	best = max(best, res);
	res = memo;
	for (int i = 0; i < 1 && i < bad.size(); i++)
		res += bad[i];
	return res;
}

bool check(int thold)
{
	BOUND = thold;
	for (int i = 1; i <= n; i++)
	{
		subsize[i] = cbad[i] = used[i] = 0;
	}
	trace(1);

	best = 0;
	for (int i = 1; i <= n; i++)
		used[i] = 0;
	solve(1);
	if (best >= k)
		return 1;
	return 0;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int l, r;
	l = 0;
	r = 1e9;

	while (l < r)
	{
		int mid = l + r + 1;
		mid /= 2;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	
	cout << l << endl;

	cin.get(); cin.get();
	return 0;
}