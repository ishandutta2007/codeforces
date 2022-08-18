/*
Take some venom and accept
That you won't see Nazareth
The rainbow leads you home

Warrior sent to milky way
UFO shooting Gamma ray
A riot of destruction

Watch the rock bitch go down, vixen spread

When the priest killed a maiden in the metal church
Armored saints and warlocks watched the slaughter
Rage of the slayer forced the pretty maids
To kiss the queen in crimson glory

You were born a motor head
Bike's in flames you race ahead
You do the Kansas rush

Racing with the motley crew
Annihilator chasing you
With guns and burning roses

Status quo has been reached
Wasps unleashed

Take a sky ride with me
Then you'll see
*/

#pragma comment(linker, "/STACK:16777216")
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
const int N = 200000;

vector<pair<int, int> > g[N];
int a[N];
int n;
long long dep[N], shit[N];
int ans;
int used[N];

void dfs(int v, long long qdep, long long qbest)
{
	if (qdep-qbest > a[v])
		shit[v] = 1;
	dep[v] = qdep;
	used[v] = 1;
	qbest = min(qbest, dep[v]);
	for (int i = 0; i < g[v].size(); i++)
	{
		if (used[g[v][i].first])
			continue;
		dfs(g[v][i].first, qdep + g[v][i].second, qbest);
	}
}

void trace(int v)
{
	if (used[v])
		return;
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		trace(g[v][i].first);
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 2; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(make_pair(i, b));
		//g[b].push_back(make_pair(i, a));
	}

	dfs(1, 0ll, 0ll);

	for (int i = 1; i <= n; i++)
	{
		used[i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (shit[i])
		{
			trace(i);
	//		cout << i << endl;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n;i++)
		if (used[i])
			++ans;

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}