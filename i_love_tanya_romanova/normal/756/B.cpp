/*
Do you see the world in different colors?
Do you see the world in black and gray?
Alone in your thoughts
How many others have stood where you stand
Where you stand today?
I've stood where you stand
But all, can you...

Wait for me now?
Take off this crown
To break all these vows
Don't you know?
Wait for me now
The airs running out
Wait for me, wait for me
Wait for me, wait for me now

The promise of safe return undelivered
The ocean is wider than I first guessed
When roads disappeared, I followed the rivers
But somehow got in over my head
So deep I felt taken

Wait for me now
Take off this crown
To break all these vows
Don't you know?
Wait for me now
The airs running out
Wait for me, wait for me
Wait for me, wait for me now

A lost dream of what could have been
A house on fire, a tangled web
The key turns to find the locks have changed
In time to hear the back door slam
A sound that to this day I can't forget
The colors drained to black and gray
Oh...

Wait for me now
Take off this crown
To break all these vows
Don't you know?
Wait for me now
The airs running out
Wait for me, wait for me
Wait for me, wait for me now
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

int  n,ar[N],dp[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
	}

	dp[0]=0;
	for (int i=1;i<=n;i++)
	{
		dp[i]=1e9;
		// buy 1
		dp[i]=min(dp[i],dp[i-1]+20);

		// 90 minutes
		int thold=ar[i-1]-90;
		int first_good=upper_bound(ar,ar+n,thold)-ar;
		dp[i]=min(dp[i],dp[first_good]+50);

		thold=ar[i-1]-1440;
		first_good=upper_bound(ar,ar+n,thold)-ar;
		dp[i]=min(dp[i],dp[first_good]+120);
	}

	for (int i=1;i<=n;i++)
	{
		cout<<dp[i]-dp[i-1]<<"\n";
	}

	cin.get(); cin.get();
	return 0;
}