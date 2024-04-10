/*
Fantasize exploding hands
Archaic science, master plan
Yeah, hear the war cry watch the crow fly

When your body's set, it never fails
Then you hear the tale of tales

Bound and gagged
You're in a reign of fire
Spells and magic
In the reign of fire

Complacency with all
A strong need to bathe in gall
Yeah hear the war cry, watch the crow fly

When your body's set, it never fails
Then you hear the tale of tales

Bound and gagged
You're in the reign of fire
Spells and magic
In the reign of fire

Feel the hexes
In the reign of fire
Find what sex is
In the reign of fire

Ya I sold my soul to give to you
I sold my soul, let me pull you through
Never fails, no
Oh it never fails

Feel the hexes
In the reign of fire
Find what sex is
In the reign of fire

Reign of fire
Reign of fire

Oh
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

using namespace std;

int n;
vector<int> g[1<<15];
int leaves,root;
int dp[5005][5005][2];
vector<int> sons[1<<15];
int subsize[5005];
int knap[5005][3],nknap[5005][3];
int used[5005];

void solve(int v)
{
	if (g[v].size()==1)
		subsize[v]=1;
	
	used[v]=1;
	
	vector<int> sons;
	
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		sons.push_back(to);
		solve(to);
		subsize[v]+=subsize[to];
	}
	
	for (int i=0;i<=subsize[v];i++)
		dp[v][i][0]=dp[v][i][1]=1e9;
	
	if (sons.size()==0)
	{
		dp[v][0][0]=dp[v][1][1]=0;
		return;
	}
	
	int ttl=0;
	for (int i=0;i<=subsize[v];i++)
		knap[i][0]=knap[i][1]=nknap[i][0]=nknap[i][1]=1e9;
	
	knap[0][0]=knap[0][1]=0;
	
	for (int i=0;i<sons.size();i++)
	{
		for (int j=0;j<=ttl+subsize[sons[i]];j++)
			nknap[j][0]=1e9,
			nknap[j][1]=1e9;
		
		int id=sons[i];
		
		for (int j=ttl;j>=0;--j)
			for (int q=0;q<=subsize[id];q++)
				for (int val1=0;val1<=1;val1++)
					for (int val2=0;val2<=1;val2++)
						nknap[j+q][val1]=min(nknap[j+q][val1],knap[j][val1]+dp[id][q][val2]+(val1!=val2));
		
		for (int j=0;j<=ttl+subsize[id];j++)
			knap[j][0]=nknap[j][0],
			knap[j][1]=nknap[j][1];
		
		ttl+=subsize[id];
	}
	for (int i=0;i<=subsize[v];i++)
		dp[v][i][0]=knap[i][0],
		dp[v][i][1]=knap[i][1];
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
	int a,b;
	cin>>a>>b;
	g[a].push_back(b);
	g[b].push_back(a);
}

if (n==2)
{
	cout<<1<<endl;
	return 0;
}

for (int i=1;i<=n;i++)
	if (g[i].size()==1)
		++leaves;
	
root=1;
while (g[root].size()==1)
	++root;

solve(root);

//cout<<leaves<<" "<<subsize[root]<<endl;


//cout<<dp[root][leaves/2][0]<<" "<<dp[root][leaves/2][1]<<endl;

cout<<min(dp[root][leaves/2][0],dp[root][leaves/2][1])<<endl;

//cin.get();cin.get();
return 0;}