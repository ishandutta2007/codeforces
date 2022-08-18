/*
Night time, see the castles burning
Smoke in the skies and tears in their eyes
As the world keeps turning

Sleep now, hear a distant thunder
It's far away at least for today
Close your eyes and wonder

Spring turns so quickly to summer
Summer so quickly to fall
It seemed far away or it was yesterday
When time didn't matter at all

And then you met your winter
While dancing with her daughters
Till tired and cold, were much wiser than bold
You wait for tomorrow to call

All of your life you have waited alone for a Savior
He's not coming
A carousel horse who is constantly lost
Standing still but always running

And all of those things that you needed so bad
You have found they mean nothing
And, oh Lord, I'm coming home

I'm searching through the haze
That's drifting through my mind
Stare in my looking glass
And wonder who I'll find

No one would listen
To a man upon the water
Until they were old and their mountains of gold
Couldn't buy any more time

All of your life you have waited alone for the Savior
He's not coming
A carousel horse who is constantly lost
Standing still but always running

And all of those things that you needed so bad
You have found they mean nothing
And, oh Lord, I'm coming home

All of your life you have waited alone for the Savior
He's not coming
A carousel horse who is constantly lost
Standing still but always running

And all of those things that you needed so bad
You have found they mean nothing
And, oh Lord, I'm coming home
And, oh Lord, I'm coming home
And, oh Lord, I'm coming
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

#define eps 1e-16
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 200005;

using namespace std;

int n;
int c[N];
map<int, int> S[N];
int w[N];
int used[N];
int mx[N];
long long cnt[N];
vector<int> g[N];
long long ans[N];

void run_merge(int a,int b)
{
	if (S[w[a]].size()<S[w[b]].size())
	{
		swap(w[a],w[b]);
	}
	int id=w[a];
	map<int, int>::iterator it;
	
	for (it=S[w[b]].begin();it!=S[w[b]].end();it++)
	{
		int val=(*it).first;
		int amount=(*it).second;
		S[id][val]+=amount;
		if (S[id][val]>mx[id])
		{
			mx[id]=S[id][val];
			cnt[id]=0;
		}
		if (S[id][val]==mx[id])
			cnt[id]+=val;
	}
}

void dfs(int v)
{
	used[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
		run_merge(v,to);
	}
//	cout<<v<<" "<<mx[w[v]]<<" "<<cnt[w[v]]<<endl;
	ans[v]=cnt[w[v]];
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		S[i][c[i]]=1;
		w[i]=i;
		mx[i]=1;
		cnt[i]=c[i];
	}
	
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1);
	
	for (int i=1;i<=n;i++)
	{
		if (i>1)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	
	return 0;
}