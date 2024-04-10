/*
We've been out in the cold
Trying to get in
We've been ripped off and rolled
Heads in a spin
Nothin can stop us breakin' through
Finding my way back home to you
Standing alone in the fight
You've never been out of our sight

We're back on the streets again
We're back on our feet again
We're out of the night
Into the light
We're back on the streets again

We're back, we're back on the streets again
We're back, we're back on our feet again

We were caught in the crossfire
But no one could win
They bled off the power
Our spirit within
Standing our ground
We're digging in
This time 'round
We're gonna win
The banners are flying high
We're reaching for the sky

We're back on the streets again
We're back on our feet again
We're out of the night
Into the light
We're back on the streets again

We're back, we're back on the streets again
We're back, we're back on our feet again

We're back on the streets again, whooo
We're back, we're back on the streets again, yeah
We're back, we're finding our feet again

We're back, we're back on the streets again
We're back on the streets again
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

using namespace std;

int n,ar[1<<20];
int stable[1<<20],ans;
int cnt;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	
	stable[1]=1;
	stable[n]=1;
	
	for (int i=2;i<=n;i++)
		if (ar[i]==ar[i-1])
			stable[i]=stable[i-1]=1;
	
	for (int i=n-1;i;--i)
		if (ar[i]==ar[i+1])
			stable[i]=stable[i+1]=1;
	/*
	for (int i=1;i<=n;i++)
		cout<<stable[i]<<" ";
	cout<<endl;
	*/
	for (int i=1;i<=n;i++)
	{
		if (stable[i]==0)
		{
			++cnt;
		}
		else
		{
			int moves=(cnt+1)/2;
			ans=max(ans,moves);
			if (ar[i-cnt-1]==ar[i])
			{
				for (int j=i-cnt;j<i;j++)
					ar[j]=ar[i];
			}
			else
			{
				for (int j=i-cnt;j<i;j++)
				{
					int d1,d2;
					d1=j-(i-cnt-1);
					d2=i-j;
					if (d1<d2)
						ar[j]=ar[i-cnt-1];
					else
						ar[j]=ar[i];
				}
			}
			cnt=0;
		}
	}
	
	cout<<ans<<endl;
	for (int i=1;i<=n;i++)
	{
		if (i>1)
			cout<<" ";
		cout<<ar[i];
	}
	cout<<endl;
	
	return 0;
}