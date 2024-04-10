
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

int n,ans;
vector<int> g[N];
int clr[N];
int used[N];

int T,ban[N];

void solve(int v,int p)
{
	++T;
	used[v]=1;
	ban[clr[v]]=ban[clr[p]]=T;
	int ptr=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		while (ban[ptr]==T)
			++ptr;
		clr[to]=ptr;
		ban[ptr]=T;
	}
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		solve(to,v);
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
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i=1;i<=n;i++)
	{
		ans=max(ans,(int)g[i].size()+1);
	}

	clr[1]=1;
	solve(1,1);

	cout<<ans<<endl;
	for (int i=1;i<=n;i++)
	{
		if (i>1)
			cout<<" ";
		cout<<clr[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}