/*
I met a blackbird flying south tonight, I looked into her eyes tonight
I saw her wings were getting tired, still looking for the light
There is evil on the way, it will come with break of day
I heard her say before she turned and flew away
But for a moment there alone I could find my way back home

How it hurts still there when she comes to show
She's always near down the black brick road

I watched her heading for the southern skies when she lost her wings and died
But then I saw her flying higher when I looked into her eyes
There is evil on the way, I heard the blackbird say
It will reach us by the coming of the day
But for a moment there alone I was heading back for home

How it hurts still there when she comes to show
She's always near down the black brick road
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

#define eps 1e-8
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 1000100;
const int MAG = 4000000;

using namespace std;

long long n, m;

long long brute()
{
	long long res = 0;
	for (long long i = 1; i <= m; i++)
	{
		res = res + n%i;
		res %= bs;
	}
	return res;
}

long long bound, res;
long long ans;

pair<long long, long long> intersect(pair<long long, long long> p1, pair<long long, long long> p2)
{
	p1.first = max(p1.first, p2.first);
	p1.second = min(p1.second, p2.second);
	return p1;
}

long long sum_prog(long long l, long long r)
{
	long long mul1 = n%l + n%r;
	long long mul2 = r - l + 1;
	if (mul1 % 2 == 0)
		mul1 /= 2;
	else
		mul2 /= 2;
	mul1 %= bs;
	mul2 %= bs;
	return mul1*mul2%bs;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;

	//	cout << brute() << endl;

	for (int i = 1; i <= MAG; i++)
	{
		if (i > m || i>n)
			break;
		bound = i;
		ans = ans + n%i;
		ans %= bs;
	}

	if (bound<m&&bound<n)
	for (long long div = 1;; div++)
	{
		long long l = n / (div + 1) + 1;
		long long r = n / div;
		if (r < bound)
			break;
		pair<long long, long long> P = intersect(make_pair(l, r), make_pair(bound + 1, m));
		if (P.first <= P.second)
		{
			ans += sum_prog(P.first, P.second);
		}
		ans %= bs;
	}

	if (m>n)
	{
		long long times = (m - n);
		times %= bs;
		long long m2 = n%bs;
		ans = ans + times*m2%bs;
	}

	cout << ans %bs << endl;

	cin.get(); cin.get();
	return 0;
}