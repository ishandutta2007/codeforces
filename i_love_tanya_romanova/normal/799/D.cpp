/*
I've begun to realize
That whenever I am with you
You deliver me from the pain in my life
Easy now to recognize
All the misery I have been through
It was beating me to submission
'Til the day you arrived
Certainly, I felt alive
Strength I had lost was revived
I'm mending inside and we both know why
'Cause you're mine
I knew I could be whole if you were mine
I'll vanquish any foe because you're mine

Been betrayed too many times
Didn't think I would ever recover
That it'd haunt me for the rest of my life
Then you opened up my eyes
And you helped me rediscover
With what you resurrected
A man who had died
Your power regave me new life
Made me reborn and refined
Rebuilt from inside and we both know why
'Cause you're mine
I knew I could be whole if you were mine
I'll vanquish any foe because you're mine

I never thought I would ever escape
At times, I wanted to die
Feared that it all was just a little too late
For then, I wouldn't survive
I let you in and let go of the hate
My heart recovered now, I
Owe you a debt that I can never repay
I still believe 'cause you're mine

I'm burning inside and we both know why
'Cause you're mine
I knew I could be whole if you were mine
I'll vanquish any foe because you're mine
I can regain control because you're mine
I can take over the world because you're mine
Mine
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
const int N = 300031;

int a,b,h,w,n;
vector<int> v;
long long dp[N],new_dp[N];

bool ok()
{
	for (int i=0;i<=100000;i++)
	{
		if (i>=a&&dp[i]>=b)
			return true;
		if (i>=b&&dp[i]>=a)
			return true;
	}
	return false;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>a>>b>>h>>w>>n;

	for (int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		v.push_back(val);
	}

	sort(v.begin(),v.end());

	reverse(v.begin(),v.end());

	while (v.size()>100)
		v.pop_back();

	int ans=-1;

	for (int i=0;i<=100000;i++)
	{
		dp[i]=-1;
	}

	dp[h]=w;

	for (int i=0;i<v.size();i++){

		if (ok())
		{
			ans=i;
			break;
		}

		for (int j=0;j<=100000;j++)
		{
			new_dp[j]=dp[j];
		}

		for (int j=0;j<=100000;j++)
		{
			if (dp[j]<0)
				continue;
			long long new_v1=1ll*j*v[i];
			if (new_v1>100000)
				new_v1=100000;
			new_dp[new_v1]=max(new_dp[new_v1],dp[j]);
			long long new_v2=1ll*dp[j]*v[i];
			if (new_v2>100000)
				new_v2=100000;
			new_dp[j]=max(new_dp[j],new_v2);
		}
		for (int j=0;j<=100000;j++)
		{
			dp[j]=new_dp[j];
		}
	}

	if (ok()==1&&ans==-1)
		ans=v.size();

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}