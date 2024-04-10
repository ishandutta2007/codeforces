/*
I know you think I'm wrong, but I'm not your tour guide
Have a guess, I don't let you look inside
Cold dry stone

What makes you want to carve your initials in me?
Rained and weathered, erasing, hard to read
Find me distant, outwardly rough, obscene
Cold dry stone

Cold and dry a stone
Cold and dry a stone

I'm not a cornerstone in a palace for you
Time will bring your very own hard truth
Not to worry, ice covered rocks still move
Cold dry stone
Cold dry stone
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
const int N = 210000;

int n, k;
int a[N], b[N];

long long need(long long am)
{
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		long long ths = 1ll * a[i] * am;
		if (ths > b[i])
			res += ths-b[i];
		if (res > 1e12)
			res = 1e12;
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
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}

	long long l, r;
	l = 0;
	r = 2e9;
	while (l < r)
	{
		long long mid = l + r+1;
		mid /= 2;
		if (need(mid) <= k)
			l = mid;
		else
			r = mid - 1;
	}

	cout << l << endl;

	cin.get(); cin.get();
	return 0;
}