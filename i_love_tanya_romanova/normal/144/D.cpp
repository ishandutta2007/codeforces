/*
Ascending I look down upon the lucid dream I leave behind the division of thought that evolved two suns echoing throughout all world fragments of life.

Separation of being from flesh I transcend back to thought.

The origin of all, Subconsciousness...
Ancient memories Re-emerge

To be lost again, to discover that I am Self
To see behind the shadows of illusion from within the earths.

I touch the heavens reflecting opposite thought

They speak to me, words of vast illusions, the inner and outer worlds, all mirroring creation

Containing all in existence, infinite worlds of relative energies

Intricate balance of oppositions, repeating patterns of complex detail

And self variation
Infinitely
And I am the essence

Engulfed in the light

Universe through unity, all memories diminished.
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
#define escape asdgasdgasdg

#define eps 1e-8
#define M_PI 3.141592653589793
//#define bs 1234567891
#define bsize 512

const int N = 120000;

using namespace std;

int n, m, s;
vector<pair<pair<int, int>, int> > edges;
vector<pair<int, int> > g[N];
long long D;
long long dist[N];
set<pair<long long, long long> >S;
int ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
		edges.push_back(make_pair(make_pair(a, b), c));
	}

	cin >> D;

	for (int i = 1; i <= n; i++)
		dist[i] = 1e16;

	dist[s] = 0;

	for (int i = 1; i <= n; i++)
		S.insert(make_pair(dist[i], i));

	while (S.size())
	{
		pair<long long, long long> p = *S.begin();
		int qv = p.second;
		S.erase(p);
		for (int i = 0; i < g[qv].size(); i++)
		{
			int to = g[qv][i].first;
			long long cost = g[qv][i].second + dist[qv];
			if (dist[to]>cost)
			{
				S.erase(make_pair(dist[to], to));
				dist[to] = cost;
				S.insert(make_pair(dist[to], to));
			}
		}
	}

	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == D)
			++ans;
	}

	for (int i = 0; i < edges.size(); i++)
	{
		int v1 = edges[i].first.first;
		int v2 = edges[i].first.second;
		long long C = edges[i].second;
		long long ohead = D - dist[v1];
		if (ohead>0 && ohead < C && (C - ohead) + dist[v2] >= D)
			++ans;
		ohead = D - dist[v2];
		if (ohead>0 && ohead<C && (C - ohead) + dist[v1]>D)
			++ans;
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}