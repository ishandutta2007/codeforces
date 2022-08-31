/*
As you walk the path of least resistance
Is it as simple as you claim it to be?
Your tongue, your eyes
Your lies, they do decieve you

I stand firm in my solidarity
The path I walk, I walk it with my own resolve
When darkness falls we are reborn
Our dream since the fall of man
We are reborn

My beliefs are not antiquated
We are the hope
Silence them all with not just words
Let resolution be our voice

I stand firm in my solidarity
The path I walk, I walk it with my own resolve
When darkness falls we are reborn
Our dream since the fall of man
We are reborn

We are the remnant
We the remnant will silence them all
We are the faithful
We the faithful will silence them all

When darkness falls we are reborn
Our dream since the fall of man
We are reborn
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-13
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

const int N = 250000;

int n,L;
int x[N],d[N],t[N],p[N];
vector<int> X;
vector<pair<int, pair<int, int> > > g[N];
map<int, int> mapp,rmap;
int dist[N];
set<pair<int, int> > S;
set<pair<int, int> > ::iterator it;
pair<int, int> par[N];

void add_point(int x)
{
	X.push_back(x);
}

int get_id(int x)
{
	return mapp[x];
}

void add_edge(int a,int b,int c,int tp)
{
	g[a].push_back(make_pair(b,make_pair(c,tp)));
}

void mapp_points()
{
	sort(X.begin(),X.end());
	
	int cnt=0;
	
	for (int i=0;i<X.size();i++)
	{
		if (i==0||X[i]!=X[i-1])
		{
			mapp[X[i]]=cnt;
			rmap[cnt]=X[i];
			++cnt;
		}
	}
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>L;
	
	add_point(0);
	add_point(L);
	
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>d[i]>>t[i]>>p[i];
		if (x[i]-p[i]>=0)
			add_point(x[i]-p[i]);
		add_point(x[i]+d[i]);
	}
	
	mapp_points();
	
	for (int i=1;i<=n;i++)
	{
		if (x[i]-p[i]<0)
			continue;
		int id1=get_id(x[i]-p[i]);
		int id2=get_id(x[i]+d[i]);
		add_edge(id1,id2,p[i]+t[i],i);
	}
	
	int N=mapp.size();
	
	for (int i=0;i+1<N;i++)
	{
		int x1=rmap[i];
		int x2=rmap[i+1];
		add_edge(i,i+1,x2-x1,0);
		add_edge(i+1,i,x2-x1,0);
	}
	
	for (int i=0;i<N;i++)
		dist[i]=1e9+1e6;
	
	dist[0]=0;
	for (int i=0;i<N;i++)
		S.insert(make_pair(dist[i],i));
	
	while (S.size())
	{
		it=S.begin();
		pair<int, int> tp=(*it);
		S.erase(it);
		int qv=tp.second;
		for (int i=0;i<g[qv].size();i++)
		{
			int to=g[qv][i].first;
			int tcost=g[qv][i].second.first+dist[qv];
			if (tcost<dist[to])
			{
				S.erase(make_pair(dist[to],to));
				par[to]=make_pair(qv,g[qv][i].second.second);
				dist[to]=tcost;
				S.insert(make_pair(dist[to],to));
			}
		}
	}
	
	cout<<dist[N-1]<<endl;
	
	vector<int> ans;
	
	int cur=N-1;
	while (cur!=0)
	{
		pair<int,int> P=par[cur];
		if (P.second>0)
			ans.push_back(P.second);
		cur=P.first;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
	
	return 0;
}