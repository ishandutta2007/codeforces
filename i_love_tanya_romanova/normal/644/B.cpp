/*
Glowing heat, horizon swims
Wall-less labyrinth
Grace and ugliness, combined like never before
It's hell on earth, desert law

Where water means gold

Burning breath, deadly games
Two colored world of disgrace

Where water means gold

Mistress of deception
Daughter of death
Realm of the sun
Merciless, invincible

Glowing heat, horizon swims
Wall-less labyrinth
Storm, culmination of her wildness
Swallows every trace for eternity
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

const int N = 300000;

using namespace std;

int n, b;
long long t[N], d[N];
deque<pair<long long, long long> > qu;
long long ans[N];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> d[i];
	}

	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			if (qu.size() == 0)
				break;
			pair<long long, long long> p = qu.front();
			if (p.second <= t[i])
			{
				ans[p.first] = p.second;
				qu.pop_front();
				continue;
			}
			break;
		}
		if (qu.size() == 0)
		{
			qu.push_back(make_pair(i, t[i] + d[i]));
			ans[i] = t[i] + d[i];
			continue;
		}
		if (qu.size() > b)
		{
			ans[i] = -1;
			continue;
		}
		pair<long long, long long> p = qu.back();
		qu.push_back(make_pair(i, p.second + d[i]));
		ans[i] = p.second + d[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}