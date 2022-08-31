/*
Tell me what you see,
In the after-life
Par-del le ciel
Par-del le soleil

In all there is to learn
The sun is on our side
And though you're on the run
You will survive
Expanded to the state of light
The deepest corners of the world
Gliding through the lowlands
And swimming all the oceans

Walking through the silence
Already made it through the night
There will be a new day
Whenever the sun rises

You're invisible, you're in everything
Tell me what you see
Tell me you're everywhere
Tell me now

While you drift away,
From all the plagues of this world
You're put out of misery, giant monster

You won't have to face it again
Every step of the way gets you higher

All the voices trapped underneath the ground
Let them all go in the sky!
Find the power lost underneath the ground
Let it all blow in the sky!
All the voices trapped in my head
Let them all scream in the night!
Find the power lost underneath the ground
Let it all blow in the sky!
*/

#pragma GCC optimize("O3")
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
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 500031;

int n;
int a[N],b[N];
int indeg[N],outdeg[N];

vector<int> g[N],gr[N];
int cnt;

int used[N];

bool is_loop(int v){
	if (g[v].size()!=1)
		return false;
	return (g[v][0]==v);
}

void rdfs(int v)
{
	used[v]=1;
	cnt++;
	for (int i=0;i<gr[v].size();i++)
	{
		int to=gr[v][i];
		if (used[to])
			continue;
		rdfs(to);
	}
}

void fill_dfs(int v)
{
	used[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		fill_dfs(to);
	}
	for (int i=0;i<gr[v].size();i++)
	{
		int to=gr[v][i];
		if (used[to])
			continue;
		fill_dfs(to);
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		indeg[b[i]]++;
		outdeg[a[i]]++;
		g[a[i]].push_back(b[i]);
		gr[b[i]].push_back(a[i]);
	}

	long long ans=1;

	for (int i=1;i<=n*2;i++)
	{
		if (outdeg[i]==0)
		{
			cnt=0;
			rdfs(i);
			ans*=cnt;
			ans%=bs;
		}
	}

	for (int i=1;i<=n*2;i++)
	{
		if (used[i])
			continue;
		if (is_loop(i))
			fill_dfs(i);
	}

	for (int i=1;i<=n*2;i++)
	{
		if (used[i])
			continue;
		fill_dfs(i);
		ans*=2;
		ans%=bs;
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}