/*
A gathering in the cold, in the North, in the dark lands of Pohjola
Where the sun had not been crossing the sky nor seen for centuries...

We were brought together by oaths we had once sworn - by blood...
...once together drawn...

We had gathered all our forces
Called together all the heroes
Equipped a hundred swordmen
And a thousand men with crossbows

Strengthened by hate and the thirst for the enemies' blood
We lay in wait for the season of no light
We had seen the frozen mist - we weren't afraid to die
And the oath we had sworn gave us reason to live on

A Calm before the Storm
(We were) Awaiting the Winter Frost

...And then a storm arose in fury
The sky was shattered by lightning...

Awaiting the Winter Frost
As the sky blackened and the stars turned red
The frost greeted us with a cold northern breeze

Off with their heads! Off with their fuckin' heads!!!
Oh, the time had come...
To slaughter the hordes of cowardice
And cleanse the North from lies

We had gathered all our forces
Called together all the heroes
Equipped a hundred swordmen
And a thousand men with crossbows

We raised our swords
Grasped the irons
Lifted our bows
And chose the arrows

The false ones' hordes were put to the sword
The strong and the weak, one by one...
Their race was slaughtered to the very last man
Our bloodfeind was done as their bodies reddened the land

Awaiting the Winter Frost
The sign of the dark and the cold
the spell of pure hate

Awaiting the Winter Frost

And the heathen peace was found
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

const int N = 600000;

using namespace std;

int n, m, clr[N];
long long t[N*4];
int topush[N*4];
int used[N];
int timer;
int tin[N], tout[N];
int order[N];
vector<int> g[N];

int count_bits(long long x)
{
	if (x == 0)
		return 0;
	return x % 2 + count_bits(x / 2);
}

void dfs(int v)
{
	used[v] = 1;
	++timer;
	tin[v] = timer;
	order[timer] = v;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
	tout[v] = timer;
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
//		cout << tl << "@" << order[tl] << " " << clr[order[tl]] << endl;

		t[v] = (1ll << clr[order[tl]]);
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = (t[v * 2] | t[v * 2 + 1]);
}

void push(int v, int tl, int tr)
{
	if (topush[v] == 0)
		return;
	t[v * 2] = t[v * 2 + 1] = t[v];
	topush[v * 2] = topush[v * 2 + 1] = 1;
	topush[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
	if (l > r)
		return;

	if (tl == l&&tr == r)
	{
		t[v] = (1ll << val);
		topush[v] = 1;
		return;
	}
	push(v, tl, tr);

	int tm = tl + tr;
	tm /= 2;
	update(v * 2, tl, tm, l, min(r, tm), val);
	update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	t[v] = (t[v * 2] | t[v * 2 + 1]);
}

long long get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0;
	if (tl == l&&tr == r)
		return t[v];
	push(v, tl, tr);
	int tm = tl + tr;
	tm /= 2;
	return get(v * 2, tl, tm, l, min(r, tm)) | get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
//		cin >> clr[i];
		scanf("%d", &clr[i]);
	}
	
	for (int i = 1; i < n; i++)
	{
		int a, b;
//		cin >> a >> b;
		scanf("%d", &a);
		scanf("%d", &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	build(1, 1, n);

	for (; m; --m)
	{
		int tp;
		cin >> tp;
		if (tp == 1)
		{
			int a, b;
//			cin >> a >> b;
			scanf("%d", &a);
			scanf("%d", &b);
			//cout << "!"<<tin[a] << " " << tout[a] << endl;

			update(1, 1, n, tin[a], tout[a], b);
		}
		else
		{
			int a;
//			cin >> a;
			scanf("%d", &a);
			long long res = get(1, 1, n, tin[a], tout[a]);
			//cout << "@@" << res << endl;

			printf("%d\n", count_bits(res));
		}
	}

	cin.get(); cin.get();
	return 0;
}