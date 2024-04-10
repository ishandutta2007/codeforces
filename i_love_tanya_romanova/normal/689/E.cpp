/*
Brought into this world
Met by open arms
I was born as a hero
All the tears I wept

The tears that just kept falling
All the dreams I dreamt
Dies when the river's calling

Liars, soulless
Lairs, I am soulless

Another side of me
Oh yes it's getting stronger
Kept as a prisoner
A darker soul can't be found

All the times I've cried
The times when I was lonely
Breathing for the last time
My body's dragged down slowly

Liars, soulless
Lairs, I am soulless
Yes I, yes I am

Why won't you leave me alone?
Wont you leave me alone?
Why won't you leave
Why won't you leave me alone?

Liars, soulless
Lairs, I am soulless
Lie, lie
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
const int N = 1010031;

int n, k;
long long fact[N], invf[N];
vector<int> xs, ux;
int a[N], b[N];
int opens[N], closes[N];

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
	if (n < m)
		return 0;
	long long res = fact[n];
	res *= invf[m];
	res %= bs;
	res *= invf[n - m];
	return res%bs;
}

long long ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 250000; i++)
	{
		fact[i] = fact[i - 1] * i%bs;
	}

	for (int i = 0; i <= 250000; i++)
	{
		invf[i] = inv(fact[i]);
	}

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		xs.push_back(a[i]);
		xs.push_back(b[i]);
	}

	sort(xs.begin(), xs.end());
	for (int i = 0; i < xs.size(); i++)
	{
		if (i == 0 || xs[i] != xs[i - 1])
			ux.push_back(xs[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		int lid = lower_bound(ux.begin(), ux.end(), a[i]) - ux.begin();
		int rid = lower_bound(ux.begin(), ux.end(), b[i]) - ux.begin();
		
		opens[lid]++;
		closes[rid]++;
	}

	int cur_open = 0;

	for (int i = 0; i < ux.size(); i++)
	{
		cur_open += opens[i];
		ans += C(cur_open, k);
		ans %= bs;
		cur_open -= closes[i];
	}

	//cout << ans << endl;

	for (int i = 0; i+1 < ux.size(); i++)
	{
		cur_open += opens[i];
		cur_open -= closes[i];
		ans += C(cur_open, k)*(ux[i+1] - ux[i]-1);
		ans %= bs;
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}