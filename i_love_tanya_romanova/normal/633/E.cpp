/*
Fifteen days and nights
Out here in the wild
What is it that I'm hunting for
I'm not sure

It is moving fast
Through its native land
It is always one day ahead
Out of sight

Bring on the storm
Let it rage on

Won't give up, not this time
Can't stop now, anymore
It's time to finally gain the ground

I call upon the sky
Strike me with all your might
And see if I will turn around

Bring on the storm
Let it rage on
Make all my fears take form
Let it rain on my castle's keep
My mountain and my ocean's deep
Bring on the storm
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

const int N = 1000010;

using namespace std;

int n, k, v[N], c[N];
int maxv[20][N];
int minc[20][N];
int L[N];
vector<int> V;
long double fact[N];

int eval1(int l, int r)//maxv*100
{
	int lev = L[r - l + 1];
	return max(maxv[lev][l], maxv[lev][r - (1 << lev) + 1]) * 100;
}

int eval2(int l, int r)// minc
{
	int lev = L[r - l + 1];
	return min(minc[lev][l], minc[lev][r - (1 << lev) + 1]);
}

long double C(int n, int m)
{
	if (n < m)
		return -1e9;
	long double res = fact[n];
	res -= fact[m];
	res -= fact[n - m];
	return res;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> k;

	fact[0] = 0;
	for (int i = 1; i < N; i++)
		fact[i] = fact[i - 1] + log(i + .0);

	L[1] = 0;
	for (int i = 2; i < N; i++)
	{
		L[i] = L[i / 2] + 1;
	}

	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];

	for (int i = 1; i <= n; i++)
	{
		maxv[0][i] = v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		minc[0][i] = c[i];
	}

	for (int lev = 1; lev < 20; lev++)
	{
		for (int i = 1; i <= n; i++)
		{
			maxv[lev][i] = maxv[lev - 1][i];
			if (i + (1 << lev) / 2 <= n)
				maxv[lev][i] = max(maxv[lev][i], maxv[lev - 1][i + (1 << lev) / 2]);
			minc[lev][i] = minc[lev - 1][i];
			if (i + (1 << lev) / 2 <= n)
				minc[lev][i] = min(minc[lev][i], minc[lev - 1][i + (1 << lev) / 2]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int l, r;
		l = i;
		r = n;
		while (l < r)
		{
			int mid = l + r + 1;
			mid /= 2;
			int val1 = eval1(i, mid);
			int val2 = eval2(i, mid);
			if (val1 <= val2)
				l = mid;
			else
				r = mid - 1;
		}
		int val1, val2;
		val1 = eval1(i, l);
		val2 = eval2(i, l);
		val1 = min(val1, val2);

		if (l < n)
		{
			int val3 = eval1(i, l + 1);
			int val4 = eval2(i, l + 1);
			val3 = min(val3, val4);
			val1 = max(val1, val3);
		}

		V.push_back(val1);
	}

	/*
	for (int i = 0; i < V.size(); i++)
	{
	cout << V[i] << " ";
	}
	cout << endl;
	*/

	sort(V.begin(), V.end());

	long double ans = 0;

	long double total_ways = C(n, k);

	/*
	for (int i = 1; i <= 5; i++)
	{
	for (int j = 0; j <= i; j++)
	{
	cout << exp(C(i, j)) << " " << i << " " << j << endl;
	}
	}*/

	for (int i = 0; i < V.size(); i++)
	{
		long double pick_this = C(n - i - 1, k - 1);
		pick_this -= total_ways;
		//cout << pick_this << endl;
		if (pick_this>-1e70)
		{
			long double real_val = exp(pick_this);
			ans += real_val*V[i];
		}
		else
			break;
	}

	cout.precision(10);
	cout << fixed << ans << endl;

	cin.get(); cin.get();
	return 0;
}