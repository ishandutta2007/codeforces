/*
*/
 
//#pragma comment(linker, "/STACK:16777216")
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define ends adsfasfsdf

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define LEV 18

using namespace std;

int n,a,b,tp;
vector<pair<int, int> > g[1<<20];
int tests,cur;
int cnt[1<<20][2];
int tin[1<<20],tout[1<<20],timer;
int up[1<<18][LEV];
int p[1<<19];
int dir[1<<19];
int dep[1<<19];

void dfs(int v,int par)
{
	tin[v]=timer;
	++timer;
	up[v][0]=par;
	for (int i=1;i<LEV;i++)
		up[v][i]=up[up[v][i-1]][i-1];
	
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i].first;
		if (to==par)
			continue;
		p[to]=v;
		dir[to]=g[v][i].second;
		dep[to]=dep[v]+1;
		dfs(to,v);
	}
	tout[v]=timer;
	++timer;
}

bool upper(int a,int b)
{
	return tin[a]<=tin[b]&&tout[a]>=tout[b];
}

int lca(int a,int b)
{
	if (dep[a]<dep[b])
		swap(a,b);
	int dif=dep[a]-dep[b];
	for (int i=LEV-1;i+1;--i)
		if (dif&(1<<i))
			a=up[a][i];
	if (a==b)
		return a;
	for (int i=LEV-1;i+1;--i)
		if (up[a][i]!=up[b][i])
			a=up[a][i],
			b=up[b][i];
	return up[a][0];
}

long long pw(long long a,long long b)
{
	if (b==0)
		return 1;
	if (b%2)	
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

void add_path(int v1,int v2,int TP)
{
	cnt[v1][TP]++;
	cnt[v2][TP]--;
}

void make_move(int v1,int v2)
{
	int q=lca(v1,v2);
	add_path(v1,q,1);
	add_path(v2,q,0);
}

long long ans=0;

void solve(int v,int par)
{
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i].first;
		if (to==par)
			continue;
		solve(to,v);
		cnt[v][0]+=cnt[to][0];
		cnt[v][1]+=cnt[to][1];
	}
	//cout<<" "<<v<<" "<<cnt[v][0]<<" "<<cnt[v][1]<<" "<<dir[v]<<endl;
	for (int d=0;d<=1;d++)
	{
		if (!(dir[v]&(1<<d)))
		{
			long long val=pw(2,cnt[v][d]);
			val--;
			if (val<0)
				val+=bs;
			ans+=val;
			if (ans>=bs)
				ans-=bs;
		}
	}
}

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
	cin>>a>>b>>tp;
	if (tp==0)
		g[a].push_back(make_pair(b,3)),
		g[b].push_back(make_pair(a,3));
	else
		g[a].push_back(make_pair(b,1)),
		g[b].push_back(make_pair(a,2));
}

dfs(1,1);

cin>>tests;
cur=1;

for (;tests;--tests)
{
	int v;
	cin>>v;
	make_move(cur,v);
	cur=v;
}

solve(1,1);

cout<<ans<<endl;

return 0;}