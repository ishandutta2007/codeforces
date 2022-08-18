/*
Well I wake up this morning I rolled out of bed
I felt like a dog who's been kicked in the head
Checked out my mail there was letter that read
Love for sale, love for sale

I picked up the phone I called everyone I could
I let my fingers do the walking through the telephone book
You can't catch a fish if you ain't got the hook
Love for sale, love for sale

Send up a signal throw me a line
Somebody explain " this funny Valentine"
It might not be legal but it sure ain't a crime
I'm one step from crazy and two steps behind

I called Lt. Columbo from my TV set
I've tried the Dating Game I haven't found her yet
I'm hoping that she's looking like a Penthouse Pet
Love for sale, love for sale

We've been living together 3 years,
2 hours, 20 minutes maybe four houndred beers
You can't shop for love when you're shopping at, Sears
Love for sale, love for sale

I guess I've learnt my lesson it was easy to see
My old lady she played this joke on me
I never looked where I forgot it would be
Love for sale, love for sale
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
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 600031;

int n, m;
vector<pair<int, int> > edge_list;
vector<int> g[N];
int s, t;
int d1, d2;
int used[N];
vector<int> comp;

int C;
vector<pair<int, int> > ans;

void dfs(int v)
{
	used[v] = C;
	comp.push_back(v);
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		if (to == s || to == t)
			continue;
		ans.push_back(make_pair(v, to));
		dfs(to);
	}
}

int HAVE_ST;
int have_S[N], have_T[N], S_id[N], T_id[N];
int DONE[N];

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
		edge_list.push_back(make_pair(a, b));
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cin >> s >> t >> d1 >> d2;

	for (int i = 1; i <= n; i++)
	{
		if (i == s || i == t)
			continue;
		if (used[i])
			continue;
		++C;
		comp.clear();
		dfs(i);
	}
	
	for (int i = 0; i < g[s].size(); i++)
	{
		int to = g[s][i];
		if (to == t)
		{
			HAVE_ST = 1;
			continue;
		}
		int id = used[to];
		have_S[id] = 1;
		S_id[id] = to;
	}

	for (int i = 0; i < g[t].size(); i++)
	{
		int to = g[t][i];
		if (to == s)
			continue;
		int id = used[to];
		have_T[id] = 1;
		T_id[id] = to;
	}

	/*for (int i = 1; i <= C; i++)
	{
		cout << have_S[i] << " " << have_T[i] << endl;
	}
	*/

	for (int i = 1; i <= C; i++)
	{
		if (have_S[i] == 0 && have_T[i] == 0)
		{
			cout << "No" << endl;
			return 0;
		}
		if (have_S[i] == 0&&have_T[i]==1)
		{
			d2--;
			ans.push_back(make_pair(T_id[i], t));
			DONE[i] = 1;
		}
		if (have_T[i] == 0 && have_S[i] == 1)
		{
			d1--;
			ans.push_back(make_pair(S_id[i], s));
			DONE[i] = 1;
		}
	}

	int together = 0;

	for (int i = 1; i <= C; i++)
	{
		if (DONE[i])
			continue;
		if (together == 0)
		{
			ans.push_back(make_pair(S_id[i], s));
			--d1;
			ans.push_back(make_pair(T_id[i], t));
			--d2;
			together = 1;
			continue;
		}
		if (d1 > 0)
		{
			ans.push_back(make_pair(S_id[i], s));
			--d1;
		}
		else
		{
			ans.push_back(make_pair(T_id[i], t));
			--d2;
		}
	}


	if (HAVE_ST == 1&&together==0)
	{
		together++;
		ans.push_back(make_pair(s, t));
		--d1;
		--d2;
	}

	//cout << d1 << "%" << d2 << endl;
	//while (true);

	if (d1 < 0 || d2 < 0||together==0)
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}

	cin.get(); cin.get();
	return 0;
}