/*
A heartbeat skip, relationship
Inside a bubble bath
An icing drip below your lip
So we undo the math
A sudden slip between
My pathetic sedatives
A real-life script of how
Mistakes became our medicine, so

Delay the hurtful words
Of complicated overcast
Please take the message that I'm
Picking up my chin at last
I said my confidence
It gets stronger when you're next to me
But we pray from miles away
In quest for what we long to be

I might crumble, I might take a fall again
(Still missing you)
I might crumble, I might take a fall again
(Still missing you)
I might crumble, I might take a fall again
But you're my everlasting friend
Everlasting friend

A heartbeat skip, relationship
So we would stay up late
A teardrop drip below your lip
Beside the airport gate
A sudden slip from where
We used to be a year ago
A real-life script of how
Our hands would hold and not let go

But delay the mournful words
Of complicated overcast
Please take the message
That you taught me how to live at last
But I said my confidence
It gets stronger when you're next to me
But we wave respect goodbye
In quest for what we long to be, but

I might crumble, I might take a fall again
(Still missing you)
I might crumble, I might take a fall again
(Still missing you)
I might crumble, I might take a fall again
But you're my everlasting friend

Will you be coming home?
(Everlasting friend)
My everlasting friend, will you be coming home?
(Everlasting friend)

I might crumble, I might take a fall again
(Still missing you)
I might crumble, I might take a fall again
(Still missing you)
I might crumble, I might take a fall again

I might crumble, I might take a fall again
I might crumble, I might take a fall again
I might crumble, I might take a fall again
I might crumble, I might take a fall again
I just want to know that you'll be coming home
I just want to know that you'll be coming home
I just want to know that you'll be coming home
I just want to know that you'll be coming home
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
#define right asdashgasrhsdf

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 500031;

int n;
vector<int> g[N];
int mask[N];
int dep[N];
int subsize[N];

int sack[1<<22];

int timer,tin[N],tout[N],order[N];

int dp[1<<22];

int update(int v,int root)
{
	int res=-1e9;
	res=max(res,sack[mask[v]]+dep[v]-2*dep[root]);
	for (int i=0;i<22;i++)
	{
		res=max(res,sack[mask[v]^(1<<i)]+dep[v]-2*dep[root]);
	}
	return res;
}

void trace(int v)
{
	++timer;
	tin[v]=timer;
	order[timer]=v;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		trace(to);
	}
	tout[v]=timer;
}

void add_vertex(int v)
{
	int msk=mask[v];
	//cout<<msk<<"%%%"<<v<<endl;

	sack[msk]=max(sack[msk],dep[v]);
}

void solve(int v,int keep)
{
	//cout<<v<<"%"<<keep<<endl;

	vector<pair<int,int> > sons;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		sons.push_back(make_pair(subsize[to],to));
	}
	sort(sons.begin(),sons.end());
	reverse(sons.begin(),sons.end());

	for (int i=1;i<sons.size();i++)
	{
		solve(sons[i].second,0);
	}

	if (sons.size())
	{
		solve(sons[0].second,1);
	}

	for (int i=1;i<sons.size();i++)
	{
		int id=sons[i].second;
		for (int j=tin[id];j<=tout[id];j++)
		{
			dp[v]=max(dp[v],update(order[j],v));
		}
		for (int j=tin[id];j<=tout[id];j++)
		{
			add_vertex(order[j]);
		}
	}

	dp[v]=max(dp[v],update(v,v));
	add_vertex(v);

	if (keep==0)
	{
		for (int j=tin[v];j<=tout[v];j++)
		{
			int V=order[j];
			sack[mask[V]]=-1e9;
		}
	}

}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=2;i<=n;i++)
	{
		int par;
		cin>>par;
		g[par].push_back(i);
		string st;
		cin>>st;
		int here=st[0]-'a';
		mask[i]=mask[par];
		mask[i]^=(1<<here);
		dep[i]=dep[par]+1;
	}

	for (int i=n;i;--i)
	{
		subsize[i]=1;
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			subsize[i]+=subsize[to];
		}
	}

	for (int i=0;i<(1<<22);i++)
	{
		sack[i]=-1e9;
	}

	trace(1);

	solve(1,0);

	for (int i=n;i>=1;--i)
	{
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			dp[i]=max(dp[i],dp[to]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (i>1)
			cout<<" ";
		cout<<dp[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}