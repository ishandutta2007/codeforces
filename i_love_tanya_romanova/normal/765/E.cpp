/*
The unsaid tone of weak despair
Fail to resonate
Frayed end of our binding threads
Will disintegrate
By the laws our physique state
Failure to communicate
None too sentient
Hear no, see no works its magic
Against all function
Ongoing choices the trials will end
Filter the nonsense and laugh at what's left
Indecision/non-vision what matters taken away
Look at the shell that is you
Empty, fragile, weak
Soon the battle is over
Lost to apathy
So overcome with pointless tears
To test pain receptors
Nothing matters ever here
Put up a non-reaction
These eyes will never see
Covered up from reality
Look at the shell that is you
Empty, fragile, weak
Soon the battle is over
Lost to apathy
The unknown world that you deny
No priority
Cannot fail if you never start
How predictable
I want to know where did it end
For madness to start
Always the sceptic and never be part
Introvertive/non-descriptive
It matters not, not
Look at the shell that is you
Empty, fragile, weak
Look at the shell that is you
Empty, fragile, weak
Soon the battle is over
Lost to apathy
The shell that is you
Empty, fragile, weak
The battle is over
Lost to apathy
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

#define eps 1e-14
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n;
set<int> g[N];
pair<int,int> cur_ps[N];
vector<pair<int,int> > candidates;
set<pair<pair<int,int>,int> > S;
set<pair<pair<int,int>,int> > ::iterator it;
int have_solution;
int ans;

int get_adj(int v)
{
	set<int>::iterator it;
	if (g[v].size()==0)
		return -1;

	it=g[v].begin();
	return (*it);
}

void kill_edge(int a,int b)
{
	if (a==-1||b==-1)
		return ;

	g[a].erase(b);
	g[b].erase(a);
}

void kill_vertex(int v)
{
	int stop_point=cur_ps[v].second;
	if (stop_point==-1)
		return ;
	//cout<<v<<" "<<stop_point<<endl;
	while (v!=stop_point)
	{
		int to=get_adj(v);
		//cout<<v<<"%"<<to<<" "<<stop_point<<endl;
		kill_edge(v,to);
		v=to;
	}
	//cout<<"$$$"<<endl;
}

int dep[N];

pair<int,int> make_move(pair<int,int> p){
	set<int>::iterator it;
	int qv=p.second;
	int ban=p.first;
	for (it=g[qv].begin();it!=g[qv].end();it++)
	{
		int to=(*it);
		if (to!=ban)
			return make_pair(qv,to);
	}
	return make_pair(qv,-1);
}

void run_trace(int v)
{
	if (cur_ps[v].second==-1)
		while (true);

	if (have_solution)
		return ;

	while (g[cur_ps[v].second].size()<=2)
	{
		//cout<<v<<" "<<cur_ps[v].first<<" "<<cur_ps[v].second<<"%"<<endl;
		//cin.get();
		cur_ps[v]=make_move(cur_ps[v]);
		if (cur_ps[v].second==-1)
		{
			have_solution=1;
			ans=dep[v];
			return ;
		}
		else
			dep[v]++;
	}

	if (g[cur_ps[v].second].size()==1) // leaf
	{
		have_solution=1;
		ans=dep[v];
		return ;
	}
	else
	{
		it=S.lower_bound(make_pair(make_pair(cur_ps[v].second,dep[v]),-1));
		if (it!=S.end())
		{
			pair<pair<int,int>,int> here=(*it);
			if (here.first==make_pair(cur_ps[v].second,dep[v]))
				candidates.push_back(here.first);
		}
		S.insert(make_pair(make_pair(cur_ps[v].second,dep[v]),v));
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
		int a,b;
		cin>>a>>b;
		g[a].insert(b);
		g[b].insert(a);
	}


	for (int i=1;i<=n;i++)
	{
		if (have_solution)
			break;

		if (g[i].size()==1)
		{
			cur_ps[i]=make_pair(i,i);
			run_trace(i);
		}
		//cout<<S.size()<<endl;

	}

	while (candidates.size()>0&&have_solution==0)
	{
		pair<int,int> v=candidates.back();
		//cout<<v.first<<"%"<<v.second<<endl;

		while (candidates.size()>0&&candidates.back()==v)
			candidates.pop_back();
		vector<int> to_remove;
		while (true)
		{
			it=S.lower_bound(make_pair(v,-1));
			if (it==S.end())
				break;
			if ((*it).first!=v)
				break;
			pair<pair<int,int>,int> p=(*it);
			to_remove.push_back((*it).second);
			S.erase(it);
		}

		/*for (int i=0;i<to_remove.size();i++)
		{
			cout<<"%"<<to_remove[i]<<endl;
		}
*/
		for (int i=0;i+1<to_remove.size();i++)
		{
			kill_vertex(to_remove[i]);
			//cout<<"DONE"<<endl;
		}

		if (to_remove.size()==0)
			continue;
		run_trace(to_remove.back());
	}

	while (ans%2==0&&ans>0)
		ans/=2;

	if (!have_solution)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}

	cin.get(); cin.get();
	return 0;
}