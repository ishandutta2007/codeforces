/*
Tonight I'm nothing
It doesn't matter where I've been
Delay of reaction is
The unseen movie of this life

I remember one of my friends
Telling me to go ahead

Water on every side
There's a dead spot in my eye
If I listen close at night
There's something coming my way

Like someone called my name
But I didn't care to look that way
I just fixed my eyes into the crowd
It would have been strange to turn around

If you would tell me that I was someone
Then for a second I would think
Just like I would try to consider
How it would feel to know

I have to get on with this
It's a decision for tonight
Out to look for chances
It is murder of my mind

Once I was someone new
I was chosen for a while
Then with time I am changing
At least that is what they say

What is worth with being here
I pray so often for a change
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000009

#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 4051;

int n,k,ar[N][N];
int S_row[N][N],S_col[N][N];
int COST[N][N];
int DP[900][N],cut[900][N];
char buf[200000];

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;

	string st;
	getline(cin,st);

	for (int i=0;i<n;i++)
	{
		fgets(buf,n*3,stdin);
		for (int j=0;j<n;j++)
		{
			ar[i][j]=buf[j*2]-48;
//			scanf("%d",&ar[i][j]);
			//cin>>ar[i][j];
		}
	}

//	if (n==4000)
//		return 1;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (j)
				S_row[i][j]=S_row[i][j-1];
			if (i)
				S_col[i][j]=S_col[i-1][j];
			S_row[i][j]+=ar[i][j];
			S_col[i][j]+=ar[i][j];
		}
	}

	for (int start=0;start<n;start++)
	{
		int cur=0;

		for (int r=start;r<n;r++)
		{
			cur+=S_row[r][r];
			if (start>0)
				cur-=S_row[r][start-1];
			COST[start][r]=cur;
			COST[r][start]=cur;
		//	cout<<COST[start][r]<<" ";
		}
//		cout<<endl;
	}

	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=k;j++)
		{
			DP[j][i]=1e9;
		}
	}

	for (int i=0;i<n;i++)
	{
		DP[1][i]=COST[0][i];
	}


	for (int j=2;j<=k;j++)
	{
		for (int i=n-1;i>0;--i)
		{
			int l=cut[j-1][i];
			int r=i;
			if (i!=n-1)
				r=min(r,cut[j][i+1]);
			DP[j][i]=1e9;
			for (int q=l;q<=r;q++)
			{
				int here=COST[i][q];
				if (q>0)
					here+=DP[j-1][q-1];
				if (here<DP[j][i])
				{
					DP[j][i]=here;
					cut[j][i]=q;
				}
			}
		}
	}

	cout<<DP[k][n-1]<<endl;

	cin.get(); cin.get();
	return 0;
}