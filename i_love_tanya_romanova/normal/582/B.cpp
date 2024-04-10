/*
Say a little prayer
For everybody else
From your own private hell

I know about your hurt
and I know about your past
Why you almost never laugh

We're all getting something from someone
What about you
What about you?

If I was God for a day
I would take it all away
Give you all my power
For 24 good hours
Lift you up above the storm
Let your wings mend
I would make it all okay
If I was God for a day

So you take a little pill to suffocate the pain
Are you still breathing?
Would anybody know, would anybody care
If one day you just weren't there?

We're all getting something from someone
What about you
What about you?

If I was God for a day
I would take it all away
Give you all my power
For 24 good hours
Lift you up above the storm
Let your wings mend
I would make it all okay

I see through all of your silence
I hear everything, everything you do
Not alone in this moment
I'm here with you

If I was God for a day
I would take it all away
Give you all my power

If I was God for a day
I would take it all away
Give you all my power
For 24 good hours
Lift you up above the storm
Let your wings mend
I would make it all okay

If I was God for a day
I would make it all ok

If I was God for a day
I would make it all ok

If I was God for a day
For a day
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
#define move adsfasfsdf

using namespace std;

int n,t,CNT[1<<20],trash,ar[1<<20];
int dp[1<<10][1<<10],DP[1<<10][1<<10];
int ans,tans,move[1<<10][1<<10];

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>t;
for (int i=1;i<=n;i++)
{
	cin>>ar[i];
	CNT[ar[i]]++;
	trash=max(trash,CNT[ar[i]]);
}


for (int bound=1;bound<=300;bound++)
{
	for (int j=0;j<=n;j++)
		for (int q=0;q<=300;q++)
			dp[j][q]=-1e9;
	
	dp[0][bound]=0;
	for (int i=1;i<=n;i++)
	{
		for (int mx=1;mx<=300;mx++)
		{
			dp[i][mx]=max(dp[i][mx],dp[i-1][mx]);
			dp[i][mx]=max(dp[i][mx],dp[i][mx-1]);
			if (ar[i]>=mx)
				dp[i][ar[i]]=max(dp[i][ar[i]],dp[i-1][mx]+1);
		}
	}
	
	for (int j=1;j<=300;j++)
		move[bound][j]=dp[n][j];
}

for (int i=0;i<=300;i++)
	for (int j=0;j<=300;j++)
		DP[i][j]=-1e9;


//cout<<move[1][2]<<" "<<move[2][4]<<endl;

DP[0][1]=0;
for (int i=0;i<=300;i++)
	for (int cur_mx=1;cur_mx<=300;cur_mx++)
		for (int new_mx=cur_mx+1;new_mx<=300;new_mx++)
		{
			DP[i+1][new_mx]=max(DP[i+1][new_mx],DP[i][cur_mx]+move[cur_mx][new_mx]);
		}

for (int i=0;i<=300&&i<=t;i++)
	for (int j=1;j<=300;j++)
	{
		int rem_blocks=t-i;
		int tans=rem_blocks*trash+DP[i][j];
		ans=max(ans,tans);
	}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}