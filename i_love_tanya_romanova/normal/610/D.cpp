/*
Ruin is your profit
Meraud the hollow mind
Religious passion is not for you
Agnostic modern science
Suffocate superior forces
Tearing down this fortress of control

Dogmatic authority falls
Alternative to submission
Mental emancipation
Severance, selection of
All powers from above
Strong minded in preparation
For this sickening mess
We're living in

Threat for your security
Authority will collapse
End pseudo-democracy
Take fate in your own hands
Violent terroristic action
Only self-defense
Ignorence is unconciousness

No pessimistic vision
Corruption pseudo peace
Propaganda drug of nation
Deceiving you and me
A psychosocial revolt
Becomes aware, horowing truth
Hear my call!

Dogmatic authority falls!
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

const int N = 510000;

using namespace std;

int n;
int x1[N], y1[N], x2[N], y2[N];
vector<int> xs, ys;
vector<int> ux, uy;
map<int, int> mapx, mapy;
long long ans;
vector < pair<int, pair<int, int> > > vertical, horizontal;
vector<pair<int, pair<int, int> > > events;
int t[N * 4];

void inc(int i, int delta)
{
	for (; i <= uy.size(); i = (i|(i + 1)))
		t[i] += delta;
}

int sum(int r)
{
	int res = 0;
	for (; r >= 0; r = (r&(r + 1)) - 1)
		res += t[r];
	return res;
}

int sum(int l, int r)
{
	return sum(r) - sum(l - 1);
}

void compress()
{
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	
	for (int i = 0; i < xs.size(); i++)
	{
		if (i>0 && xs[i] == xs[i - 1])
			continue;
		mapx[xs[i]] = ux.size();
		ux.push_back(xs[i]);
	}
	for (int i = 0; i < ys.size(); i++)
	{
		if (i>0 && ys[i] == ys[i - 1])
			continue;
		mapy[ys[i]] = uy.size();
		uy.push_back(ys[i]);
	}
}

vector<pair<int, pair<int, int> > > compres2(vector<pair<int, pair<int, int> > > v)
{
	sort(v.begin(), v.end());
	vector<pair<int, pair<int, int> > > res;
	if (v.size() == 0)
		return res;
	int lmost = v[0].second.first;
	int rmost = v[0].second.second;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].first != v[i - 1].first || v[i].second.first>rmost)
		{
			res.push_back(make_pair(v[i - 1].first, make_pair(lmost, rmost)));
			lmost = v[i].second.first;
			rmost = v[i].second.second;
		}
		else
		{
			rmost = max(rmost, v[i].second.second);
		}
	}
	res.push_back(make_pair(v[v.size() - 1].first, make_pair(lmost, rmost)));
	return res;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		
		if (x1[i] > x2[i])
			swap(x1[i], x2[i]),
			swap(y1[i], y2[i]);
		if (y1[i] > y2[i])
			swap(x1[i], x2[i]),
			swap(y1[i], y2[i]);

		xs.push_back(x1[i]);
		xs.push_back(x2[i]);
		ys.push_back(y1[i]);
		ys.push_back(y2[i]);
	}

	compress();

	for (int i = 1; i <= n; i++)
	{
		if (x1[i] == x2[i])// vertical
			vertical.push_back(make_pair(x1[i], make_pair(y1[i], y2[i])));
		else
			horizontal.push_back(make_pair(y1[i], make_pair(x1[i], x2[i])));
	}

	sort(vertical.begin(), vertical.end());
	sort(horizontal.begin(), horizontal.end());

	vertical = compres2(vertical);
	horizontal = compres2(horizontal);

	for (int i = 0; i < vertical.size(); i++)
	{
		ans += vertical[i].second.second - vertical[i].second.first + 1;
	}
	for (int i = 0; i < horizontal.size(); i++)
	{
		ans += horizontal[i].second.second - horizontal[i].second.first + 1;
	}

//	cout << ans << endl;

	for (int i = 0; i < horizontal.size(); i++)
	{
		events.push_back(make_pair(horizontal[i].second.first, make_pair(-1, mapy[horizontal[i].first])));
		events.push_back(make_pair(horizontal[i].second.second, make_pair(1, mapy[horizontal[i].first])));
	}

	for (int i = 0; i < vertical.size(); i++)
	{
		events.push_back(make_pair(vertical[i].first, make_pair(0, i)));
	}

	sort(events.begin(), events.end());

	for (int i = 0; i < events.size(); i++)
	{
		int tp = events[i].second.first;
		if (tp == -1)// add
		{
			inc(events[i].second.second, 1);
		}
		if (tp == 1)// remove
		{
			inc(events[i].second.second, -1);
		}
		if (tp == 0)
		{
			int id = events[i].second.second;
			ans -= sum(mapy[vertical[id].second.first], mapy[vertical[id].second.second]);
		}
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}