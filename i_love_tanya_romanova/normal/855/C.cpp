/*
Our generation sees the world
not the same as before
We might as well just throw it all
And live like there's no tomorrow
There's no tomorrow
We are the ones
Who are living under the gun every day
You might be gone before you know
So live like there's no tomorrow
Ain't gonna waste this life
There's no tomorrow - you ain't gonna live it for me
Believe it
The official view of the world has changed
In a whole new way
Live fast cause if you don't take it
You'll never make it
So if you understand me
And if you feel the same
Then you will know what nitro means
You'll live like there's no tomorrow - you ain't gonna waste this life
There's no tomorrow - you ain't gonna live it for me
There's no tomorrow
*/

//#pragma GCC optimize("O3")
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

const int N = 100031;

int n,m,k,x;
vector<int> g[N];
long long dp[N][13][2][2];
long long knap[N][13][2][2];

int used[N];

long long add(long long a,long long b){
	return (a+b)%bs;
}

void solve(int v){
	used[v]=1;
	vector<int> sons;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		sons.push_back(to);
		solve(to);
	}

	for (int i=0;i<=sons.size();i++)
	{
		for (int j=0;j<=10;j++)
		{
			for (int q=0;q<=1;q++)
			{
				for (int e=0;e<=1;e++){
				knap[i][j][q][e]=0;}
			}
		}
	}

	knap[0][0][0][0]=1;
	knap[0][0][0][1]=1;

	//cout<<"@"<<endl;

	//cout<<v<<" "<<sons.size()<<"!"<<endl;

	for (int i=0;i<sons.size();i++)
	{
		int to=sons[i];
		for (int have_already=0;have_already<=1;have_already++)
		{
			for (int have_there=0;have_there<=1;have_there++){
				for (int cnt_there=0;cnt_there<=10;cnt_there++){
					for (int my_cnt=0;my_cnt+cnt_there<=10;my_cnt++){
						for (int will_have_above=0;will_have_above<=1;will_have_above++){
						knap[i+1][cnt_there+my_cnt][have_already|have_there][will_have_above]=(
								knap[i+1][cnt_there+my_cnt][have_already|have_there][will_have_above]
								+1ll*knap[i][my_cnt][have_already][will_have_above]*dp[to][cnt_there][have_there][will_have_above])%bs;
					}
				}
			}
		}
	}
	}

		//cout<<"@"<<endl;

	//cout<<v<<" "<<sons.size()<<endl;

	//cout<<v<<" "<<knap[sons.size()][0][0][1]<<endl;

	for (int i=0;i<=10;i++)
	{
		for (int j=0;j<=1;j++)
		{
				if (j==0) // pick any
				{
					dp[v][i][0][1]=add(dp[v][i][0][1],knap[sons.size()][i][j][0]*(k-1)%bs);
					dp[v][i][0][0]=add(dp[v][i][0][0],knap[sons.size()][i][j][0]*(m-1)%bs);
					dp[v][i+1][1][0]=add(dp[v][i+1][1][0],knap[sons.size()][i][j][1]);
				}
				else // pick normal < k
				{
					dp[v][i][0][0]=add(dp[v][i][0][0],knap[sons.size()][i][j][0]*(k-1)%bs);
					dp[v][i][0][1]=add(dp[v][i][0][1],knap[sons.size()][i][j][0]*(k-1)%bs);
				}
			}
		}

	//cout<<dp[v][1][1]<<" "<<dp[v][0][0]<<endl;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cin>>k>>x;

	solve(1);

	long long ans=0;

	for (int i=0;i<=x;i++)
	{
		for (int j=0;j<=1;j++)
		{
			//cout<<i<<" "<<j<<" "<<dp[1][i][j]<<endl;
			ans=add(ans,dp[1][i][j][0]);
		}
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}