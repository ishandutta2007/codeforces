/*
It has been many years since I was thrown into the cell
My sentence was electrocution when the gavel fell
The clock is slowly getting closer to that final time
Strapped into the chair and punished for false crimes

My last meal is getting colder
But I have no appetite
I look down the hall at the impending doom
That waits for me this very night
My last rites are read by the pastor
As if I had rights from the start
I'm moments away before they strap me in
And voltage will flow through my heart

The warden straps me in
Flashes me a twisted grin
No last words for me to say
I know my life will end
For something that I never did
Death is just a switch away

A victim's family cheers
A killer has been free for years
I'm punished for another's crimes
My time is finally up
I guess I'm just a victim
of the wrong place at the wrong time

The Ripper runs wild through the streets
While I sit here inside a cell
A judicial system's deadly mistake
A psychopath out free to kill
Poor lawyers and poor evidence
And witnesses appeared and lied
These fools will take years to see their mistakes
And I will be long gone and fried

Mental Shock
All appeals denied
Mental Shock
It's me they want to die
Mental Shock
Nothing lasts forever
Mental Shock
Until they pull the lever

The current shoots through as I begin to convulse
A fate that should be for somebody else
Electrified brain shoots straight through the eyes
And justice is served while innocence dies
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

vector<int> g[N];
int indeg[N];
int n, m;
int query[N], need[N];
vector<pair<int, int> > order;
int shit;
int dep[N];
int prior[N];

void dfs(int v)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dep[to] = dep[v] + 1;
		dfs(to);
	}
}

set<pair<int, int> > alive;
set<pair<int, int> > ::iterator it;

int get_best()
{
	it = alive.end();
	--it;
	return (*it).second;
}

void trace(int v)
{
	if (need[v])
	{
		alive.insert(make_pair(prior[v], v));
	}
	int Q = get_best();
	if (Q != query[v])
	{
		shit = 1;
	}
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		trace(to);
	}
	if (need[v])
	{
		alive.erase(make_pair(prior[v], v));
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		indeg[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> query[i];
		need[query[i]] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (indeg[i])
			continue;
		dfs(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (need[i])
			need[i] = dep[i] + 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (need[i])
		{
			order.push_back(make_pair(need[i], i));
		}
		prior[i] = need[i];
	}

	sort(order.begin(), order.end());
	reverse(order.begin(), order.end());

	shit = 0;
	for (int i = 1; i <= n; i++)
	{
		if (indeg[i])
			continue;
		trace(i);
	}
	if (shit)
	{
		cout << "-1" << endl;
		return 0;
	}
	
	cout << order.size() << endl;

	for (int i = 0; i < order.size(); i++)
	{
		cout << order[i].second << endl;
	}

	cin.get(); cin.get();
	return 0;
}