/*
When I need to spark a bit of inspiration
And the melody feels like it's trapped inside
All I need is a bit of illumination
So the rhythm can no longer run and hide
Well, I take a puff from the leaves of the devil
And it carries me on the other side (fire it up)

I like to fire it up and it feels so right
Fire it up
'Cause when I fire it up, I feel like serenity (I feel like serenity)
Is mine

When I need a little bit of relaxation
My medicine isn't too hard to find
When I'm looking for a bit rejuvenation
I only partake of the finest kind
And then the mystery begins to unravel
It helps me break through to the other side (fire it up)

I like to fire it up and it feels so right
Fire it up
'Cause when I fire it up, I feel like serenity (I feel like serenity)
Is mine

Fire it up, fire it up

Fire it up (fire it up)
I like to fire it up and it feels so right
Fire it up
'Cause when I fire it up I feel like serenity (I feel like serenity)
Is mine
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 1100000;

using namespace std;

int n, m, k, ar[N];
long long t[N];
vector<int> ent[N];
vector<int> queries[N];
vector<int> heavy;
int L[N], R[N];
int S[N];
long long ans[N];
int W; 
vector<pair<int, int> > V;


long long get(int r)
{
	long long res = 0;
	for (; r >= 0; r = (r&(r + 1)) - 1)
		res += t[r];
	return res;
}

void inc(int i, int val)
{
	for (; i < 200000; i = (i | (i + 1)))
		t[i] += val;
	return;
}

void make_update(int val)
{
	if (ent[val].size() >= bsize)
		return;
	if (ent[val^k].size() >= bsize)
		return;
	for (int i = 0; i < ent[val^k].size(); i++)
	{
		int ps = ent[val^k][i];
		if (ps >= W)
			break;
		inc(ps, 1);
	}
}

int count_entries(int val, int l, int r)
{
	return upper_bound(V.begin(), V.end(), make_pair(val, r)) - lower_bound(V.begin(), V.end(), make_pair(val, l));
}
long long solve(int l,int r)
{
	long long res = get(r) - get(l - 1);
	for (int i = 0; i < heavy.size(); i++)
	{
		int val = heavy[i];
		if (k>0 && ent[val^k].size() >= bsize && (val^k) > val)
			continue;
		int ent1 = count_entries(val, l, r);
		int ent2 = count_entries(val^k, l, r);
		if (k == 0)
			res += 1ll * ent1*(ent1 - 1) / 2;
		else
			res += 1ll * ent1*ent2;
	}
	return res;
}

int naive(int a, int b, int val)
{
	int res = 0;
	for (int i = a; i <= b; i++)
	{
		for (int j = i; j <= b; j++)
		{
			if ((S[j] ^ S[i - 1]) == val)
				++res;
		}
	}
	return res;
}
int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		S[i] = (S[i - 1] ^ ar[i]);
	}

	for (int i = 0; i <= n; i++)
	{
		ent[S[i]].push_back(i);
		V.push_back(make_pair(S[i], i));
	}

	sort(V.begin(), V.end());

	for (int i = 0; i < N; i++)
	{
		if (ent[i].size()>bsize)
			heavy.push_back(i);
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> L[i] >> R[i];
		queries[R[i]].push_back(i);
	}

	for (int i = 0; i <= n; i++)
	{
		W = i;
		make_update(S[i]);
		for (int j = 0; j < queries[i].size(); j++)
		{
			int id = queries[i][j];
			ans[id] = solve(L[id]-1,i);
		}
	}

	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " "
			//<<naive(L[i],R[i],k)
			<<endl;
	}

	cin.get(); cin.get();
	return 0;
}