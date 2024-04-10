/*
I take a look around,
The blood of our men has painted the ground
There are corpses lying everywhere
Some try to pray, some cry in despair
As our enemy cuts its way through our lines
Desperate thoughts take over our minds
Is this to be the end of our days?

The overwhelming enemy
Rides our front lines down
With hate in their faces, with hate in their sound
Houndreds of men lying wounded on the ground
No one can help them,
To their destiny they're bound

I think of my family, I think of my home
Interrupted by a fearful tone:
"We're practically dead, they'll slaughter us all!"
Through a cloud of dust I see our right wing fall

This cursed war will swallow us all
What will happen to our loved-ones,
The ones we're fighting for?
I will not stand and watch this army fall
We will fight back, hear us roar

Pull our lines together
Our fury is greater than the worst stormy weather
I grasp the sword in my hand, this is for my brothers,
This is for my land
With blood on my face to battle I ride
With dust in my eyes, with faith in my heart
Until death do us part

From the skies a man came down to earth
He lead our way and rode first
How dark the night may seem
A new day always heals

I stroll across the field, the morning has broken,
Our victory's been sealed
The hooves have plowed the ground to mud,
Familiar faces in ponds of blood
A snowflake lands on my face,
Melts and runs away
The sun rose red that day
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
#define bsize 256
#define N ((1<<21)+31)
//#define root 1
#define M 150

using namespace std;

int n,m;
vector<int> g[N];
int need[N];
int used[N];

int dp[N],fur[N];
int down[N];
int fup[N];
vector<pair<int, int> > downs[N];

void solve(int v)
{
	used[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		solve(to);
		if (dp[to]>0||need[to]==1)
		{
			downs[v].push_back(make_pair(fur[to]+1,to));
			dp[v]+=dp[to]+2;
			fur[v]=max(fur[v],fur[to]+1);
		}
	}
	sort(downs[v].begin(),downs[v].end());
}

void solve2(int v,int par)
{
	used[v]=1;
	if (v!=1)
	{
		if (fup[par]>0)
			fup[v]=fup[par]+1;
		if (need[par])
		{
			fup[v]=max(fup[v],1);
		}
		int sz=downs[par].size();
		for (int i=sz-1;i>=sz-3;i--)
		{
			if (i<0)
				break;
			if (downs[par][i].second==v)
				continue;
			//cout<<v<<"%" <<par<<" "<<downs[par][i].first<<" "<<downs[par][i].second<<endl;
			fup[v]=max(fup[v],downs[par][i].first+1);
		}
		int rem=dp[par]-dp[v];
		if (dp[v]>0||need[v]==1)
			rem-=2;
		
//		cout<<v<<"   "<<rem<<endl;
		
		if (rem>0||need[par]==1)
		{
			dp[v]=dp[v]+rem+2;
		}
		fur[v]=max(fur[v],fup[v]);
	}
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		solve2(to,v);
	}
}

int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		need[x]=1;
	}
	
	solve(1);
	
	for (int i=1;i<=n;i++)
		used[i]=0;
		
	solve2(1,1);
	
	int ans=1e9;
	int bp=1;
	
	for (int i=1;i<=n;i++)
	{
	//	cout<<i<<" "<<dp[i]<<" "<<fup[i]<<" "<<fur[i]<<endl;
		int here=dp[i]-fur[i];
		if (here<ans)
			ans=here,
			bp=i;
	}
	
	cout<<bp<<endl;
	cout<<ans<<endl;
	
	return 0;
	
}