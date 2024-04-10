/*
Traveling down life's highway
We carry the heavy load
Where will we be, be tomorrow
Somewhere down the road
We won't forget the friends
We made along the way
Soon we'll be together
Together one fine day

Where the lightning strikes
Is where we're gonna be
Stood on the edge of tomorrow
There waits our destiny

I hear the sound of rolling thunder
The beating of a drum
There's many been, been before us
There's many yet to come
We see the day
The new day dawning
It's just begun
We march into the future
Towards the rising sun

(See the light,
hear the thunder,
the new day)

Beyond the wide, the wide horizon
There's many paths to tread
A journey filled, filled with wonder
Is waiting just ahead

Where the lightning strikes
Is where we're gonna be
Stood on the edge of tomorrow
There waits our destiny

Where the lightning strikes
Is where we're gonna be
Stood on the edge of tomorrow
There waits our destiny
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
#define N 1031

using namespace std;

string st;
int n,m;
int bad[N][N];
int dist[N][N];
int have[N][N];
int memo[5][N][N];

deque<pair<int, int> >qu;
int ans,QD;
int bst[N];

bool outside(int a,int b)
{
	return (a<1||a>n||b<1||b>m);
}

void tryy(int a,int b)
{
	if (outside(a,b))
		return;
	if (bad[a][b])
		return ;
	int nd=QD+1-(have[a][b]>0);
	if (dist[a][b]<=nd)
		return;
	
	dist[a][b]=nd;
	if (have[a][b])
		qu.push_front(make_pair(a,b));
	else
		qu.push_back(make_pair(a,b));
}
int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	
	for (int i=1;i<=n;i++)
	{
		cin>>st;
		for (int j=1;j<=m;j++)
		{
			if (st[j-1]=='#')
			{
				bad[i][j]=1;
				continue;
			}
			if (st[j-1]>='1'&&st[j-1]<='3')
				have[i][j]=st[j-1]-48;
		}
	}
	
	ans=1e9;
	
	for (int root=1;root<=3;root++)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				dist[i][j]=1e9;
		
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (have[i][j]==root)
				{
					dist[i][j]=0;
					qu.push_back(make_pair(i,j));
				}
		
		while (qu.size())
		{
			pair<int, int> temp=qu.front();
			qu.pop_front();
			int qx,qy;
			qx=temp.first;
			qy=temp.second;
			QD=dist[qx][qy];
//			cout<<qx<<"% "<<qy<<" "<<QD<<endl;
			tryy(qx-1,qy);
			tryy(qx+1,qy);
			tryy(qx,qy-1);
			tryy(qx,qy+1);
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				memo[root][i][j]=dist[i][j];
		//ans=min(ans,s);
	}
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			long long S=0;
			for (int q=1;q<=3;q++)
				S+=memo[q][i][j];
			
			if (have[i][j]==0)
				S-=2;
			
			if (S>1e9)
				continue;
			if (S<ans)
				ans=S;
		}
	if (ans>1e8)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
		
	return 0;
}