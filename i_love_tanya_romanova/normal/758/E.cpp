/*
It gets ahead of us
Blind ambition meets our desperation
It gets ahead of us
It leads a charge to where we should not go
It makes no sense to me
Our willingness to hold on to belief
It got away from us
The thought of understanding what's around
Have we gone too far this time?
To argue from authority in this case
It just got away
I feel we've lost our place in time
It's getting closer now
The fear that we have held off for so long
It's getting closer now
To where we know there can be no return
It makes no sense to me
What has been set in motion here today
It makes no sense anymore
Was it too little, too late
Or too much too fast?
This time we've gone too far
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
int a[N],b[N],w[N],p[N];
vector<int> g[N];

vector<int> G[N];
int used[N];
long long should_remove[N],can_remove[N];
long long total_w[N];

int get_other(int id,int v)
{
	if (a[id]==v)
		return b[id];
	return a[id];
}

void trace(int v,int pedge)
{
	used[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int id=g[v][i];
		int to=get_other(id,v);
		if(used[to])
			continue;
		G[v].push_back(id);
		trace(to,id);
		//should_remove[v]+=should_remove[to];
		//can_remove[v]+=can_remove[to];
		long long rem_w=total_w[to]-should_remove[to];

		long long ohead=max(rem_w-p[id],0ll);
		//ohead=min(ohead,can_remove[to]-should_remove[to]);
		should_remove[to]+=ohead;

		long long smallest_sub=total_w[to]-can_remove[to];
		long long can_on_edge=max(p[id]-smallest_sub,0ll);
		can_on_edge=min(can_on_edge,0ll+w[id]-1);

		should_remove[v]+=should_remove[to];
		can_remove[v]+=can_remove[to];
		can_remove[v]+=can_on_edge;
		total_w[v]+=total_w[to];
		total_w[v]+=w[id];
	}
}

void solve(int v,long long should)
{
	long long still_have=should;
	vector<pair<long long, long long> > sons;

	for (int i=0;i<G[v].size();i++)
	{
		int id=G[v][i];
		int to=get_other(id,v);
		long long remove_there=should_remove[to];
		still_have-=remove_there;
		sons.push_back(make_pair(remove_there,to));
	}

	for (int i=0;i<G[v].size();i++)
	{
		int id=G[v][i];
		int to=get_other(id,v);
		long long can_add=can_remove[to]-should_remove[to];
		can_add=min(can_add,still_have);
		sons[i].first+=can_add;
		still_have-=can_add;
		long long rem_w_there=total_w[to]-sons[i].first;
		long long can_on_edge=max(p[id]-rem_w_there,0ll);
		can_on_edge=min(can_on_edge,0ll+w[id]-1);
		can_on_edge=min(can_on_edge,still_have);
		w[id]-=can_on_edge;
		p[id]-=can_on_edge;
		still_have-=can_on_edge;
	}

	for (int i=0;i<sons.size();i++)
	{
		solve(sons[i].second,sons[i].first);
	}
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
		cin>>a[i]>>b[i]>>w[i]>>p[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}

	trace(1,-1);

	/*for (int i=1;i<=n;i++)
	{
		cout<<total_w[i]<<" "<<should_remove[i]<<" "<<can_remove[i]<<endl;
	}*/

	for (int i=1;i<=n;i++)
	{
		if (can_remove[i]<should_remove[i])
		{
			cout<<-1<<endl;
			return 0;
		}
	}

	solve(1,should_remove[1]);

	cout<<n<<endl;
	for (int i=1;i<n;i++)
	{
		cout<<a[i]<<" "<<b[i]<<" "<<w[i]<<" "<<p[i]<<"\n";
	}

	cin.get(); cin.get();
	return 0;
}