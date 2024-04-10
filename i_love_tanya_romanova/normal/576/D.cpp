/*
Rise! The rage of our ancient pride
Raise! The flag of blood and holy light
Hate's the power we've been saving up
So let's fight them under red stripe on the
White flag fluttering so proud and free
We shall get our sincere liberty
Dreams of freedom are to get so real
There's no one who dares to stop us on this
Way of long-awaited sacrifice
Fire of justice burning in our eyes
We're the nation who can shake the skies
There's no one who dares to stop us on this
Way we march together in all arms
Now's the time for us to put out stars
We don't like and to light new ones up
So let's march on under red stripe on the white

Bells are calling us to gather up
Hail to true and ancient our Gods
Hail to all the people who act free
What will be will be but we shall raise the
Flag of true and real liberty
Raise! The flag of our History
There's no way to suffer lies around
That's no more we're going out of underground

Abandon all hope!
Abandon all hope!
Abandon all hope!
Abandon all hope!

Light of darkness we don't ever mind
All we see the years of lies behind
Now we are to break it finally
What will be will be but we shall rise to
Live forever mighty, proud and free
It's the only way for us to be
You can run but you can't ever hide
We shall kill you if you're our enemy

Abandon all hope!
Abandon all hope!
Abandon all hope!
Abandon all hope!
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define MAG 1000

using namespace std;

int n,m;
vector<pair<int, pair<int, int> > > edges;
int reach[1<<20];
long long ans;
int mom;

queue<int> qu;
long long dist[1<<20];
vector<int> g[1<<19];

void trace(int start)
{
	for (int i=0;i<n;i++)
		if (reach[i])
			dist[i]=mom,
			qu.push(i);
		else
			dist[i]=1e18;
	
	while (qu.size())
	{
		int v=qu.front();
		qu.pop();
		for (int i=0;i<g[v].size();i++)
		{
			int to=g[v][i];
			if (dist[to]<=dist[v]+1)
				continue;
			dist[to]=dist[v]+1;
			qu.push(to);
		}
	}
	ans=min(ans,dist[n-1]);
}

vector<vector<int> > graph;

void add_edge(pair<int,pair<int, int> > p)
{
	g[p.second.first].push_back(p.second.second);
	graph[p.second.first][p.second.second]=1;
}

int glog(long long x)
{
	if (x==0)
		return 0;
	return glog(x/2)+1;
}

int new_reach[1<<19];

vector<vector<int> > PW[100];

unsigned int one=1;

unsigned int G1[200][200],G2[200][200];

void show(vector<vector<int> > v)
{
	for (int i=0;i<v.size();i++)
	{
		for (int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
	cout<<"#"<<endl;
}

vector<vector<int> > fast_shit(vector<vector<int> > &v1,vector<vector<int> > &v2)
{
	for (int i=0;i<v1.size();i++)
		for (int j=0;j<n/32+3;j++)
			G1[i][j]=G2[i][j]=0;
	
//	show(v1);
//	show(v2);
	// res[i][j]|=a[i][k]&b[k][j]
	// res[i][j]|=A[i][k]&B[j][k]
	for (int i=0;i<v1.size();i++)
		for (int j=0;j<v1.size();j++)
		{
			if (v1[i][j])
				G1[i][j/32]|=(one<<(j%32));
			if (v2[j][i])
				G2[i][j/32]|=(one<<(j%32));
		}
	vector<vector<int> > res;
	res=v1;
	for (int i=0;i<v1.size();i++)
		for (int j=0;j<v1.size();j++)
			{
				unsigned int found=0;
				for (int k=0;k<n/32+3&&found==0;k++)
					found|=(G1[i][k]&G2[j][k]);
				res[i][j]=(found!=0);
			}
	return res;
}

vector<vector<int> > ONE;

void update_moment(long long dif)
{
	vector<vector<int> > V=graph;
	PW[0]=V;
	int need=glog(dif)+2;
	for (int i=1;i<=need;i++)
		PW[i]=fast_shit(PW[i-1],PW[i-1]);
	//show(PW[0]);
	vector<vector<int> >R=ONE;
	for (int i=need;i+1;--i)
		if (dif&(1ll<<i))
		{
			//cout<<"!!"<<i<<endl;
			R=fast_shit(R,PW[i]);
			//show(R);
		}
	for (int i=0;i<n;i++)
		new_reach[i]=0;
	
	//show(R);
	
	for (int i=0;i<R.size();i++)
		for (int j=0;j<R.size();j++)
			if (R[i][j]==1&&reach[i]==1)
				new_reach[j]=1;
	for (int i=0;i<n;i++)
		reach[i]=new_reach[i];
/*	for (int i=0;i<n;i++)
		cout<<"@"<<reach[i];
	cout<<endl;*/
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
graph.resize(n);
for (int i=0;i<n;i++)
	graph[i].resize(n);

ONE.resize(n);
for (int i=0;i<n;i++)
{
	ONE[i].resize(n);
	for (int j=0;j<n;j++)
		ONE[i][j]=(i==j);
}

for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
		graph[i][j]=0;

for (int i=1;i<=m;i++)
{
	int a,b,c;
	cin>>a>>b>>c;
	--a;
	--b;
	edges.push_back(make_pair(c,make_pair(a,b)));
}

sort(edges.begin(),edges.end());

reach[0]=1;
ans=1e18;

mom=0;

for (int i=0;i<edges.size();i++)
{
	trace(mom);
	/*
	for (int j=0;j<n;j++)
		cout<<reach[j]<<" ";
	cout<<"  @"<<endl;
	*/
	int dif=edges[i].first-mom;
	update_moment(dif);
	add_edge(edges[i]);
	mom+=dif;
}
/*
for (int i=0;i<n;i++)
	cout<<reach[i]<<" ";
*/
trace(mom);

if (ans>1e15)
	cout<<"Impossible"<<endl;
else
	cout<<ans<<endl;
	
//cin.get();cin.get();
return 0;}