/*
Existing on damnation's edge
The priest had never known
To witness such a violent show
Of power overthrown

Angels fighting aimlessly
Still dying by the sword
Our legions killing all in sight
To get the one called Lord

The Gates of Hell lie waiting as you see
There's no price to pay just follow me
I can take your lost soul from the grave
Jesus knows your soul can not be saved

Crucify the so called Lord
He soon shall fall to me
Your souls are damned your God has fell
To slave for me eternally
Hell awaits

The Reaper guard's the darkened Gates
That Satan calls his home
Demons feed the furnace where
The Dead are free to roam

Lonely children of the night
There's seven ways to go
Each leading to the burning hole
The Lucifer controls

Priests of Hades seek the sacred star
Satan sees the answer lies not far
Zombies screaming souls cry out to you
Satanic laws prevail your life is through

Pray to the moon, when it is round
Death with you shall then abound
What you seek, for can't be found
In sea or sky or underground

Now I have you deep inside my everlasting grasp
The seven bloody Gates of Hell
Is where you'll live your last

Warriors from Hell's Domain
Will bring you to your Death
The flames of Hades burning strong
Your soul shall never rest

The Gates of Hell lie waiting as you see
There's no price to pay just follow me
I can take your lost soul from the grave
Jesus knows your soul can not be saved

Sacrifice the lives of all I know they
Soon shall die
Their souls are damned to rot in Hell
and keep the fire growing deep inside
Hell awaits
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,k,m;
int cost[100][100];
int dp[100][100][100][3];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;
	cin>>m;
	for (int i=0;i<=n+1;i++)
	{
		for (int j=0;j<=n+1;j++)
		{
			cost[i][j]=1e9;
		}
	}

	for (int l=0;l<=n+1;l++)
	{
		for (int r=0;r<=n+1;r++)
		{
			for (int cnt=0;cnt<=k;cnt++)
			{
				for (int which=0;which<=1;which++)
				{
					dp[l][r][cnt][which]=1e9;
				}
			}
		}
	}

	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cost[a][b]=min(cost[a][b],c);
	}

	for (int i=1;i<=n;i++)
	{
		dp[i][n+1][0][0]=0;
		dp[0][i][0][1]=0;
	}

	for (int iter=0;iter<k;iter++)
	{
		for (int l=0;l<=n+1;l++)
		{
			for (int r=l;r<=n+1;r++)
			{
				for (int which=0;which<=1;which++)
				{
					if (dp[l][r][iter][which]>1e8)
						continue;

					for (int next_pt=l+1;next_pt<r;next_pt++)
					{
						int here=dp[l][r][iter][which];
						if (which==0)
							here+=cost[l][next_pt];
						else
							here+=cost[r][next_pt];

						dp[l][next_pt][iter+1][1]=min(dp[l][next_pt][iter+1][1],here);
						dp[next_pt][r][iter+1][0]=min(dp[next_pt][r][iter+1][0],here);
					}
				}
			}
		}
	}

	int ans=1e9;
	for (int i=0;i<=n+1;i++)
	{
		for (int j=i;j<=n+1;j++)
		{
			ans=min(ans,dp[i][j][k-1][0]);
			ans=min(ans,dp[i][j][k-1][1]);
		}
	}

	if (ans>1e7)
		ans=-1;
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}