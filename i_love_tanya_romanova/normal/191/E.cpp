/*
Time has come the peace can't stand
Masters of the switch now rule the land
Push the switch and send out death
Politicians warpigs shit in head

Try to run or hide
From your death
You will burn and bleed
From your head

Total death
No one escapes the burning flames
Flesh and skin decays from your face
Five megatons lie on every soul
Destroy the human race is their goal
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 210000;

using namespace std;

int n;
long long k;
int ar[N];
long long s[N];
vector<pair<long long, long long> > sums;
int at[N];

int t[N];

int get(int r)
{
	int res = 0;
	for (; r >= 0; r = (r&(r + 1)) - 1)
		res += t[r];
	return res;
}

void inc(int i, int delta)
{
	for (; i <= n + 5; i = (i | (i + 1)))
		t[i] += delta;
}

long long solve(long long x)
{
	for (int i = 0; i <= n + 5; i++)
		t[i] = 0;
	long long res = 0;
	for (int i = 0; i <= n; i++)
	{
		long long val = s[i] - x;
		int sz = upper_bound(sums.begin(), sums.end(), make_pair(val, 1000000ll)) - sums.begin();
		res += get(sz - 1);
		inc(at[i], 1);
	}
	return res;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		s[i] = s[i - 1] + ar[i];
	}

	for (int i = 0; i <= n; i++)
	{
		sums.push_back(make_pair(s[i], i));
	}

	sums.push_back(make_pair(-100000000000000000ll, 0ll+n + 1));
	sort(sums.begin(), sums.end());

	for (int i = 0; i < sums.size(); i++)
	{
		at[sums[i].second] = i;
	}

	long long l, r;
	l = -1e18;
	r = 1e18;
	while (l < r)
	{
		long long mid = l + r+1;
		mid /= 2;
		if (solve(mid) >= k)
			l = mid;
		else
			r = mid - 1;
	}
	cout << l << endl;

	cin.get(); cin.get();
	return 0;
}