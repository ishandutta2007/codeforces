/*
As I went a walking
One morning in spring
I met with some travelers
On an old country lane
One was an old man
The second a maid
The third was a young boy who smiled as he said

"With the wind in the willows
The birds in the sky
There's a bright sun to warm us wherever we lie...
We have bread and fishes and a jug of red wine
To share on our journey with all of mankind".

So I asked them to tell me their name and their race
So I could remember each smile on their face
"Our name, they mean nothing...
They change throughout time
So come sit beside us and share in our wine"

So I sat down beside them
With flowers all around
We et from a mantle
Spread out on the ground
They told me of prophets
And peoples and kings
And all of the one god that knows everything
"We're traveling to Glaston
Over England's gren lanes
To hear of men's troubles
To hear of their pains
We travel the wide world
Over land and the sea
To tell all the people
How they can be free..."

So sadly I left them
On that old country lane
For I knew that I'd never see them again
One was an old man
The second a maid
The third was a young boy who smiled as he said...
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
const int N = 501031;

int n,m,d[N];
vector<int> unk;
int cnt[10];

int a[N],b[N];
vector<int> g[N];
int used[N];

int up[N][20];

vector<int> odd;

int timer;
int par_edge[N];
int tin[N],tout[N];
vector<int> G[N];

void dfs(int v,int p=1)
{
	++timer;
	tin[v]=timer;
	used[v]=1;
	up[v][0]=p;

	for (int i=1;i<20;i++)
	{
		up[v][i]=up[up[v][i-1]][i-1];
	}

	for (int i=0;i<g[v].size();i++)
	{
		int to_id=g[v][i];
		int to=a[to_id]+b[to_id]-v;
		if (used[to])
			continue;
		G[v].push_back(to);
		par_edge[to]=to_id;
		dfs(to,v);
	}
	++timer;
	tout[v]=timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=19; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

vector<int> ans;

int flag[N];

void make_flip(int a,int b)
{
	flag[a]^=1;
	flag[b]^=1;
}

void trace(int v)
{
	for (int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		trace(to);
		flag[v]^=flag[to];
	}
	if (flag[v])
		ans.push_back(par_edge[v]);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>d[i];
		if (d[i]==-1)
			unk.push_back(i);
		else
		{
			cnt[d[i]]++;
		}
	}

	if (cnt[1]%2==1&&unk.size()==0)
	{
		cout<<-1<<endl;
		return 0;
	}

	if (cnt[1]%2)
	{
		int val=unk.back();
		unk.pop_back();
		d[val]=1;
	}
	for (int i=0;i<unk.size();i++)
	{
		d[unk[i]]=0;
	}

	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}

	dfs(1);

	for (int i=1;i<=n;i++)
	{
		if (d[i]==1)
		{
			odd.push_back(i);
		}
	}

	for (int i=0;i<odd.size();i+=2)
	{
		int a=odd[i];
		int b=odd[i+1];
		int l=lca(a,b);
		make_flip(a,l);
		make_flip(b,l);
	}

	trace(1);

	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
	{
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}