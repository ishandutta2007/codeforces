/*
To be green in the beautiful hour of envy so divine
To be pure, to let chance form your infinite design
Let the seed awakening begin again
I hate the way you judge me
I hate that you're above me
Can't humanity reach a certain point of understanding?

Why do we live this way?
Why do we have to say the things that subvert the minds of youth?
Why is the world unborn as crashing seas still form?
The vision of the future is of blood

As we face the bleak horizon under crushing skies
The truth belying a future uncertain and dark
We are but one small race, all wear a human face
Yet our image is imperfect and flawed

To set your mind free you must first just listen
Don't waste your life on worthless hate and contradiction, don't you

Reaction in the earth and sky is coming at fast pace
The end to this winding road, extinction of our race
If we all are to survive, there must come great change
I foresee the future, I see the coming plague

Why do we live this way?
Why do we have to say the things that subvert the minds of youth?

To set your mind free you must first just listen
Don't waste your life on worthless hate and contradiction, don't you
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

const int N = 805000;

using namespace std;

int t[N * 4];
int n, m, ar[N];
pair<int, int> quer[N];
vector<int> vals;
vector<int> queries[N];
int best_pref[N], best_suf[N], quer_pref[N], quer_suf[N];
map<int, int> mapp;
int dif;
int LIS;
int could_be[N];
int largest_pref[N], smallest_suf[N], lis[N];

void remap()
{
	sort(vals.begin(), vals.end());
	for (int i = 0; i < vals.size(); i++)
	{
		if (i == 0 || vals[i] != vals[i - 1])
		{
			mapp[vals[i]] = dif;
			++dif;
		}
	}
}

void build(int v, int tl, int tr)
{
	t[v] = 0;
	if (tl == tr)
		return;
	int tm = tl + tr;
	tm /= 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
}

int get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0;
	if (tl == l&&tr == r)
		return t[v];
	int tm = tl + tr;
	tm /= 2;
	return max(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

void update(int v, int tl, int tr, int ps, int val)
{
	if (tl == tr)
	{
		t[v] = max(t[v], val);
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	if (ps <= tm)
		update(v * 2, tl, tm, ps, val);
	else
		update(v * 2 + 1, tm + 1, tr, ps, val);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int main(){
	//	freopen("packing.in", "r", stdin);
	//	freopen("packing.out", "w", stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		vals.push_back(ar[i]);
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> quer[i].first >> quer[i].second;
		vals.push_back(quer[i].second);
	}

	remap();

	for (int i = 1; i <= n; i++)
	{
		ar[i] = mapp[ar[i]];
	}

	for (int i = 1; i <= m; i++)
	{
		quer[i].second = mapp[quer[i].second];
		queries[quer[i].first].push_back(i);
	}

	// prefixes

	for (int i = 1; i <= n; i++)
	{
		int bst = get(1, 0, dif, 0, ar[i] - 1);
		best_pref[i] = bst;
		for (int j = 0; j < queries[i].size(); j++)
		{
			int id = queries[i][j];
			int im_val = quer[id].second;
			int res = get(1, 0, dif, 0, im_val - 1);
			quer_pref[id] = res;
		}
		update(1, 0, dif, ar[i], best_pref[i]+1);
	}

	build(1, 0, dif);

	//suff

	for (int i = n; i; --i)
	{
		int bst = get(1, 0, dif, ar[i] + 1, dif);
		best_suf[i] = bst;
		for (int j = 0; j < queries[i].size(); j++)
		{
			int id = queries[i][j];
			int im_val = quer[id].second;
			int res = get(1, 0, dif, im_val + 1, dif);
			quer_suf[id] = res;
		}
		update(1, 0, dif, ar[i], best_suf[i]+1);
	}

	/*
	for (int i = 1; i <= n; i++)
	{
		cout << best_pref[i] << "  " << best_suf[i] << endl;
	}*/

	for (int i = 1; i <= n; i++)
	{
		LIS = max(LIS, best_pref[i] + best_suf[i] + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		if (best_pref[i] + best_suf[i] + 1 == LIS)
			could_be[i] = 1;
	}

	largest_pref[0] = -100;

	for (int i = 1; i <= n; i++)
	{
		largest_pref[i] = largest_pref[i - 1];
		if (could_be[i])
			largest_pref[i] = max(largest_pref[i], ar[i]);
	}
	
	smallest_suf[n + 1] = 1e9;

	for (int i = n; i; --i)
	{
		smallest_suf[i] = smallest_suf[i + 1];
		if (could_be[i])
			smallest_suf[i] = min(smallest_suf[i], ar[i]);
	}

	for (int i = 1; i <= m; i++)
	{
		lis[i] = LIS - 1;// easy part
		//cout << quer_pref[i] << " * " << quer_suf[i] << endl;
		lis[i] = max(lis[i], quer_pref[i] + quer_suf[i] + 1);// takes
		int ps = quer[i].first;

		if (largest_pref[ps - 1] >= ar[ps] || smallest_suf[ps + 1] <= ar[ps])
			lis[i] = max(lis[i],LIS);
	}

	for (int i = 1; i <= m; i++)
	{
		cout << lis[i] << "\n";
	}

	cin.get(); cin.get();
	return 0;
}