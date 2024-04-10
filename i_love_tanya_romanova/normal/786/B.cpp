/*
Dealing out the agony within
Charging hard and no one's gonna give in
Living on your knees, conformity
Or dying on your feet for honesty
Inbred, our bodies work as one
Bloody, but never cry submission
Following our instinct not a trend
Go against the grain until the end

Blood will follow blood
Dying time is here
Damage Incorporated

Slamming through, don't fuck with razorback
Stepping out? You'll feel our hell on your back
Blood follows blood and we make sure
Life ain't for you and we're the cure
Honesty is my only excuse
Try to rob us of it, but it's no use
Steamroller action crushing all
Victim is your name and you shall fall

Blood will follow blood
Dying time is here
Damage Incorporated

We chew and spit you out
We laugh, you scream and shout
All flee, with fear you run
You'll know just where we come from

Damage Incorporated

Damage jackals ripping right through you
Sight and smell of this, it gets me goin'
Know just how to get just what we want
Tear it from your soul in nightly hunt
Fuck it all and fucking no regrets
Never happy ending on these dark sets
All's fair for Damage Inc. you see
Step a little closer if you please

Blood will follow blood
Dying time is here
Damage Incorporated
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 500331;

int n,q,s;

vector<pair<int,int> > g[N*4];

long long t[N*4];
int where_is[N];

int MX;

set<pair<long long, int> > S;
set<pair<long long, int> >::iterator it;

int dwn(int x)
{
	return x*2;
}
int up(int x)
{
	return x*2+1;
}

void build(int v,int tl,int tr)
{
	MX=max(MX,v);
	if (tl==tr&&tl==s)
	{
		t[up(v)]=t[dwn(v)]=0;
	}
	else
		t[up(v)]=t[dwn(v)]=1e18;
	if (v!=1)
	{
		g[up(v)].push_back(make_pair(up(v/2),0));
	}
	if (tl==tr)
	{
		where_is[tl]=v;
		return;
	}

	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);

	g[dwn(v)].push_back(make_pair(dwn(v*2),0));
	g[dwn(v)].push_back(make_pair(dwn(v*2+1),0));

}

int START,GOAL;

void add_from(int v,int tl,int tr,int l,int r,int cost)// from START to vertices
{
	if (l>r)
		return;
	if (tl==l&&tr==r)
	{
		g[up(START)].push_back(make_pair(up(v),cost));
		g[up(START)].push_back(make_pair(dwn(v),cost));
		g[dwn(START)].push_back(make_pair(up(v),cost));
		g[dwn(START)].push_back(make_pair(dwn(v),cost));
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	add_from(v*2,tl,tm,l,min(r,tm),cost);
	add_from(v*2+1,tm+1,tr,max(tm+1,l),r,cost);
}

void add_to(int v,int tl,int tr,int l,int r,int cost) // from vertices to GOAL
{
	if (l>r)
		return;
	if (tl==l&&tr==r)
	{
		g[up(v)].push_back(make_pair(up(GOAL),cost));
		g[up(v)].push_back(make_pair(dwn(GOAL),cost));
		g[dwn(v)].push_back(make_pair(up(GOAL),cost));
		g[dwn(v)].push_back(make_pair(dwn(GOAL),cost));
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	add_to(v*2,tl,tm,l,min(r,tm),cost);
	add_to(v*2+1,tm+1,tr,max(tm+1,l),r,cost);
}

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>q>>s;

	build(1,1,n);

	for (;q;--q)
	{
		int tp;
		cin>>tp;
		if(tp==1)
		{
			int a,b,cost;
			cin>>a>>b>>cost;
			g[up(where_is[a])].push_back(make_pair(up(where_is[b]),cost));
			g[up(where_is[a])].push_back(make_pair(dwn(where_is[b]),cost));
			g[dwn(where_is[a])].push_back(make_pair(up(where_is[b]),cost));
			g[dwn(where_is[a])].push_back(make_pair(dwn(where_is[b]),cost));
			//continue;
		}
		if (tp==2) // from point to seg tree
		{
			int a,l,r,w;
			cin>>a>>l>>r>>w;
			START=where_is[a];
			add_from(1,1,n,l,r,w);
		}
		if (tp==3)// from seg tree to point
		{
			int a,l,r,w;
			cin>>a>>l>>r>>w;
			GOAL=where_is[a];
			add_to(1,1,n,l,r,w);
		}
	}

	for (int i=0;i<=MX*3+2;i++)
	{
		S.insert(make_pair(t[i],i));
	}

	while (S.size())
	{
		it=S.begin();
		pair<long long, int> p=(*it);
		S.erase(it);
		int qv=p.second;
		for (int i=0;i<g[qv].size();i++)
		{
			int to=g[qv][i].first;
			long long tcost=g[qv][i].second+t[qv];
			if (tcost<t[to])
			{
				S.erase(make_pair(t[to],to));
//				if (S.find(make_pair(t[to],S.erase(make_pair(t[to],tcost));
				t[to]=tcost;
				S.insert(make_pair(t[to],to));
			}
		}
	}

	for (int i=1;i<=n;i++)
	{
		int id=where_is[i];
		long long res=min(t[up(id)],t[dwn(id)]);
		if (res>1e17)
			res=-1;
		if (i>1)
			cout<<" ";
		cout<<res;
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}