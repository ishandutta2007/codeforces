/*
I am you are me
Good woman said you gotta believe
Submerge into the urge of we
Deliciously the mystery

[Chorus:]
One big mob aw yea aw yea
One big mob aw yea aw yea
Ek bara mala aw yea aw yea
Ek bara mala aw yea aw yea

Ooze into into my noodle
East or west shepherd or poodle
Ladybug pinetree
To mingle with the bumblebee
A lover to the sun
And a brother to the cool breeze

[Chorus]

Scrawled upon the wall
Of a bathroom stall
A stranger wrote a note
That spoke to all

One two buckle my shoe
Take care of me
'Cause I might be you

[Chorus]

We live in the city
We live in the jungle
It's time to be drinking
A thimble humble
Everything you ever see
Is never more than you and me
Give it on in to the beauty of the mystery

One big mob in one big home
A broken home
I'd like to share some air with you
Some air with you
A morning forest full of truths
The green is blue
The head that's getting pregnant lives
To give and give
What was I thinking in my head
The color red
Breaking hearts instead of bread
Something I said
Checkmated by frustration...
...Need to be cut loose
A different kind of being lost
...A sullen cost

Picaboo street
in Timbuktu
Do I need repeat
That a boy
named Sue
Rockin'
to the beat
Of the kangaroo
Let me kiss your feet
And your
forehead
too
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

int n,m,a[N],b[N];
vector<int> g[N];
int used[N];

int dep[N];

vector<int> this_comp;
vector<pair<int,int> > order;
vector<pair<int,pair<int,int> > > solution;
int par[N];
int in_st[N];
int used_edge[N];
int par_edge[N];
set<int> sons[N];

vector<int> with_dep[N];
vector<int> not_st_list[N];
set<int>::iterator it;

void trace(int v){
	used[v]=1;
	this_comp.push_back(v);
	for (int i=0;i<g[v].size();i++)
	{
		int id=g[v][i];
		int to=a[id]+b[id]-v;
		if (used[to])
			continue;
		par[to]=v;
		sons[v].insert(to);
		par_edge[to]=id;
		dep[to]=dep[v]+1;
		in_st[id]=1;
		trace(to);
	}
}

void process_vertex(int v){
	vector<int> free_edges;

	for (int i=0;i<g[v].size();i++)
	{
		int id=g[v][i];
		if (used_edge[id])
			continue;
		if (in_st[id])
			continue;
		free_edges.push_back(id);
	}

	while (free_edges.size()>1){
		int a=free_edges.back();
		free_edges.pop_back();
		int b=free_edges.back();
		free_edges.pop_back();
		used_edge[a]=1;
		used_edge[b]=1;
		solution.push_back(make_pair(v,make_pair(a,b)));
	}

	// either 0 or 1 free edges

	if (free_edges.size()==1){
		if (par[v]==0){
			int id=free_edges[0];
			used_edge[id]=1;
			return;
		}
		solution.push_back(make_pair(v,make_pair(par_edge[v],free_edges[0])));
		used_edge[par_edge[v]]=1;
		used_edge[free_edges[0]]=1;
		sons[par[v]].erase(v);
		return;
	}

}

int get_out_of_st(int v){
	while (not_st_list[v].size()>0){
		int id=not_st_list[v].back();
		if (used_edge[id]==0)
			return id;
		not_st_list[v].pop_back();
	}
	return -1;
}

void resolve(int v){
	// 0 free edges now
	if (par[v]==0)
		return;
	if (used_edge[par_edge[v]])
		return;
	if (sons[par[v]].size()>1){ // take 2 and merge
		sons[par[v]].erase(v);
		it=sons[par[v]].begin();
		int othr=(*it);
		sons[par[v]].erase(othr);
		used_edge[par_edge[othr]]=1;
		used_edge[par_edge[v]]=1;
		solution.push_back(make_pair(par[v],make_pair(par_edge[othr],par_edge[v])));
		return;
	}
	int edge_in_father=get_out_of_st(par[v]);
	if (edge_in_father!=-1){
		sons[par[v]].erase(v);
		solution.push_back(make_pair(par[v],make_pair(par_edge[v],edge_in_father)));
		used_edge[par_edge[v]]=1;
		used_edge[edge_in_father]=1;
		return ;
	}
	// father and his father
	if (dep[v]==1) // no grandpa
		return;
	int v2=par[par[v]];
	sons[par[v]].erase(v);
	sons[v2].erase(par[v]);
	solution.push_back(make_pair(par[v],make_pair(par_edge[v],par_edge[par[v]])));
	used_edge[par_edge[v]]=1;
	used_edge[par_edge[par[v]]]=1;
}

void solve(int v)
{
	this_comp.clear();
	trace(v);
	int max_dep=0;

	for (int i=0;i<this_comp.size();i++)
	{
		max_dep=max(max_dep,dep[this_comp[i]]);
	}

	order.clear();
	for (int i=0;i<this_comp.size();i++)
	{
		int cur_v=this_comp[i];
		for (int j=0;j<g[cur_v].size();j++)
		{
			int e_id=g[cur_v][j];
			if (in_st[e_id])
				continue;
			not_st_list[cur_v].push_back(e_id);
		}
		order.push_back(make_pair(dep[cur_v],cur_v));
		with_dep[dep[cur_v]].push_back(cur_v);
	}

	for (int i=max_dep;i>=0;--i)
	{
		for (int j=0;j<with_dep[i].size();j++)
		{
			int v_id=with_dep[i][j];
			process_vertex(v_id);
		}
		for (int j=0;j<with_dep[i].size();j++)
		{
			int v_id=with_dep[i][j];
			resolve(v_id);
		}
		with_dep[i].clear();
	}

}

int get_other(int id,int v){
	return a[id]+b[id]-v;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}

	for (int i=1;i<=n;i++)
	{
		if (used[i])
			continue;
		solve(i);
	}

	cout<<solution.size()<<endl;

	for (int i=0;i<solution.size();i++)
	{
		int id1=solution[i].second.first;
		int id2=solution[i].second.second;
		cout<<get_other(id1,solution[i].first)<<" "<<solution[i].first<<" "<<get_other(id2,solution[i].first)<<"\n";
	}
	cin.get(); cin.get();
	return 0;
}