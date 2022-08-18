/*
Wishing never got us what we needed
So we waited for our salvation to arrive
Then it took everything that we loved
And it let us alive

I hear you call
And I promise to you
One day, some day
The pain will go

Solitary movement meant for two
Can you hear the loneliness in silent cries
If you take everyting that I love
Leave me to die

I hear you call
And I promise to you
One day, some day
The pain will go

If you take everything that I love
And you leave here
Leave me alive
If you take everything thet I love
And I'm standing here
Waiting to die

I hear you call
And I promise to you
One day, some day
The pain will go
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
#define bsize 2
#define N 300505

using namespace std;

vector<pair<int, int> > xs,ys;
int X[N];
int Y[N];
int n,k;
long long ans;
int tx1,ty1,tx2,ty2;
int cnt;
int used[N];

bool bad(int id)
{
	return (X[id]<tx1||X[id]>tx2||Y[id]<ty1||Y[id]>ty2);
}

void remove_point(int id)
{
	if (used[id]==0)
		return;
	--cnt;
	used[id]=0;
}

void add_point(int id)
{
	if (used[id])
		return;
	used[id]=1;
	cnt++;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		X[i]=(1ll*a+1ll*c);
		Y[i]=(1ll*b+1ll*d);
		xs.push_back(make_pair(X[i],i));
		ys.push_back(make_pair(Y[i],i));
	}
	
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	
	ans=8e18;
	
	for (int cut_left=0;cut_left<=k&&cut_left<n;cut_left++)
		for (int cut_right=0;cut_right<=k&&cut_right<n;cut_right++)
			for (int cut_up=0;cut_up<=k&&cut_right<n;cut_up++)
				for (int cut_down=0;cut_down<=k&&cut_down<n;cut_down++)
				{
					tx1=xs[cut_left].first;
					tx2=xs[n-cut_right-1].first;
					ty1=ys[cut_down].first;
					ty2=ys[n-cut_up-1].first;
					if (tx1>tx2)
						continue;
					if (ty1>ty2)
						continue;
					cnt=0;
					for (int i=0;i<n&&i<20;i++)
					{
						if (bad(xs[i].second))
							add_point(xs[i].second);
						if (bad(ys[i].second))
							add_point(ys[i].second);
					}
					for (int i=n-1;i>=0&&i>=n-20;i--)
					{
						if (bad(xs[i].second))
							add_point(xs[i].second);
						if (bad(ys[i].second))
							add_point(ys[i].second);
					}
					int mcnt=cnt;
					//cout<<tx1<<" "<<ty1<<" "<<tx2<<" "<<ty2<<" "<<cnt<<" "<<k<<endl;
					
					for (int i=0;i<n&&i<20;i++)
					{
						remove_point(xs[i].second);
						remove_point(ys[i].second);
					}
					for (int i=n-1;i>=0&&i>=n-20;i--)
					{
						remove_point(xs[i].second);
						remove_point(ys[i].second);
					}
					
					if (mcnt>k)
						continue;
					int dx=ty2-ty1;
					int dy=tx2-tx1;
					if (dx==0)
						++dx;
					if (dy==0)
						++dy;
					if(dx%2)dx++;
					if(dy%2)dy++;
					ans=min(ans,1ll*dx*dy);
				}
	
	cout<<ans/4<<endl;			
	return 0;
}