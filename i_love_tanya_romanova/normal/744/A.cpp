/*
Darkness was my light
Muteness was my tongue
Death was my life
Matter was my spirit

I am a brother to the fire
To fire a brother I am
From breasts of maidens three
I drank the black milk
Devoured the white milk
I swallowed the red milk

Brother to the fire I am
Brother to the fire

I've lain in the dark bowels
Bowels of this marshland
Dead beneath the soil
Under the waters
Oblivious to all
Devoid of all knowing
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

long long INF = 1e9;
const int N = 102231;

int n, m, k;
vector<int> g[N];
int used[N];
vector<int> comps;
int sz;

void dfs(int v)
{
	used[v] = 1;
	sz++;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
}

vector<int> cent;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int v;
		cin >> v;
		cent.push_back(v);
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0;i<cent.size();i++){
		int v = cent[i];
		sz = 0;
		dfs(v);
		comps.push_back(sz);
	}

	sort(comps.begin(), comps.end());

	int taken = 0;
	
	long long ans = 0;
	long long here;
	for (int i = 0; i < comps.size(); i++)
	{
		taken += comps[i];
	}
	comps[comps.size() - 1] += n - taken;

	for (int i = 0; i < comps.size(); i++)
	{
		here = 1ll * comps[i] * (comps[i] - 1) / 2;
		ans += here;
	}

	cout << ans - m << endl;

	cin.get(); cin.get();
	return 0;
}