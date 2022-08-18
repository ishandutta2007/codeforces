/*
Sometimes your mind makes twists and turns
Dreams up something out of this world
Relieves you of dull sanity
Every once in a while you dream
Or simply forget what is real
And it enables you to flee

Hell or high water
Say hi to mother Earth and father sky

Behold, I just dethroned the laws of gravity
In this place where
My machine is fuelled by quicksilver
It's cold in here, radio is silent for me
Quicksilver ghost
Take me to the world I love the most

Those who are weightless don't need wings
No cosmic gales or solar winds
The world is dark but mind is free
It's you who gets her off the ground
Co-pilot is nowhere to be found
Go find a place beyond belief
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

const int N = 200000;

const int root = 1;

using namespace std;

int n;
int cost[N];
int used[N];
vector<int> g[N], G[N];
int par_pos[N];

long long max_dep[N];
long long longest_below[N];

vector<long long> pref_bel[N], suf_bel[N], pref_dep[N], suf_dep[N];
int par[N];
multiset<long long> D[N];
long long best_out[N], longest_up[N];

void dfs(int v)
{
	used[v] = 1;
	max_dep[v] = longest_below[v] = cost[v];

	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		G[v].push_back(to);
		par_pos[to] = G[v].size() - 1;
		par[to] = v;
		dfs(to);
		max_dep[v] = max(max_dep[v], max_dep[to] + cost[v]);
		D[v].insert(max_dep[to]);
		longest_below[v] = max(longest_below[v], longest_below[to]);
	}

	vector<long long> vec;

	if (G[v].size() > 1)
	{
		for (int i = 0; i < G[v].size(); i++)
		{
			int to = G[v][i];
			vec.push_back(max_dep[to]);
		} 
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		longest_below[v] = max(longest_below[v], vec[0] + vec[1] + cost[v]);
	}
	
	longest_below[v] = max(longest_below[v], max_dep[v]);

	pref_dep[v].resize(G[v].size());
	suf_dep[v].resize(G[v].size());
	suf_bel[v].resize(G[v].size());
	pref_bel[v].resize(G[v].size());
	
	if (G[v].size())
	{
		pref_dep[v][0] = max_dep[G[v][0]];
		pref_bel[v][0] = longest_below[G[v][0]];
		for (int i = 1; i < G[v].size(); i++)
		{
			pref_dep[v][i] = max(pref_dep[v][i - 1], max_dep[G[v][i]]);
			pref_bel[v][i] = max(pref_bel[v][i - 1], longest_below[G[v][i]]);
		}
		suf_dep[v][G[v].size() - 1] = max_dep[G[v][G[v].size() - 1]];
		suf_bel[v][G[v].size() - 1] = longest_below[G[v][G[v].size() - 1]];
		int sz = G[v].size();
		for (int i = sz - 2; i >= 0; --i)
		{
			suf_dep[v][i] = max(suf_dep[v][i + 1], max_dep[G[v][i]]);
			suf_bel[v][i] = max(suf_bel[v][i + 1], longest_below[G[v][i]]);
		}
	}
}

void solve1(int v)
{
	longest_up[v] = cost[v];
//	best_out[v] = cost[v];

	if (v != root)
	{
		int p = par[v];
		longest_up[v] = max(longest_up[v], longest_up[p] + cost[v]);
		if (par_pos[v] != 0)
		{
			longest_up[v] = max(longest_up[v], pref_dep[p][par_pos[v] - 1] + cost[v] + cost[p]);
		}
		if (par_pos[v] != G[p].size() - 1)
		{
			longest_up[v] = max(longest_up[v], suf_dep[p][par_pos[v] + 1] + cost[v] + cost[p]);
		}

		best_out[v] = max(best_out[v], best_out[p]);

		if (par_pos[v] != 0)
		{
			best_out[v] = max(best_out[v], pref_dep[p][par_pos[v] - 1] + longest_up[p]);
			best_out[v] = max(best_out[v], pref_bel[p][par_pos[v] - 1]);
		}
		if (par_pos[v] !=G[p].size()-1)
		{
			best_out[v] = max(best_out[v], suf_dep[p][par_pos[v] + 1] + longest_up[p]);
			best_out[v] = max(best_out[v], suf_bel[p][par_pos[v] + 1]);
		}

		if (D[p].size() > 1)
		{
			multiset<long long>::iterator it;
			it = D[p].end();
			--it;
			long long val1 = (*it);
			--it;
			long long val2 = (*it);
			best_out[v] = max(best_out[v], val1 + val2 + cost[p]);
		}
	}
//	best_out[v] = max(best_out[v], longest_up[v]);

	for (int i = 0; i < G[v].size(); i++)
	{
		int to = G[v][i];
		D[v].erase(D[v].find(max_dep[to]));
		solve1(to);
		D[v].insert(max_dep[to]);
	}
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(root);

	solve1(root);
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << i << " " << best_out[i] << " " << longest_up[i] << " " << max_dep[i] << " " << longest_below[i] << endl;
	}
	*/
	long long ans = 0;

	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, best_out[i] + longest_below[i]);
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}