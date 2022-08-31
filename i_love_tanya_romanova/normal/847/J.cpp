/*
Nobody gonna take my car
I'm gonna race it to the ground
Nobody gonna beat my car
It's gonna break the speed of sound
Oooh it's a killing machine
It's got everything
Like a driving power big fat tyres
and everything

I love it and I need it
I bleed it yeah it's a wild hurricane
Alright hold tight
I'm a highway star

Nobody gonna take my girl
I'm gonna keep her to the end
Nobody gonna have my girl
She stays close on every bend
Oooh she's a killing machine
She's got everything
Like a moving mouth body control
and everything

I love her I need her
I seed her
Yeah She turns me on
Alright hold on tight
I'm a highway star

Nobody gonna take my head
I got speed inside my brain
Nobody gonna steal my head
Now that I'm on the road again
Oooh I'm in heaven again I've got everything
Like a moving ground an open road
and everything

I love it and I need it
I seed it
Eight cylinders all mine
Alright hold on tight
I'm a highway star

Nobody gonna take my car
I'm gonna race it to the ground
Nobody gonna beat my car
It's gonna break the speed of sound
Oooh it's a killing machine
It's got everything
Like a driving power big
fat tyres and everything

I love it and I need it
I bleed it
Yeah it's a wild hurricane
Alright hold on tight
I'm a highway star
I'm a highway star
I'm a highway star
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

const int N = 200031;

int n,m;
int a[N],b[N];
vector<int> list_of_edges[N];

struct edge{
	int a;
	int b;
	int cap;
	int flow;
};

int s,t;
int d[N],ptr[N],q[N];
vector<edge> e;
vector<int> g[N];

void add_edge(int a,int b,int cap){
	edge e1={a,b,cap,0};
	edge e2={b,a,0,0};
	g[a].push_back(e.size());
	e.push_back(e1);
	g[b].push_back(e.size());
	e.push_back(e2);
}

bool bfs(){
	queue<int> qu;
	qu.push(s);
	for (int i=0;i<=t;i++)
	{
		d[i]=-1;
	}
	d[s]=0;
	while (qu.size()>0){
		int v=qu.front();
		qu.pop();
		for (int i=0;i<g[v].size();i++){
			int id=g[v][i];
			int to=e[id].b;
			if (e[id].flow==e[id].cap)
				continue;
			if (d[to]!=-1)
				continue;
			d[to]=d[v]+1;
			qu.push(to);
		}
	}
	return (d[t]!=-1);
}

int dfs(int v,int flow){
	if (v==t||flow==0)
		return flow;
	for (;ptr[v]<g[v].size();ptr[v]++){
		int id=g[v][ptr[v]];
		int to=e[id].b;
		if (d[to]!=d[v]+1)
			continue;
		int pushed=dfs(to,min(flow,e[id].cap-e[id].flow));
		if (pushed){
			e[id].flow+=pushed;
			e[id^1].flow-=pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic(){
	int flow=0;
	while (true){
		if (!bfs())
			break;
		for (int i=0;i<=t;i++)
		{
			ptr[i]=0;
		}
		while (true){
			int pushed=dfs(s,10000);
			if (pushed==0)
				break;
			flow+=pushed;
		}
	}
	return flow;
}

int solve(int am){
	for (int i=0;i<=n+m+5;i++){
		g[i].clear();
	}
	e.clear();
	for (int i=1;i<=n;i++)
	{
		add_edge(0,i,am);
	}
	for (int i=1;i<=m;i++)
	{
		add_edge(a[i],i+n,1);
		add_edge(b[i],i+n,1);
		add_edge(i+n,n+m+1,1);
	}
	s=0;
	t=n+m+1;
	int here=dinic();
	return here;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;

	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		list_of_edges[a[i]].push_back(i);
		list_of_edges[b[i]].push_back(i);
	}

	int l,r;
	l=0;
	r=m;
	while (l<r){
		int mid=l+r;
		mid/=2;
		int here=solve(mid);
		if (here==m)
			r=mid;
		else
			l=mid+1;
	}

	solve(l);

	for (int i=0;i<e.size();i++){
		if (e[i].a>=1&&e[i].a<=n&&e[i].flow==1){
			int to=e[i].b;
			int e_id=to-n;
			//cout<<e_id<<"@"<<e[i].a<<" @"<<endl;
			if (b[e_id]==e[i].a)
				swap(a[e_id],b[e_id]);
		}
	}

	cout<<l<<endl;
	for (int i=1;i<=m;i++)
	{
		cout<<a[i]<<" "<<b[i]<<endl;
	}

	cin.get(); cin.get();
	return 0;
}