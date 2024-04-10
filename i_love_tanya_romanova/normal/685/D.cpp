/*
Standing on the edge
Battle in my head
I'm dying to know
I'm dying to know

If I take this leap
To fail or succeed
I'm dying to know
I'm dying to know

This is it, I've shaken
My body's aching
I lose my hold
I will let go

This is it, I'm falling
My wings need to grow
I lose my hold
I will let go

There's so many roads
Pitfalls filled with doubt
I'm dying to know
I'm dying to know

Grabbing what I need
And rip it til it bleeds
I'm dying to know
I'm dying to know

This is it, I've shaken
My body's aching
I lose my hold
I will let go

This is it, I'm falling
My wings need to grow
I lose my hold
I will let go

If I, if I take this, this leap
Will I be broken?
I'm dying to know

This is it, I've shaken
My body's aching
I lose my hold
I will let go

(I lose my hold)
This is it, I'm falling
(I lose my hold)
My wings need to grow
I lose my hold
I will let go, I will let go

I will let go
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
const int N = 100031;

int n, k, x[N], y[N];
vector<int> xs, ux;
vector<pair<pair<int, char>, pair<int, int> > > queries;

int last_update[3050000], cnt[3050000];
long long ans[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		xs.push_back(x[i] - k);
		xs.push_back(x[i] - k + 1);
		xs.push_back(x[i]);
		xs.push_back(x[i] + 1);
/*		for (int j = -k; j <= 1; j++)
		{
			xs.push_back(x[i] + j);
		}
*/
	}

	sort(xs.begin(), xs.end());

	for (int i = 0; i < xs.size(); i++)
	{
		if (i == 0 || xs[i] != xs[i - 1])
			ux.push_back(xs[i]);
	}

	xs.clear();

	queries.reserve(n * 2);

	for (int i = 1; i <= n; i++)
	{
		int lx = lower_bound(ux.begin(), ux.end(), x[i] - k + 1) - ux.begin();
		int rx = upper_bound(ux.begin(), ux.end(), x[i]) - ux.begin();
		queries.push_back(make_pair(make_pair(y[i] - k + 1, 1), make_pair(lx, rx)));
		queries.push_back(make_pair(make_pair(y[i] + 1, -1), make_pair(lx, rx)));
	}

	sort(queries.begin(), queries.end());

	for (int i = 0;i < queries.size(); i++)
	{
		int cur_x = queries[i].first.first;
		int change = queries[i].first.second;
		int start = queries[i].second.first;
		int finish = queries[i].second.second;
		for (int j = start; j < finish; j++)
		{
			ans[cnt[j]] += (cur_x - last_update[j])*(ux[j+1]-ux[j]);
			last_update[j] = cur_x;
			cnt[j] += change;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i>1)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}