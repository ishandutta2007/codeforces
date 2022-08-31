/*
*/

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
#define have adsgagshdshfhds

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 400031;

int n;
int ar[N];
int tests, l[N], r[N], d[N];
long long A[N];

struct vert
{
	pair<int, int> pref;
	pair<int, int> suf;
	int len;
	int best_ans;
};

vert t[N * 4];

vert make_vert(long long val)
{
	vert res;
	if (val != 0)
		res.best_ans = 1;
	else
		res.best_ans = 0;
	if (val > 0)
		val = 1;
	if (val < 0)
		val = -1;
	res.pref = res.suf = make_pair(val, 1);
	if (val == 0)
		res.pref.second = res.suf.second = 0;

	res.len = 1;
	return res;
}

vert merge(vert &a, vert &b)
{
	vert res;
	res.len = a.len + b.len;
	res.best_ans = max(a.best_ans, b.best_ans);

	// pref
	res.pref = a.pref;

	if (a.pref.second == a.len)
	{
		if (b.pref.first != 0 && b.pref.first <= a.suf.first)
			res.pref.second += b.pref.second;
	}

	// suf
	res.suf = b.suf;
	if (b.suf.second == b.len)
	{
		if (b.pref.first <= a.suf.first&&a.suf.first != 0 && b.pref.first != 0)
		{
			res.suf.second += a.suf.second;
		}
	}

	// inside
	if (a.suf.first != 0 && b.pref.first != 0 && a.suf.first >= b.pref.first)
	{
		res.best_ans = max(res.best_ans, a.suf.second + b.pref.second);
	}
	return res;
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = make_vert(A[tl]);
		return;
	}
	int tm = tl + tr;
	tm /= 2;

	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);

	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void add(int v, int tl, int tr, int ps, int val)
{
	if (tl == tr)
	{
		A[tl] += val;
		t[v] = make_vert(A[tl]);
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	if (ps <= tm)
		add(v * 2, tl, tm, ps, val);
	else
		add(v * 2 + 1, tm + 1, tr, ps, val);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		//	ar[i] = rand();
	}
	for (int i = 2; i <= n; i++)
	{
		A[i] = ar[i] - ar[i - 1];
	}

	if (n == 1)
	{
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++)
		{
			cout << 1 << "\n";
		}
		return 0;
	}

	build(1, 2, n);

	cin >> tests;
	for (; tests; --tests)
	{
		int i = 1;
		/*for (int i = 2; i <= n; i++)
		{
		cout << A[i] << " ";
		}
		cout << endl;
		*/
		/*l[i] = rand() % n + 1;
		r[i] = rand() % n + 1;
		d[i] = rand();

		if (r[i]<l[i])
		swap(l[i], r[i]);
		*/
		cin >> l[i] >> r[i] >> d[i];
		if (l[i] > 1)
			add(1, 2, n, l[i], d[i]);
		if (r[i] < n)
			add(1, 2, n, r[i] + 1, -d[i]);
		int res = t[1].best_ans + 1;
		cout << res << "\n";
	}

	cin.get(); cin.get();
	return 0;
}