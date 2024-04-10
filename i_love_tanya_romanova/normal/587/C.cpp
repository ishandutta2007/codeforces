/*
Through the clouds and rain of sand
Where the seeker walks the land
Endless moments of eternal pain
A shattered version of his past
Like a shadow in debris
But the ancient call remains

Watching you, watching me
Children of the seven seas
Came to be the reign supreme

He came through frozen land
He turned your gold to sand
The son of the morning star
He wore no crown of thorns
Raised his hands up to the sky
'Cause he was battleborn

Through the storm he oiled his pain
All this fight was not in vain
The day of reckoning is here

Paradise ain't a place
For a man that leaves no trace
In a wasteland of the fallen

He came thourgh frozen land
He turned your gold to sand
The son of the morning star
He wore no crown of thorns
Raised his hands up to the sky
Cause he was battelborn
He was battleborn! Yeah! He was battleborn

The son of the morning star!
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define l 17

using namespace std;

int n,m,tests;
vector<int> g[1<<20];
vector<int> ent[1<<17][18];

int tin[1<<20],tout[1<<20];
int timer;
int up[1<<18][18];
vector<int> cur;
int dep[1<<19];

vector<int> run_merge(vector<int> &v1,vector<int>& v2)
{
	vector<int> res;
	int ptr1=0;
	int ptr2=0;
	while (ptr1<v1.size()||ptr2<v2.size())
	{
		if (res.size()==10)
			break;
		if (ptr1==v1.size())
		{
			res.push_back(v2[ptr2]);
			++ptr2;
			continue;
		}
		if (ptr2==v2.size())
		{
			res.push_back(v1[ptr1]);
			++ptr1;
			continue;
		}
		if (v1[ptr1]<v2[ptr2])
		{
			res.push_back(v1[ptr1]);
			++ptr1;
			continue;
		}
		else
		{
			res.push_back(v2[ptr2]);
			if (v1[ptr1]==v2[ptr2])
				++ptr1;
			++ptr2;
		}
	}
	return res;
}

void dfs(int v,int p)
{
	tin[v]=timer;
	++timer;
	up[v][0]=p;
	for (int i=1;i<=l;i++)
	{
		up[v][i]=up[up[v][i-1]][i-1];
		ent[v][i]=run_merge(ent[v][i-1],ent[up[v][i-1]][i-1]);
	}
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (to==p)
			continue;
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
	if (upper(a,b))
		return a;
	if (upper(b,a))
		return b;
	for (int i=l;i>=0;--i)
		if (!upper(up[a][i],b))
			a=up[a][i];
	return up[a][0];
}

void resolve(int a,int b)
{
	int ddif=dep[a]-dep[b];
	for (int i=l;i>=0;--i)
	{
		if (ddif&(1<<i))
		{
			cur=run_merge(cur,ent[a][i]);
			a=up[a][i];
		}
	}
}
int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

scanf("%d",&n);
scanf("%d",&m);
scanf("%d",&tests);

//cin>>n>>m>>tests;
for (int i=1;i<n;i++)
{
	int a,b;
//	cin>>a>>b;	
	scanf("%d",&a);
	scanf("%d",&b);
	g[a].push_back(b);
	g[b].push_back(a);
}

for (int i=1;i<=m;i++)
{
	int id;
//	cin>>id;
	scanf("%d",&id);
	ent[id][0].push_back(i);
}

dfs(1,1);
/*
for (int i=1;i<=n;i++)
	cout<<"##"<<i<<" "<<dep[i]<<endl;
*/	
for (;tests;--tests)
{
	int a,b;
	//cin>>a>>b;
	int tt;
	//cin>>tt;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&tt);
	
	int q=lca(a,b);
	cur.clear();
//	cout<<a<<"$"<<q<<" "<<b<<" "<<dep[a]<<" "<<dep[b]<<" "<<dep[q]<<endl;
	resolve(a,q);
	resolve(b,q);
	cur=run_merge(cur,ent[q][0]);
//	cout<<"!"<<endl;
	while (cur.size()>tt)
		cur.pop_back();
	
//	cout<<cur.size();
	int sz=cur.size();
	printf("%d",sz);
	for (int i=0;i<cur.size();i++)
	{
		printf(" %d",cur[i]);
//		cout<<" "<<cur[i];
	}
	//cout<<endl;
	puts("");
}

//cin.get();cin.get();
return 0;}