/*
How much pain, do you need to feel
How much shame, do you have to conceal
There is no sunshine, just endless nights
Nobody's there, nobody cares when you cry

Is it my face you see?
Do I haunt you in your sleep?
On your hands and knees when you crawl
Through your nightmares

When there's no more grace
Does your heartbeat start to race?
Crawling everywhere in the dark
Poisonous shadows

How many secrets, do you keep inside?
How many sins, do you have to hide?
The haunting masses, have blackened the sun
You'll pay for everything you've done
One by one

Is it my face you see?
Do I mock you in your sleep?
On your hands and knees when you crawl
Through your nightmares

When there's no more grace
Does your heartbeat start to race?
Crawling everywhere in the dark
Poisonous shadows

Is it my face you see?
Do I haunt you in your sleep?
On your hands and knees when you crawl
Through your nightmares

When there's no more grace
Does your heartbeat start to race?
Crawling everywhere in the dark
Poisonous shadows

Is it my face you see?
Do I haunt you in your sleep?
On your hands and knees when you crawl
Through your nightmares
When there's no more grace
Does your heartbeat start to race?
Crawling everywhere in the dark
Poisonous shadows
(It's like I woke up and she was right there
You know, I can almost touch her
Although she's been gone for years now
I can feel her
I can feel her watching me)
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 105000;

const double INF = 1e18;

using namespace std;

int n, m;
vector<int> g[N];
int up[N][19];
long long subsize[N], subsum[N];
int tin[N], tout[N];
int dep[N];
int timer;
long long prog[N];
long long sum_down[N], sum_up[N], sum_to_all[N];

void dfs(int v, int p)
{
	tin[v] = timer;
	subsize[v] = 1;
	subsum[v] = dep[v];
	++timer;
	up[v][0] = p;
	for (int i = 1; i <= 18; i++)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to == p)
			continue;
		dep[to] = dep[v] + 1;
		dfs(to, v);
		subsize[v] += subsize[to];
		subsum[v] += subsum[to];
		sum_down[v] += sum_down[to] + subsize[to];
	}
	tout[v] = timer;
	++timer;
}

bool upper(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b)
{
	if (upper(a, b))
		return a;
	if (upper(b, a))
		return b;
	for (int i = 18; i >= 0; --i)
	{
		if (!upper(up[a][i], b))
			a = up[a][i];
	}
	return up[a][0];
}

int get_parent(int v, int q)
{
	for (int i = 18; i >= 0; --i)
	{
		if (q&(1 << i))
			v = up[v][i];
	}
	return v;
}

void trace(int v, int p)
{
	if (v != 1)
	{
		sum_up[v] = n - subsize[v] + sum_up[p] + (sum_down[p] - sum_down[v] - subsize[v]);
	}
	sum_to_all[v] = sum_up[v] + sum_down[v];

	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to == p)
			continue;
		trace(to, v);
	}
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	prog[0] = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		prog[i] = prog[i - 1] + i;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1, 1);

	trace(1, 1);
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << sum_down[i] << " " << sum_up[i] << " " << sum_to_all[i] << " " << endl;
	}
	*/
	for (; m; --m)
	{
		int a, b;
		cin >> a >> b;
		int com = lca(a, b);
		
		if (com != a&&com != b)
		{
			long long total_a = subsize[a];
			long long total_b = subsize[b];
			long long sub_dep_a = subsum[a] - total_a*dep[com];
			long long sub_dep_b = subsum[b] - total_b*dep[com];
			long long res = sub_dep_a*total_b + sub_dep_b*total_a + total_a*total_b;
			long long tpairs = 1ll * total_a*total_b;
			cout.precision(10);
			cout << fixed << res*1.0 / tpairs << endl;
			continue;
		}

		if (com == a)
			swap(a, b);
		long long total_a = subsize[a];
		long long last_below = get_parent(a, dep[a] - dep[b]-1);
		long long total_b = n - subsize[last_below];

		long long sub_dep_a = subsum[a] - total_a*dep[com];
		long long sub_dep_b = sum_to_all[b] - sum_down[last_below] - subsize[last_below];
		
		long long res = sub_dep_a*total_b + sub_dep_b*total_a + total_a*total_b;
		long long tpairs = 1ll * total_a*total_b;
		cout.precision(10);
		cout << fixed << res*1.0 / tpairs << endl;
	}

	cin.get(); cin.get();
	return 0;
}