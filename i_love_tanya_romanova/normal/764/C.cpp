/*
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n;
vector<pair<int,int> > edges;
vector<int> g[N];
int clr[N];
int ans;
int have_bad;

int used[N];
int shit;

void validate(int v)
{
	used[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		if (clr[to]!=clr[v])
			shit=1;
		validate(to);
	}
}

bool valid(int root)
{
	for (int i=1;i<=n;i++)
	{
		used[i]=0;
	}
	used[root]=1;
	shit=0;
	int v=root;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		validate(to);
	}
	return (shit==0);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		edges.push_back(make_pair(a,b));
	}

	for (int i=1;i<=n;i++)
	{
		cin>>clr[i];
	}

	ans=-1;

	for (int i=0;i<edges.size();i++)
	{
		int v1=edges[i].first;
		int v2=edges[i].second;
		if (clr[v1]!=clr[v2])
		{
			if (have_bad)
				break;
			have_bad=1;
			if (valid(v1))
				ans=v1;
			if (valid(v2))
				ans=v2;
		}
	}

	if (have_bad==0)
	{
		cout<<"YES"<<endl;
		cout<<1<<endl;
	}
	else if (ans!=-1)
	{
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	}
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}