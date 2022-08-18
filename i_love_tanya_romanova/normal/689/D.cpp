/*
I see the world
Feel the chill
Which way to go
Windowsill

I see the words
On a rocking horse of time
I see the birds in the rain

Oh dear dad
Can you see me now
I am myself
Like you somehow

I'll ride the wave
Where it takes me
I'll hold the pain
Release it

Oh dear dad
Can you see me now
I am myself
Like you somehow

I'll wait up in the dark
For you to speak to me
I'll open up
Release me
Release me
Release me
Release me
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
const int N = 410031;

pair<int, int> t[N];
int a[N], b[N];
int ans1;
long long ans;
int n;
int st1[20][N], st2[20][N];

pair<int, int> combine(pair<int, int> &p1, pair<int, int>& p2)
{
	pair<int, int> res;
	res.first = max(p1.first, p2.first);
	res.second = min(p1.second, p2.second);
	return res;
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = make_pair(a[tl], b[tl]);
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = combine(t[v * 2], t[v * 2 + 1]);
}

/*pair<int, int> get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
	{
		return make_pair(-2000000000, 2000000000);
	}
	if (tl == l&&tr == r)
		return t[v];
	int tm = tl + tr;
	tm /= 2;
	pair<int, int> p1, p2;
	p1 = get(v * 2, tl, tm, l, min(r, tm));
	p2 = get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
	return combine(p1, p2);
}
*/

int L[N];

pair<int, int> get(int l, int r)
{
	int span = r - l + 1;
	int whr = L[span];
	pair<int, int> res;
	res.first = max(st1[whr][l], st1[whr][r - (1 << whr) + 1]);
	res.second = min(st2[whr][l], st2[whr][r - (1 << whr) + 1]);
	return res;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		//cin >> a[i];
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		//cin >> b[i];
		scanf("%d", &b[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		st1[0][i] = a[i];
		st2[0][i] = b[i];
	}
	for (int lev = 1; lev <= 18; lev++)
	{
		for (int i = 1; i <= n; i++)
		{
			st1[lev][i] = st1[lev - 1][i];
			st2[lev][i] = st2[lev - 1][i];
			if (i + (1 << lev) / 2 <= n)
				st1[lev][i] = max(st1[lev][i], st1[lev - 1][i + (1 << lev) / 2]),
				st2[lev][i] = min(st2[lev][i], st2[lev - 1][i + (1 << lev) / 2]);
		}
	}

	for (int i = 2; i <= n; i++)
	{
		L[i] = L[i / 2] + 1;
	}

	//build(1, 1, n);

	for (int i = 1; i <= n; i++)
	{
		int l, r;
		l = i-1;
		r = n;
		while (l < r)
		{
			int mid = l + r+1;
			mid /= 2;
			pair<int, int> p = get(i,mid);
			if (p.first < p.second)
				l = mid;
			else
				r = mid - 1;
		}
		ans1 = l;
		l = i - 1;
		r = n;
		while (l < r)
		{
			int mid = l + r + 1;
			mid /= 2;
			pair<int, int> p = get(i,mid);
			if (p.first <= p.second)
				l = mid;
			else
				r = mid - 1;
		}
		ans += l - ans1;
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}