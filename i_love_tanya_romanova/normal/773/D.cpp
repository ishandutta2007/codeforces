/*
Welcome to our fortress tall
I'll take some time to show you around
Impossible to break these walls
For you see the steel is much too strong
Computer banks to rule the world
Instruments to sight the stars

Possibly I've seen too much
Hangar 18 I know too much.

Foreign life forms inventory
Suspended State of cryogenics
Selective amnesia's the story
Believed foretold but who'd suspect
The military intelligence
Two words combined that can't make sense

Possibly I've seen too much
Hangar 18 I know too much.
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
const int N = 2031;

int n,val;
int ar[N][N];

int mn;
int used[N];
long long D[N];
int smallest_edge[N];

vector<pair<int,pair<int,int> > > edges;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	mn=1e9;


	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		smallest_edge[i]=1e9;
	}
	for (int i=1;i<=n;i++)
	{
		ar[i][i]=1e9;
		for (int j=i+1;j<=n;j++)
		{
			scanf("%d",&val);
			ar[i][j]=ar[j][i]=val;
			mn=min(mn,val);
		}
	}

	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			ar[i][j]-=mn;
			smallest_edge[i]=min(smallest_edge[i],ar[i][j]);
			smallest_edge[j]=min(smallest_edge[j],ar[i][j]);
		}
	}

	for (int i=1;i<=n;i++)
	{
		D[i]=1e18;
	}

	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (ar[i][j]==0)
				D[i]=D[j]=0;
		}
	}

	for (int iter=1;iter<=n;iter++)
	{
		long long mval=1e18;
		int mp;

		for (int i=1;i<=n;i++)
		{
			if (used[i])
				continue;
			if (D[i]<mval)
			{
				mval=D[i];
				mp=i;
			}
		}
		used[mp]=1;
		for (int i=1;i<=n;i++)
		{
			if (used[i])
				continue;
			//cout<<i<<" "<<mp<<" "<<smallest_edge[i]<<endl;
			D[i]=min(D[i],D[mp]+ar[mp][i]);
			D[i]=min(D[i],D[mp]+2*smallest_edge[i]);
		}
	}

	for (int i=1;i<=n;i++)
	{
		cout<<D[i]+mn*1ll*(n-1)<<endl;
	}

	cin.get(); cin.get();
	return 0;
}